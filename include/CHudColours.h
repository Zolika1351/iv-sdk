#include "eHudColour.h"

class CHudColours
{
public:
	static inline CRGBA* ms_HudColour = (CRGBA*)AddressSetter::Get(0xDE4D40, 0xDE8038); // ms_HudColour[73]
};