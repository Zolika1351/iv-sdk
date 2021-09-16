#include "eHudColour.h"

class CHudColour
{
public:
	uint8_t b, g, r, a;
};

class CHudColours
{
public:
	static inline CHudColour* ms_HudColour; // ms_HudColour[73]
};