======== INSTALLATION ========

IMPORTANT: If you're using my (or any) other mod that edits the player-inventory.bin file, please fllow the steps below to resolve conflicts.

This mod requires the ndmodloader (https://www.nexusmods.com/thelastofuspart2/mods/32).

If you're not using any other mods that edit the players inventory, you can simply place the included "more_items.psarc" file in your mods folder.

======== MOD CONFLICTS ========

[My previous mod](https://www.nexusmods.com/thelastofuspart2/mods/215) needs to modify the same file as this one. Placing both
.psarc files in the mod folder won't work. Instead, take the .psarc file that you're using from the last mod (either the one that comes with it
or a custom one you created yourself) and place it inside "more_items\bin\dc1\". Windows will ask you if you want to replace the file, click 'yes'.
After that, use the included 'patch_inventory.exe' program. This will require [ndarc](https://www.nexusmods.com/thelastofuspart2/mods/31) to be placed in the same directory as this program.
This will then create a new .psarc that will have all the modified values for both mods. You can then place this .psarc file 
in your mods folder, making sure to remove any previous versions of either mod.

You can copy the "player_inventory.bin" file inside the "original" directory to the "bin/dc1" directory to reset the limits.

During this process you can also define custom limits for each item, as detailed in the section below.

======== CUSTOM RESOURCE LIMITS ========

This section is optional if you wish to define custom limits for all resources. By default, this mod
doubles the normal capacities.

Alternatively, the file "custom_limits.txt" defines the max amount for each item/type of ammo.
You can change the number after the "=" to any integer (whole number) starting at 1. Do not change the order of the items.

After changing the limits, you need to place "ndarc.exe" in the same directory
as this file. You can then run the "patch_inventory.exe" program. This will create a new ".psarc" file.
Copy this file into your mods folder. Make sure to remove
any previous files associated with this mod, as they will otherwise conflict. 

======== CHANGELOG ========

* 1.0.0 | Release