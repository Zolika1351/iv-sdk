/*****************************************************************************\

  Copyright (C) 2009, Aru <oneforaru at gmail dot com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Please see ScriptHook-License.txt for information on how this source/header
  file is licensed as part of the ScriptHook SDK.

\*****************************************************************************/

#pragma once

// Some standard types

typedef unsigned int u32;
typedef int i32;

typedef unsigned short u16;
typedef short i16;

typedef unsigned char u8;
typedef char i8, ch;

typedef wchar_t wch;

typedef float f32;
typedef double f64;

typedef bool b8;
typedef unsigned int b32;

// Define a "any" pointer type, and define casting operations

typedef void * ptr;

template <typename T>
inline T *ptr_cast(u32 value)
{
    return *reinterpret_cast<T **>(&value);
}

inline ptr ptr_cast(u32 value)
{
    return *reinterpret_cast<ptr*>(&value);
}

template <class T>
inline T* ptr_cast(ptr value)
{
    return reinterpret_cast<T*>(value);
}

// Define a null if it already hasn't been

#ifndef NULL
#define NULL (0)
#endif

#ifdef SCRIPTHOOK_EXPORTS
#define DllExport _declspec(dllexport)
#else
#define DllExport _declspec(dllimport)
#endif

