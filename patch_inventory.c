#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    const int offsets[] = {
        0x1BB0, // AMMO CROSSBOW
        0x2B20, // MOLOTOV
        0x79F0, // SMOKE BOMB
        0x7B90, // STUN BOMB
        0x5F20, // HEALTHKIT
        0x3000, // AMMO ARROW
        0x7E00, // PIPE BOMB
        0x2A50, // SILENCER
        0x1870, // TRAP BOMB
        0x3C30, // AMMO EXPLOSIVE ARROW
        0x3EA0, // AMMO REVOLVER JOEL
        0x7C60, // SHIV
        0x4EE0, // AMMO REVOLVER
        0x7780, // AMMO PISTOL
        0x11F0, // AMMO FLAMETHROWER
        0x4110, // AMMO RIFLE VEPR
        0x53C0, // AMMO RIFLE
        0x1390, // AMMO RIFLE MPX5
        0x3A90, // AMMO SHOTGUN
        0x6DC0, // AMMO SHOTGUN DRAGONS BREATH
        0x3D00, // AMMO SHOTGUN ABBY
        0x27E0, // AMMO HUNTING PISTOL
    };
    int custom_limits[sizeof(offsets) / sizeof(int)];
    const int ITEM_SIZE = sizeof(offsets) / sizeof(int);
    FILE *bin_file, *custom_limits_file;

    bin_file = fopen("more_items/bin/dc1/player-inventory.bin", "r+b");
    if (bin_file == NULL)
    {
        printf("Couldn't open file \"more_items/bin/dc1/player-inventory.bin\".");
        getchar();
        return 1;
    }

    custom_limits_file = fopen("custom_limits.txt", "r");
    if (custom_limits_file == NULL)
    {
        printf("Couldn't open file custom_limits.txt.\n");
        getchar();
        return 1;
    }
    struct stat buffer;
    if (stat(".\\ndarc.exe", &buffer) != 0)
    {
        printf("ndarc.exe wasn't found in this folder.\n");
        getchar();
        return 1;
    }
    char line_buffer[32];
    int old_value, new_value;
    for (int i = 0; i < ITEM_SIZE; ++i)
    {
        if (fscanf(custom_limits_file, "%[^=]=%d\n", line_buffer, custom_limits + i) != 2)
        {
            printf("Error reading line %i the custom_limits.txt file.\n", i);
            getchar();
            return 1;
        }
        fseek(bin_file, offsets[i], SEEK_SET);
        fread(&old_value, sizeof(int), 1, bin_file);
        fseek(bin_file, offsets[i], SEEK_SET);
        fwrite(custom_limits + i, sizeof(int), 1, bin_file);
        if (custom_limits[i] != old_value) {
            printf("Updated limit for '%s': from %d -> %d\n", line_buffer, old_value, custom_limits[i]);
        } else {
            printf("No new limit for '%s' (%d)\n", line_buffer, old_value);
        }
    }

    fclose(bin_file);
    fclose(custom_limits_file);

    char output_name[64];
    char command[128];
    printf("Creating the new archive ...\n");
    system(".\\ndarc.exe -c .\\more_items -o .\\inventory_limits.psarc > NUL");

    printf("New archive created successfully. You can now copy it into your mods folder. Press any button to quit.\n");
    getchar();

    return 0;
}