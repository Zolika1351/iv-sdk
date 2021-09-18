#include "eHudColour.h"

class CHudColour
{
public:
	uint8_t b, g, r, a;
};

class CHudColours
{
public:
	static inline CHudColour* ms_HudColour = (CHudColour*)AddressSetter::Get(0xDE4D40, 0xDE8038); // ms_HudColour[73]
};