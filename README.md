## Half Life inspired Quake 4 Mod for IT 266, by Akhil Samarth

## Description: 
This mod adds several features inspired by the Half Life series, as well as a few additional things. The instructions on how to test this mod as well as a full list of changes can be found below.

## Instructions:

Main Instructions

 - Load test map using console command "map tools/mv2.map" (this map isn't required for the mod to work, but it makes testing easier)
 
 - Weapons: give player all the weapons using command "give all"
 -- See "weapon specifics" for more details on the specifics of each weapon

- Weapons upgrades: all weapons can be upgraded using command "upgradeWeapons"
-- NOTE: weapons cannot be downgraded, so don't run this command until you are done with the default weapons
-- See the "UPGRADE" notes under "weapon specifics" for more details on the specifics of each upgraded weapon

- Power ups: spawn each power up item using the command "spawn item_powerup_{name}"
-- {name} is one of "jump", "haste", "strength", "shield", or "ammo"
-- Walk over power up to gain its effect (only one can be picked up at a time)
-- See "power up specifics" for more details on each power up

- Creatures: spawn gunner using command "spawn monster_gunner"

Weapon specifics

- Blaster
-- Fire the weapon to see that it fires bullets instead of the original blaster particle. It also plays a bullet sound.
-- Hold left click to see that the charged attack has been removed.
-- UPGRADE: the firing rate is considerably higher and you can fire much faster now.

- Machine gun
-- TODO

- Shotgun
-- TODO

- Hyperblaster
-- Fire to see that the the original hyperblaster particles have been replaced with those of the rail gun.
-- Fire at a creature to see that the damage is much lower than that of the default railgun.
-- UPGRADE:

- Nailgun
-- Fire to see that that ammo now regenerates (up to the default clip size of 8)
-- UPGRADE: fire to see that the fire rate is much higher, as is the ammo regeneration rate

- Railgun
-- Hold right click to see the slowed-down zoom animation and no-overlay zoom, similar to the HL crossbow.
-- Fire to see that the original hitscan has been replaced with a high-damage crossbow bolt projectile.
-- Fire at a creature to see that the very high damage done by a single bolt.
-- UPGRADE: fire to see a higher reload rate

- Lightning
-- Hold the fire button, aimed at the floor, starting aimed close to you and then moving further away, to see the weapon's much more restricted range.
-- UPGRADE: repeat above, but this time, the range will be higher and the ammo consumption will be much lower

- Dark matter
-- Spawn in an item using the command "spawn item_{name}", e.g. "item_health_large"
-- Click on the item and move the mouse around to see that the item has been picked up
-- Left click while holding item to throw it
-- Right click while holding item to release it without throwing it
-- UPGRADE: the gun can now pick up monsters in addition to items. Spawn a monster in using "spawn monster_{name}", e.g. "monster_grunt". It can now be picked up and thrown like an item.
-- Power is increased with upgrade, so the item from before should go further when thrown.

Power up specifics

- Jump boost
-- Jump to see that the jump height is higher than default

- Haste
-- Fire a weapon (I suggest the machine gun) to see that its fire rate has been increased
-- Run around to see that the player can now run faster (note: this speed difference isn't very large and may be hard to notice)

- Strength
-- Spawn in a monster using command "spawn monster_{name}", e.g. "monster_grunt"
-- Fire a weapon at it before picking up the power up, keeping track of roughly how many shots it took to kill it
-- Fire the same weapon at the same monster, this time with the power up, to see that only around 1/4 as many shots are needed to kill

- Shield
-- Note, have the shield power up spawned and ready to be picked up prior to proceeding
-- Spawn in a monster using command "spawn monster_{name}", e.g. "monster_grunt"
-- Allow it to hit you and note approximately how much damage it does
-- Consume power up and let the monster hit you to see that it should now be doing much less damage

- Ammo
-- Fire a weapon with this power up to see that no ammo is consumed

## Changes:

#### Weapons:

- Original Quake weapon (Half Life inspired equivalent)

- Dark matter gun (gravity gun)
-- Removed all original DMG functionality
-- Added ability to pick up items and throw/release them (left click and right click respectively)
-- Upgrades to be able to pick up monsters and increases throwing power

- Blaster (pistol):
-- Shoots bullets instead of the default blaster particle, including bullet noise
-- Removed charged attack
-- Upgrades to have much faster firing rate

- Railgun (crossbow)
-- Removed zoom overlay, similar to the crossbow from HL
-- Changed hitscan to projectile
-- Tweaked firing rate, reload time, etc.
-- Upgrades to have faster reload times

- Nailgun (hive hand)
-- Removed reloading
-- Ammo now regenerates automatically over time, similar to hive hand from HL
-- Tweaked clip size, fire rate, etc.
-- Upgrades to have much faster fire rate and ammo regen

- Hyperblaster (tau cannon)
-- Changed hitscan to that of railgun, since it looks more similar to the tau cannon from HL
-- Tweaked clip size, fire rate, etc.

- Lightning gun (gluon gun)
-- Shortened range
-- Upgrades to have increased range and lower ammo consumption

#### Power ups:

- All power ups are in the form of items that can be picked up.

- Jump boost
-- Allows player to jump significantly higher

- Haste
-- Uses the in-game haste power up
-- Increases the player's speed
-- Increases the player's firing rate

- Strength
-- Utilizes the in-game quad damage power up
-- Allows the player to deal 4x damage

- Shield
-- Player takes significantly less damage

- Ammo
-- The player will not consume ammo while this power up is active

#### Creatures

- Original Quake name (Half Life inspired equivalent)

- Gunner (Alien grunt)
-- Removed ability to use melee attack
-- Removed ability to throw grenades
-- Only allow this creature to use the nail gun (similar to the alien grunts from HL, which use the hive hand)

#### Misc

- Added console command to upgrade all weapons at once ("upgradeWeapons") 

- Removed napalm gun, rocket launcher, and grenade launcher
