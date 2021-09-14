/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Please see ScriptHook-License.txt for information on how this source/header
  file is licensed as part of the ScriptHook SDK.

\*****************************************************************************/

#pragma once

#include "Types.h"

#define DefineScriptHandle(name) typedef struct : ScriptHandle {} name
#define DefineInheritedScriptHandle(name, baseName) typedef struct : baseName {} name

namespace Scripting
{

    typedef u32 ScriptVoid;     // We shall use ScriptVoid instead of explicit void because some 
                                // of our template code return values.

    //typedef u32 ScriptAny;      // ScriptAny for any types that we don't know yet :)

    typedef struct _ScriptHandle
    {
    private:
        u32 Handle;             // Handles are usually just uint32s

    public:
        _ScriptHandle() : Handle(0) {}
        _ScriptHandle(u32 handle) : Handle(handle) {}
        inline b8 IsNull() { return Handle == 0; }
        inline b8 IsValid() { return Handle != 0; }
        inline u32 Get() { return Handle; }

        // The comparison operation is only valid for handles of the same type!
        inline b8 operator == (const _ScriptHandle &other) { return Handle == other.Handle; }
        inline b8 operator != (const _ScriptHandle &other) { return Handle != other.Handle; }

        inline b8 operator == (const u32 handle) { return Handle == handle; }
        inline b8 operator != (const u32 handle) { return Handle != handle; }
    } ScriptHandle;

	//calculation range is -2,147,483,648 to 2,147,483,647
	//any value above or below that will be automatically cast to a signed int
	typedef unsigned int uint;
	typedef unsigned char byte;
	typedef unsigned char uchar;
	typedef unsigned short ushort;

	typedef int Player;
	typedef int Entity;
	typedef Entity Ped;
	typedef Entity Car;
	typedef Entity Vehicle;
	typedef Entity Object;
	typedef uint Hash;
	typedef int Cam;
	typedef int FireId;
	typedef int CarGenerator;
	typedef int Group;
	typedef int Train;
	typedef int Pickup;
	typedef int Object;
	typedef int Weapon;
	typedef int Interior;
	typedef int Blip;
	typedef int Texture;
	typedef int TextureDict;
	typedef int CoverPoint;
	typedef int Camera;
	typedef int TaskSequence;
	typedef int ColourIndex;
	typedef int Sphere;
	typedef int ScrHandle;
	typedef int DecisionMaker;
	typedef int ScriptAny;
	typedef int UnkInt;
	typedef int Actor;
	typedef int Controller;
	typedef int Layout;
	typedef int Iterator;
	typedef int IterationSet;
	typedef int GUIWindow;
	typedef float Time;
    
    // Some real structures... these are never passed in directly, but only
    // by reference.

	typedef union vector3
	{
		struct { float x, y, z; };
		float v[3];
	} vector3;

	typedef vector3 Vector3;
}
