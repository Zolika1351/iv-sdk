/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Please see ScriptHook-License.txt for information on how this source/header
  file is licensed as part of the ScriptHook SDK.

\*****************************************************************************/

#pragma once

#include "ScriptingTypes.h"
#include "ScriptingEnums.h"

class DllExport ScriptingHelpers
{
public:
    static Scripting::eModel GetModelHash(const ch *name);
    static void Wait(u32 timeMS);
    static void TerminateThisScript();
};

namespace Scripting
{

    // Custom helper functions

    static inline eModel GetModelHash(const ch *name) { return ScriptingHelpers::GetModelHash(name); }

    static inline void Wait(u32 timeMS) { ScriptingHelpers::Wait(timeMS); }

    static inline void TerminateThisScript() { ScriptingHelpers::TerminateThisScript(); }

    static inline b8 IsNullHandle(ScriptHandle handle) { return handle.IsNull(); }

    static inline b8 IsValidHandle(ScriptHandle handle) { return handle.IsValid(); }

}

