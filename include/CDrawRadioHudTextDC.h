// probably more general, todo look into this later
struct tRadioHudTextPos
{
	CVector2D bl;
	CVector2D tl;
	CVector2D br;
	CVector2D tr;
};

class CDrawRadioHudTextDC : public CBaseDC
{
public:
	CVector2D m_vVerts[4];						// 00-28
	CSprite2d m_sSprite;						// 28-2C
	CRGBA m_nColor;								// 2C-30
	// coords are ratio of screen (0-1)
	// same as CDrawSpriteDC but with different params?
	CDrawRadioHudTextDC(tRadioHudTextPos* pos, CSprite2d sprite, CRGBA color)
	{
		((void(__thiscall*)(CDrawRadioHudTextDC*, tRadioHudTextPos*, CSprite2d, CRGBA))(AddressSetter::Get(0x3C0D70, 0x4613E0)))(this, pos, sprite, color);
	}
};
VALIDATE_SIZE(CDrawRadioHudTextDC, 0x30);
VALIDATE_OFFSET(CDrawRadioHudTextDC, m_vVerts, 0x8);
VALIDATE_OFFSET(CDrawRadioHudTextDC, m_sSprite, 0x28);
VALIDATE_OFFSET(CDrawRadioHudTextDC, m_nColor, 0x2C);