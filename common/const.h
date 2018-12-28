/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#ifndef CONST_H
#define CONST_H
#ifdef _WIN32
#pragma once
#endif

#include "common.h"

// buttons
#ifndef IN_BUTTONS_H
#include "in_buttons.h"
#endif

#define FL_FLY					(1<<0)	// Changes the SV_Movestep() behavior to not need to be on ground
#define FL_SWIM					(1<<1)	// Changes the SV_Movestep() behavior to not need to be on ground (but stay in water)
#define FL_CONVEYOR				(1<<2)
#define FL_CLIENT				(1<<3)
#define FL_INWATER				(1<<4)
#define FL_MONSTER				(1<<5)
#define FL_GODMODE				(1<<6)
#define FL_NOTARGET				(1<<7)
#define FL_SKIPLOCALHOST			(1<<8)	// Don't send entity to local host, it's predicting this entity itself
#define FL_ONGROUND				(1<<9)	// At rest / on the ground
#define FL_PARTIALGROUND			(1<<10)	// not all corners are valid
#define FL_WATERJUMP				(1<<11)	// player jumping out of water
#define FL_FROZEN				(1<<12)	// Player is frozen for 3rd person camera
#define FL_FAKECLIENT				(1<<13)	// JAC: fake client, simulated server side; don't send network messages to them
#define FL_DUCKING				(1<<14)	// Player flag -- Player is fully crouched
#define FL_FLOAT				(1<<15)	// Apply floating force to this entity when in water
#define FL_GRAPHED				(1<<16)	// worldgraph has this ent listed as something that blocks a connection

#define FL_IMMUNE_WATER				(1<<17)
#define FL_IMMUNE_SLIME				(1<<18)
#define FL_IMMUNE_LAVA				(1<<19)

#define FL_PROXY				(1<<20)	// This is a spectator proxy
#define FL_ALWAYSTHINK				(1<<21)	// Brush model flag -- call think every frame regardless of nextthink - ltime (for constantly changing velocity/path)
#define FL_BASEVELOCITY				(1<<22)	// Base velocity has been applied this frame (used to convert base velocity into momentum)
#define FL_MONSTERCLIP				(1<<23)	// Only collide in with monsters who have FL_MONSTERCLIP set
#define FL_ONTRAIN				(1<<24)	// Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_WORLDBRUSH				(1<<25)	// Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something)
#define FL_SPECTATOR				(1<<26)	// This client is a spectator, don't run touch functions, etc.
#define FL_CUSTOMENTITY				(1<<29)	// This is a custom entity
#define FL_KILLME				(1<<30)	// This entity is marked for death -- This allows the engine to kill ents at the appropriate time
#define FL_DORMANT				(1<<31)	// Entity is dormant, no updates to client

// Engine edict->spawnflags
#define SF_NOTINDEATHMATCH			0x0800	// Do not spawn when deathmatch and loading entities from a file

// Goes into globalvars_t.trace_flags
#define FTRACE_SIMPLEBOX			(1<<0)	// Traceline with a simple box

// walkmove modes
#define WALKMOVE_NORMAL				0	// normal walkmove
#define WALKMOVE_WORLDONLY			1	// doesn't hit ANY entities, no matter what the solid type
#define WALKMOVE_CHECKONLY			2	// move, but don't touch triggers

#define MOVETYPE_NONE				0	// never moves
//#define MOVETYPE_ANGLENOCLIP	1
//#define MOVETYPE_ANGLECLIP			2
#define MOVETYPE_WALK				3	// Player only - moving on the ground
#define MOVETYPE_STEP				4	// gravity, special edge handling -- monsters use this
#define MOVETYPE_FLY				5	// No gravity, but still collides with stuff
#define MOVETYPE_TOSS				6	// gravity/collisions
#define MOVETYPE_PUSH				7	// no clip to world, push and crush
#define MOVETYPE_NOCLIP				8	// No gravity, no collisions, still do velocity/avelocity
#define MOVETYPE_FLYMISSILE			9	// extra size to monsters
#define MOVETYPE_BOUNCE				10	// Just like Toss, but reflect velocity when contacting surfaces
#define MOVETYPE_BOUNCEMISSILE			11	// bounce w/o gravity
#define MOVETYPE_FOLLOW				12	// track movement of aiment
#define MOVETYPE_PUSHSTEP			13	// BSP model that needs physics/world collisions (uses nearest hull for world collision)

#define SOLID_NOT				0	// no interaction with other objects
#define SOLID_TRIGGER				1	// touch on edge, but not blocking
#define SOLID_BBOX				2	// touch on edge, block
#define SOLID_SLIDEBOX				3	// touch on edge, but not an onground
#define SOLID_BSP				4	// bsp clip, touch on edge, block

// deadflag values
#define DEAD_NO					0	// alive
#define DEAD_DYING				1	// playing death animation or still falling off of a ledge waiting to hit ground
#define DEAD_DEAD				2	// dead. lying still.
#define DEAD_RESPAWNABLE			3
#define DEAD_DISCARDBODY			4

#define DAMAGE_NO				0
#define DAMAGE_YES				1
#define DAMAGE_AIM				2

// entity effects
#define EF_BRIGHTFIELD				1	// swirling cloud of particles
#define EF_MUZZLEFLASH 				2	// single frame ELIGHT on entity attachment 0
#define EF_BRIGHTLIGHT 				4	// DLIGHT centered at entity origin
#define EF_DIMLIGHT 				8	// player flashlight
#define EF_INVLIGHT				16	// get lighting from ceiling
#define EF_NOINTERP				32	// don't interpolate the next frame
#define EF_LIGHT				64	// rocket flare glow sprite
#define EF_NODRAW				128	// don't draw entity
#define EF_NIGHTVISION				256	// player nightvision
#define EF_SNIPERLASER				512	// sniper laser effect
#define EF_FIBERCAMERA				1024	// fiber camera

// entity flags
#define EFLAG_SLERP				1	// do studio interpolation of this entity

#define TE_BEAMPOINTS				0	// beam effect between two points
#define TE_BEAMENTPOINT				1	// beam effect between point and entity
#define TE_GUNSHOT				2	// particle effect plus ricochet sound
#define TE_EXPLOSION				3	// additive sprite, 2 dynamic lights, flickering particles, explosion sound, move vertically 8 pps
#define TE_EXPLFLAG_NONE			0	// all flags clear makes default Half-Life explosion
#define TE_EXPLFLAG_NOADDITIVE			1	// sprite will be drawn opaque (ensure that the sprite you send is a non-additive sprite)
#define TE_EXPLFLAG_NODLIGHTS			2	// do not render dynamic lights
#define TE_EXPLFLAG_NOSOUND			4	// do not play client explosion sound
#define TE_EXPLFLAG_NOPARTICLES			8	// do not draw particles
#define TE_TAREXPLOSION				4	// Quake1 "tarbaby" explosion with sound
#define TE_SMOKE				5		// alphablend sprite, move vertically 30 pps
#define TE_TRACER				6		// tracer effect from point to point
#define TE_LIGHTNING				7		// TE_BEAMPOINTS with simplified parameters
#define TE_BEAMENTS				8
#define TE_SPARKS				9		// 8 random tracers with gravity, ricochet sprite
#define TE_LAVASPLASH				10		// Quake1 lava splash
#define TE_TELEPORT				11		// Quake1 teleport splash
#define TE_EXPLOSION2				12		// Quake1 colormaped (base palette) particle explosion with sound
#define TE_BSPDECAL				13		// Decal from the .BSP file
#define TE_IMPLOSION				14		// tracers moving toward a point
#define TE_SPRITETRAIL				15		// line of moving glow sprites with gravity, fadeout, and collisions
#define TE_BEAM					16		// obsolete
#define TE_SPRITE				17		// additive sprite, plays 1 cycle
#define TE_BEAMSPRITE				18		// A beam with a sprite at the end
#define TE_BEAMTORUS				19		// screen aligned beam ring, expands to max radius over lifetime
#define TE_BEAMDISK				20		// disk that expands to max radius over lifetime
#define TE_BEAMCYLINDER				21		// cylinder that expands to max radius over lifetime
#define TE_BEAMFOLLOW				22		// create a line of decaying beam segments until entity stops moving
#define TE_GLOWSPRITE				23
#define TE_BEAMRING				24		// connect a beam ring to two entities
#define TE_STREAK_SPLASH			25		// oriented shower of tracers
#define TE_BEAMHOSE				26		// obsolete
#define TE_DLIGHT				27		// dynamic light, effect world, minor entity effect
#define TE_ELIGHT				28		// point entity light, no world effect
#define TE_TEXTMESSAGE				29
#define TE_LINE					30
#define TE_BOX					31
#define TE_KILLBEAM				99		// kill all beams attached to entity
#define TE_LARGEFUNNEL				100
#define TE_BLOODSTREAM				101		// particle spray
#define TE_SHOWLINE				102		// line of particles every 5 units, dies in 30 seconds
#define TE_BLOOD				103		// particle spray
#define TE_DECAL				104		// Decal applied to a brush entity (not the world)
#define TE_FIZZ					105		// create alpha sprites inside of entity, float upwards
#define TE_MODEL				106		// create a moving model that bounces and makes a sound when it hits
#define TE_EXPLODEMODEL				107		// spherical shower of models, picks from set
#define TE_BREAKMODEL				108		// box of models or sprites
#define TE_GUNSHOTDECAL				109		// decal and ricochet sound
#define TE_SPRITE_SPRAY				110		// spay of alpha sprites
#define TE_ARMOR_RICOCHET			111		// quick spark sprite, client ricochet sound.
#define TE_PLAYERDECAL				112		// ???
#define TE_BUBBLES				113		// create alpha sprites inside of box, float upwards
#define TE_BUBBLETRAIL				114		// create alpha sprites along a line, float upwards
#define TE_BLOODSPRITE				115		// spray of opaque sprite1's that fall, single sprite2 for 1..2 secs (this is a high-priority tent)
#define TE_WORLDDECAL				116		// Decal applied to the world brush
#define TE_WORLDDECALHIGH			117		// Decal (with texture index > 256) applied to world brush
#define TE_DECALHIGH				118		// Same as TE_DECAL, but the texture index was greater than 256
#define TE_PROJECTILE				119		// Makes a projectile (like a nail) (this is a high-priority tent)
#define TE_SPRAY				120		// Throws a shower of sprites or models
#define TE_PLAYERSPRITES			121		// sprites emit from a player's bounding box (ONLY use for players!)
#define TE_PARTICLEBURST			122		// very similar to lavasplash.
#define TE_FIREFIELD				123		// makes a field of fire.

// to keep network traffic low, this message has associated flags that fit into a byte:
#define TEFIRE_FLAG_ALLFLOAT			1 // all sprites will drift upwards as they animate
#define TEFIRE_FLAG_SOMEFLOAT			2 // some of the sprites will drift upwards. (50% chance)
#define TEFIRE_FLAG_LOOP			4 // if set, sprite plays at 15 fps, otherwise plays at whatever rate stretches the animation over the sprite's duration.
#define TEFIRE_FLAG_ALPHA			8 // if set, sprite is rendered alpha blended at 50% else, opaque
#define TEFIRE_FLAG_PLANAR			16 // if set, all fire sprites have same initial Z instead of randomly filling a cube.
#define TEFIRE_FLAG_ADDITIVE			32 // if set, sprite is rendered non-opaque with additive
#define TE_PLAYERATTACHMENT			124 // attaches a TENT to a player (this is a high-priority tent)
#define TE_KILLPLAYERATTACHMENTS		125 // will expire all TENTS attached to a player.
#define TE_MULTIGUNSHOT				126 // much more compact shotgun message
#define TE_USERTRACER				127 // larger message than the standard tracer, but allows some customization.

#define MSG_BROADCAST				0		// unreliable to all
#define MSG_ONE					1		// reliable to one (msg_entity)
#define MSG_ALL					2		// reliable to all
#define MSG_INIT				3		// write to the init string
#define MSG_PVS					4		// Ents in PVS of org
#define MSG_PAS					5		// Ents in PAS of org
#define MSG_PVS_R				6		// Reliable to PVS
#define MSG_PAS_R				7		// Reliable to PAS
#define MSG_ONE_UNRELIABLE			8		// Send to one client, but don't put in reliable stream, put in unreliable datagram ( could be dropped )
#define MSG_SPEC				9		// Sends to all spectator proxies

// contents of a spot in the world
#define CONTENTS_EMPTY				-1
#define CONTENTS_SOLID				-2
#define CONTENTS_WATER				-3
#define CONTENTS_SLIME				-4
#define CONTENTS_LAVA				-5
#define CONTENTS_SKY				-6

#define CONTENTS_LADDER				-16

#define CONTENT_FLYFIELD			-17
#define CONTENT_GRAVITY_FLYFIELD		-18
#define CONTENT_FOG				-19

#define CONTENT_EMPTY				-1
#define CONTENT_SOLID				-2
#define CONTENT_WATER				-3
#define CONTENT_SLIME				-4
#define CONTENT_LAVA				-5
#define CONTENT_SKY				-6

// channels
#define CHAN_AUTO				0
#define CHAN_WEAPON				1
#define CHAN_VOICE				2
#define CHAN_ITEM				3
#define CHAN_BODY				4
#define CHAN_STREAM				5		// allocate stream channel from the static or dynamic area
#define CHAN_STATIC				6		// allocate channel from the static area
#define CHAN_NETWORKVOICE_BASE			7		// voice data coming across the network
#define CHAN_NETWORKVOICE_END			500		// network voice data reserves slots (CHAN_NETWORKVOICE_BASE through CHAN_NETWORKVOICE_END).
#define CHAN_BOT				501		// channel used for bot chatter.

// attenuation values
#define ATTN_NONE				0
#define ATTN_NORM				0.8
#define ATTN_IDLE				2.0
#define ATTN_STATIC				1.25

// pitch values
#define PITCH_NORM				100		// non-pitch shifted
#define PITCH_LOW				95		// other values are possible - 0-255, where 255 is very high
#define PITCH_HIGH				120

// volume values
#define VOL_NORM				1.0

// plats
#define PLAT_LOW_TRIGGER			1

// Trains
#define SF_TRAIN_WAIT_RETRIGGER			1
#define SF_TRAIN_START_ON			4		// Train is initially moving
#define SF_TRAIN_PASSABLE			8		// Train is not solid -- used to make water trains

// Break Model Defines
#define BREAK_TYPEMASK				0x4F
#define BREAK_GLASS				0x01
#define BREAK_METAL				0x02
#define BREAK_FLESH				0x04
#define BREAK_WOOD				0x08

#define BREAK_SMOKE				0x10
#define BREAK_TRANS				0x20
#define BREAK_CONCRETE				0x40
#define BREAK_2					0x80

// Colliding temp entity sounds
#define BOUNCE_GLASS				BREAK_GLASS
#define BOUNCE_METAL				BREAK_METAL
#define BOUNCE_FLESH				BREAK_FLESH
#define BOUNCE_WOOD				BREAK_WOOD
#define BOUNCE_SHRAP				0x10
#define BOUNCE_SHELL				0x20
#define BOUNCE_CONCRETE 			BREAK_CONCRETE
#define BOUNCE_SHOTSHELL 			0x80

// Temp entity bounce sound types
#define TE_BOUNCE_NULL				0
#define TE_BOUNCE_SHELL				1
#define TE_BOUNCE_SHOTSHELL			2

// Rendering constants
enum
{
	kRenderNormal,			// src
	kRenderTransColor,		// c*a+dest*(1-a)
	kRenderTransTexture,		// src*a+dest*(1-a)
	kRenderGlow,			// src*a+dest -- No Z buffer checks
	kRenderTransAlpha,		// src*srca+dest*(1-srca)
	kRenderTransAdd,		// src*a+dest
};

enum
{
	kRenderFxNone = 0,
	kRenderFxPulseSlow,
	kRenderFxPulseFast,
	kRenderFxPulseSlowWide,
	kRenderFxPulseFastWide,
	kRenderFxFadeSlow,
	kRenderFxFadeFast,
	kRenderFxSolidSlow,
	kRenderFxSolidFast,
	kRenderFxStrobeSlow,
	kRenderFxStrobeFast,
	kRenderFxStrobeFaster,
	kRenderFxFlickerSlow,
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,		// Distort/scale/translate flicker
	kRenderFxHologram,		// kRenderFxDistort + distance fade
	kRenderFxDeadPlayer,		// kRenderAmt is the player index
	kRenderFxExplode,		// Scale up really big!
	kRenderFxGlowShell,		// Glowing Shell
	kRenderFxClampMinScale,		// Keep this sprite from getting very small (SPRITES only!)
	kRenderFxLightMultiplier,	//CTM !!!CZERO added to tell the studiorender that the value in iuser2 is a lightmultiplier
};

typedef struct
{
	byte r, g, b;
} color24;

typedef struct
{
	unsigned r, g, b, a;
} colorVec;

#ifdef _WIN32
#pragma pack(push,2)
#endif

typedef struct
{
	unsigned short r,g,b,a;
} PackedColorVec;

#ifdef _WIN32
#pragma pack(pop)
#endif

typedef struct link_s
{
	struct link_s *prev, *next;
} link_t;

typedef struct edict_s edict_t;

typedef struct
{
	vec3_t normal;
	float dist;
} plane_t;

typedef struct
{
	qboolean allsolid;		// if true, plane is not valid
	qboolean startsolid;		// if true, the initial point was in a solid area
	qboolean inopen, inwater;
	float fraction;			// time completed, 1.0 = didn't hit anything
	vec3_t endpos;			// final position
	plane_t plane;			// surface normal at impact
	edict_t *ent;			// entity the surface is on
	int hitgroup;			// 0 == generic, non zero is specific body part
} trace_t;

#endif // CONST_H
