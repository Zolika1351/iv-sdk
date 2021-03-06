#include "eRadarSprite.h"

class CSprite2d;

struct sRadarTraceProperties
{
	uint8_t pad[0x4];									// 00-04
	uint32_t m_nSprite;									// 04-08
};

struct sRadarTrace
{
	uint8_t pad[0x8];									// 00-08
	uint8_t m_bSomething;								// 08-09 usually 1, if not then it reads everything from ms_RadarTrace[dword_B35F1C]
	uint8_t pad2[0x3];									// 09-0C
	uint32_t m_nDisplay;								// 0C-10
	uint8_t pad3[0x8];									// 10-18
	float m_fScaleActual;								// 18-1C
	uint8_t pad4[0x4];									// 1C-20
	uint8_t m_nFlags;									// 20-24
	uint8_t pad5[0xF];									// 09-20
	CVector m_vPos;										// 30-3C
	uint8_t pad6[0x4];									// 3C-40
	float m_fRotation;									// 40-44
	uint8_t pad7[0xC];									// 44-50
	float m_fScale;										// 50-54
	uint32_t m_nColour;									// 54-58 
	uint8_t m_nAlpha;									// 58-59
	uint8_t pad8[0x3];									// 59-5C
	sRadarTraceProperties* m_pProperties;				// 5C-60
};
VALIDATE_OFFSET(sRadarTrace, m_bSomething, 0x8);
VALIDATE_OFFSET(sRadarTrace, m_nDisplay, 0xC);
VALIDATE_OFFSET(sRadarTrace, m_fScaleActual, 0x18);
VALIDATE_OFFSET(sRadarTrace, m_nFlags, 0x20);
VALIDATE_OFFSET(sRadarTrace, m_vPos, 0x30);
VALIDATE_OFFSET(sRadarTrace, m_fRotation, 0x40);
VALIDATE_OFFSET(sRadarTrace, m_fScale, 0x50);
VALIDATE_OFFSET(sRadarTrace, m_nAlpha, 0x58);
VALIDATE_OFFSET(sRadarTrace, m_pProperties, 0x5C);

class CRadar
{
public:
	static inline sRadarTrace** ms_RadarTrace = (sRadarTrace**)AddressSetter::Get(0xD9ED50, 0xDE83A0); // ms_RadarTrace[1500]
	static inline CSprite2d& m_pRadarRingBack = AddressSetter::GetRef<CSprite2d>(0xB1C9B0, 0xB35F50);
	static inline CSprite2d& m_pRadarRingFront = AddressSetter::GetRef<CSprite2d>(0xB1C9B4, 0xB35F54);
	static inline CSprite2d** RadarSprites = (CSprite2d**)AddressSetter::Get(0xD9EB20, 0xDE8170); // RadarSprites[128]
	static inline float& m_radarRange = AddressSetter::GetRef<float>(0xD9ED40, 0xDE8390);
	static inline CVector2D& vec2DRadarOrigin = AddressSetter::GetRef<CVector2D>(0xCC831C, 0xCFC9EC);

	static void DrawBlips()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x412170, 0x472D30)))();
	}
	static void DrawBlipNames()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x40D7F0, 0x46E340)))();
	}
	static void DrawRoute(bool bMenu)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get(0x46F490, 0x4920D0)))(bMenu);
	}
};