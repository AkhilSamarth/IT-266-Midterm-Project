# Quake Life 3 #
## Half Life inspired Quake 4 Mod for IT 266, by Akhil Samarth ##

## Description: 
This mod adds several features inspired by the Half Life series, as well as a few additional things. The instructions on how to test this mod as well as a full list of changes can be found below.

## Instructions:

Main Instructions

- Click "Start game" in the main menu to load into the map

- Weapons and ammo will be there by default (see "Changes" below for more details on each weapon)

- Weapons upgrades: all weapons can be upgraded at once using command "upgradeWeapons"
-- NOTE: weapons cannot be downgraded, so don't run this command until you are done with the default weapons
-- See upgrade notes under weapon changes for more details on the specifics of each upgraded weapon

- Power ups: spawn each power up item using the command "spawn item_powerup_{name}"
-- {name} is one of "jump", "haste", "strength", "shield", or "ammo"
-- Walk over power up to gain its effect (only one can be picked up at a time)
-- See "Changes" below for more details

- Creatures: spawn Alien Grunt using command "spawn monster_gunner"

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

- Machine gun (same):
-- Removed zooming
-- Added grenade launching as alt attack (hold right click before firing to use)
-- Upgrades to have faster grenade launching

- Shotgun (same):
-- Default weapon is the same as vanilla Quake 4
-- Upgrades to have higher spread but many more bullets (50 instead of 10)

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
-- Replaced projectile firing with hitscan
-- Tweaked clip size, fire rate, etc.
-- Upgrades to have faster fire rate

- Lightning gun (gluon gun)
-- Shortened range
-- Upgrades to have increased range and lower ammo consumption

#### Power ups:

- All power ups are in the form of items that can be picked up.

- Jump boost
-- Allows player to jump significantly higher

- Haste
-- Increases the player's speed

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

- Changed menu GUIs

- Added gui (objective) that shows to indicate weapons have been upgraded

- Changed weapon names UI
