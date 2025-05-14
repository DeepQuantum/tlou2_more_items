This mod gives the player more space for items (such as Molotovs,Shivs, Traps, Medkits, etc.) and more reserve ammo capacity for all weapons.

NOTE: Having more silencers is does not work right now. I'll try to fix it in a future version.

======== INSTALLATION ========

IMPORTANT: If you're using my (or any) other mod that edits the player-inventory.bin file, please follow the steps below to resolve conflicts.

If you're not using any other mods that edit the players inventory, you can simply place the included "more_items.psarc" file in
your mods folder.

This mod requires the ndmodloader (https://www.nexusmods.com/thelastofuspart2/mods/32).


======== MOD CONFLICTS ========

[My previous mod](https://www.nexusmods.com/thelastofuspart2/mods/215) needs to modify the same file as this one. Placing both
.psarc files in the mod folder won't work. Instead, follow these steps:

    * Download [ndarc](https://www.nexusmods.com/thelastofuspart2/mods/31) and place its executable in this mods directory
    * Go to the other mods folder and located the "more_resources" directory
    * Follow that directory and copy the "player-inventory.bin" file
    * Go back to this mods' folder and into its "more_items/bin/dc1" directory
    * Replace this "player-inventory.bin" file with the one you just copied from the other mod
    * Run the included "patch_inventory.exe" program
    * Place the newly created .psarc file in your mods folder


You can copy the "player_inventory.bin" file inside the "original" directory to the "bin/dc1" directory to reset the limits.

During this process you can also define custom limits for each item, as detailed in the section below.

======== CUSTOM LIMITS ========

This section is optional if you wish to define custom limits for all resources. By default, this mod
doubles the normal capacities.

Alternatively, the file "custom_limits.txt" defines the max amount for each item/type of ammo.
You can change the number after the "=" to any integer (whole number) starting at 1. Do not change the order of the items.

After changing the limits, you need to place "ndarc.exe" in the same directory
as this file. You can then run the "patch_inventory.exe" program. This will create a new ".psarc" file.
Copy this file into your mods folder. Make sure to remove
any previous files associated with this mod, as they will otherwise conflict. 

======== CHANGELOG ========

* 1.2.0 | Added Hunting Pistol
* 1.1.0 | Added Abby's Shotgun
* 1.0.0 | Release