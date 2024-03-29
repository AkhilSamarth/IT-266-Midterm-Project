#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "../Game_local.h"
#include "../Weapon.h"

const idEventDef EV_Railgun_RestoreHum( "<railgunRestoreHum>", "" );

class rvWeaponRailgun : public rvWeapon {
public:

	CLASS_PROTOTYPE( rvWeaponRailgun );

	rvWeaponRailgun ( void );

	virtual void			Spawn				( void );
	virtual void			Think				( void );
	void					Save				( idSaveGame *savefile ) const;
	void					Restore				( idRestoreGame *savefile );
	void					PreSave				( void );
	void					PostSave			( void );
	void					ClientUnstale		( void );

	// upgrade weapon
	void upgrade();

protected:
	jointHandle_t			jointBatteryView;

private:

	stateResult_t		State_Idle		( const stateParms_t& parms );
	stateResult_t		State_Fire		( const stateParms_t& parms );
	stateResult_t		State_Reload	( const stateParms_t& parms );

	void				Event_RestoreHum	( void );
	
	int ammoReloadTimer = 0;				// timer for reloading
	int ammoReloadInterval = 2000;		// time in millis for ammo to reload

	// whether or not this nailgun is upgraded
	bool isUpgraded = false;

	CLASS_STATES_PROTOTYPE ( rvWeaponRailgun );
};

CLASS_DECLARATION( rvWeapon, rvWeaponRailgun )
	EVENT( EV_Railgun_RestoreHum,			rvWeaponRailgun::Event_RestoreHum )
END_CLASS

/*
================
rvWeaponRailgun::rvWeaponRailgun
================
*/
rvWeaponRailgun::rvWeaponRailgun ( void ) {
}

/*
================
rvWeaponRailgun::Spawn
================
*/
void rvWeaponRailgun::Spawn ( void ) {
	SetState ( "Raise", 0 );	

	// get rid of zoom gui
	zoomGui = NULL;

	// increase zoom time, normal = 0.1
	zoomTime = 0.4;

	// make gun not hitscan
	wfl.attackHitscan = false;
}

void rvWeaponRailgun::upgrade() {
	gameLocal.Printf("upgrades railgun");
	// quicker reload
	ammoReloadInterval = 1000;
}

/*
================
rvWeaponRailgun::Save
================
*/
void rvWeaponRailgun::Save ( idSaveGame *savefile ) const {
	savefile->WriteJoint( jointBatteryView );
}

/*
================
rvWeaponRailgun::Restore
================
*/
void rvWeaponRailgun::Restore ( idRestoreGame *savefile ) {
	savefile->ReadJoint( jointBatteryView );
}

/*
================
rvWeaponRailgun::PreSave
================
*/
void rvWeaponRailgun::PreSave ( void ) {

	//this should shoosh the humming but not the shooting sound.
	StopSound( SND_CHANNEL_BODY2, 0);
}

/*
================
rvWeaponRailgun::PostSave
================
*/
void rvWeaponRailgun::PostSave ( void ) {

	//restore the humming
	PostEventMS( &EV_Railgun_RestoreHum, 10);
}

/*
================
rvWeaponRailgun::Think
================
*/
void rvWeaponRailgun::Think ( void ) {

	// Let the real weapon think first
	rvWeapon::Think ( );

	// check if upgrade is needed
	if (!isUpgraded && gameLocal.GetLocalPlayer()->isRailgunUpgraded) {
		upgrade();
		isUpgraded = true;
	}

	// if clip is empty, deal with timers to fill it (provided player has ammo)
	if (AmmoInClip() == 0) {
		// if timer isn't started yet, start it
		if (ammoReloadTimer == 0) {
			ammoReloadTimer = gameLocal.time;
		}
		// if timer has started, check if the required interval has passed
		else if (gameLocal.time - ammoReloadTimer >= ammoReloadInterval) {
			// reload
			AddToClip(ClipSize());

			// reset timer
			ammoReloadTimer = 0;
		}
	}
}

/*
===============================================================================

	States 

===============================================================================
*/

CLASS_STATES_DECLARATION ( rvWeaponRailgun )
	STATE ( "Idle",				rvWeaponRailgun::State_Idle)
	STATE ( "Fire",				rvWeaponRailgun::State_Fire )
	STATE ( "Reload",			rvWeaponRailgun::State_Reload )
END_CLASS_STATES

/*
================
rvWeaponRailgun::State_Idle
================
*/
stateResult_t rvWeaponRailgun::State_Idle( const stateParms_t& parms ) {
	enum {
		STAGE_INIT,
		STAGE_WAIT,
	};	
	switch ( parms.stage ) {
		case STAGE_INIT:
			if ( !AmmoAvailable ( ) ) {
				SetStatus ( WP_OUTOFAMMO );
			} else {
				StopSound( SND_CHANNEL_BODY2, false );
				StartSound( "snd_idle_hum", SND_CHANNEL_BODY2, 0, false, NULL );
				SetStatus ( WP_READY );
			}
			PlayCycle( ANIMCHANNEL_ALL, "idle", parms.blendFrames );
			return SRESULT_STAGE ( STAGE_WAIT );
		
		case STAGE_WAIT:			
			if ( wsfl.lowerWeapon ) {
				StopSound( SND_CHANNEL_BODY2, false );
				SetState ( "Lower", 4 );
				return SRESULT_DONE;
			}		
			if ( gameLocal.time > nextAttackTime && wsfl.attack && AmmoInClip ( ) ) {
				SetState ( "Fire", 0 );
				return SRESULT_DONE;
			}  
			// no reloading, clip "reloaded" in code
			if ( AutoReload() && !AmmoInClip ( ) && AmmoAvailable () ) {
				//SetState ( "reload", 2 );
				//return SRESULT_DONE;
			}
			if ( wsfl.netReload || (wsfl.reload && AmmoInClip() < ClipSize() && AmmoAvailable()>AmmoInClip()) ) {
				//SetState ( "Reload", 4 );
				//return SRESULT_DONE;			
			}
			return SRESULT_WAIT;
	}
	return SRESULT_ERROR;
}

/*
================
rvWeaponRailgun::State_Fire
================
*/
stateResult_t rvWeaponRailgun::State_Fire ( const stateParms_t& parms ) {
	enum {
		STAGE_INIT,
		STAGE_WAIT,
	};	
	switch ( parms.stage ) {
		case STAGE_INIT:
			nextAttackTime = gameLocal.time + (fireRate * owner->PowerUpModifier ( PMOD_FIRERATE ));
			Attack ( false, 1, spread, 0, 1.0f );
			PlayAnim ( ANIMCHANNEL_ALL, "fire", 0 );	
			return SRESULT_STAGE ( STAGE_WAIT );
	
		case STAGE_WAIT:		
			if ( ( gameLocal.isMultiplayer && gameLocal.time >= nextAttackTime ) || 
				 ( !gameLocal.isMultiplayer && ( AnimDone ( ANIMCHANNEL_ALL, 2 ) ) ) ) {
				SetState ( "Idle", 0 );
				return SRESULT_DONE;
			}		
			return SRESULT_WAIT;
	}
	return SRESULT_ERROR;
}


/*
================
rvWeaponRailgun::State_Reload
================
*/
stateResult_t rvWeaponRailgun::State_Reload ( const stateParms_t& parms ) {
	enum {
		STAGE_INIT,
		STAGE_WAIT,
	};	
	switch ( parms.stage ) {
		case STAGE_INIT:
			if ( wsfl.netReload ) {
				wsfl.netReload = false;
			} else {
				NetReload ( );
			}
						
			SetStatus ( WP_RELOAD );
			PlayAnim ( ANIMCHANNEL_ALL, "reload", parms.blendFrames );
			return SRESULT_STAGE ( STAGE_WAIT );
			
		case STAGE_WAIT:
			if ( AnimDone ( ANIMCHANNEL_ALL, 4 ) ) {
				AddToClip ( ClipSize() );
				SetState ( "Idle", 4 );
				return SRESULT_DONE;
			}
			if ( wsfl.lowerWeapon ) {
				StopSound( SND_CHANNEL_BODY2, false );
				SetState ( "Lower", 4 );
				return SRESULT_DONE;
			}
			return SRESULT_WAIT;
	}
	return SRESULT_ERROR;
}

/*
===============================================================================

	Event 

===============================================================================
*/

/*
================
rvWeaponRailgun::State_Reload
================
*/
void rvWeaponRailgun::Event_RestoreHum ( void ) {
	StopSound( SND_CHANNEL_BODY2, false );
	StartSound( "snd_idle_hum", SND_CHANNEL_BODY2, 0, false, NULL );
}

/*
================
rvWeaponRailgun::ClientUnStale
================
*/
void rvWeaponRailgun::ClientUnstale( void ) {
	Event_RestoreHum();
}

