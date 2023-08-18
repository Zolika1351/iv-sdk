#include "eRadarSprite.h"

class CSprite2d;

struct sRadarTraceProperties
{
	uint8_t pad[0x4];									// 00-04
	uint32_t m_nSprite;									// 04-08
};

struct sRadarTrace
{
	uint16_t ReferenceIndex;							// 00-02
	uint8_t pad[0x6];									// 02-08
	uint8_t m_bNotSimple;								// 08-09 usually 1, if not then it reads everything from ms_RadarTrace[m_nSimpleBlipIndex]
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
VALIDATE_OFFSET(sRadarTrace, ReferenceIndex, 0x0);
VALIDATE_OFFSET(sRadarTrace, m_bNotSimple, 0x8);
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
	static inline auto RadarTrace = (sRadarTrace**)AddressSetter::Get(0xD9ED50, 0xDE83A0); // RadarTrace[1500]
	static inline auto& m_pRadarRingBack = AddressSetter::GetRef<CSprite2d>(0xB1C9B0, 0xB35F50);
	static inline auto& m_pRadarRingFront = AddressSetter::GetRef<CSprite2d>(0xB1C9B4, 0xB35F54);
	static inline auto RadarBlipSprites = (CSprite2d**)AddressSetter::Get(0xD9EB20, 0xDE8170); // RadarBlipSprites[128]
	static inline auto& iNumCreatedBlipSprites = AddressSetter::GetRef<int>(0xD9ED48, 0xDE8398);
	static inline auto& fRange = AddressSetter::GetRef<float>(0xD9ED40, 0xDE8390);
	static inline auto& vec2DRadarOrigin = AddressSetter::GetRef<CVector2D>(0xCC831C, 0xCFC9EC);

	static inline auto& iCentreBlip = AddressSetter::GetRef<int32_t>(0xB1C984, 0xB35F24);
	static inline auto& iNorthBlip = AddressSetter::GetRef<int32_t>(0xB1C98C, 0xB35F2C);
	static inline auto& iSimpleBlip = AddressSetter::GetRef<int32_t>(0xB1C97C, 0xB35F1C);
	static inline auto& iBlipHovering = AddressSetter::GetRef<int32_t>(0xB1C974, 0xB35F14);

	static void DrawBlips()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x412170, 0x472D30)))();
	}
	static void DrawBlipNames()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x40D7F0, 0x46E340)))();
	}
	static void DrawFrameFront()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x40BB20, 0x46C670)))();
	}
	static void DrawFrameBack()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x40A380, 0x46AEE0)))();
	}
	static void DrawRoute(bool bMenu)
	{
		((void(__cdecl*)(bool))(AddressSetter::Get(0x46F490, 0x4920D0)))(bMenu);
	}
	static int32_t ConvertUniqueBlipToActualBlip(int32_t Index)
	{
		return ((int32_t(__cdecl*)(int32_t))(AddressSetter::Get(0x40AA80, 0x46B5E0)))(Index);
	}
	static int32_t CreateBlip(bool unk, int32_t BlpType, CVector* vecPosition, int32_t DispFlag, char* pScriptName)
	{
		return ((int32_t(__cdecl*)(bool, int32_t, CVector*, int32_t, char*))(AddressSetter::Get(0x412750, 0x473310)))(unk, BlpType, vecPosition, DispFlag, pScriptName);
	}
	static void SetBlipParameter(int paramId, int32_t Index, int value)
	{
		((void(__cdecl*)(int, int32_t, int))(AddressSetter::Get(0x410DC0, 0x471980)))(paramId, Index, value);
	}
	// 0 - scale
	// 16 - rotation
	static void SetBlipParameter(int paramId, int32_t Index, float value)
	{
		((void(__cdecl*)(int, int32_t, float))(AddressSetter::Get(0x40E720, 0x46F270)))(paramId, Index, value);
	}
	static bool RemoveBlip(int32_t Index, bool isScriptHandle)
	{
		return ((bool(__cdecl*)(int32_t, bool))(AddressSetter::Get(0x40E620, 0x46F170)))(Index, isScriptHandle);
	}
	static bool IsBlipIdInUse(int32_t Index)
	{
		return ((bool(__cdecl*)(int32_t))(AddressSetter::Get(0x40E600, 0x46F150)))(Index);
	}
};

auto RadarBlipSpriteFilenames = (const char**)AddressSetter::Get(0xC844F8, 0xC91690); // RadarBlipSpriteFilenames[130]