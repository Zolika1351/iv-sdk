#pragma once

// all natives have been changed to use their actual names
// this header is a frankenstein of scripthook, sc-cl and scocl headers with original stuff sprinkled in
// task natives have been given a _ prefix since they crash with the current native calling method and either need to be patched or something in native calling fixed
#include "NativeHashes.h"
#include "BaseScripting.h"