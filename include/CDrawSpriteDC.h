class CDrawSpriteDC : public CBaseDC
{
public:
	CVector2D m_vVerts[4];						// 00-28
	CSprite2d m_sSprite;						// 28-2C
	CRGBA m_nColor;								// 2C-30
	// coords are ratio of screen (0-1)
	CDrawSpriteDC(CVector2D* bl, CVector2D* tl, CVector2D* br, CVector2D* tr, CRGBA color, CSprite2d sprite)
	{
		((void(__thiscall*)(CDrawSpriteDC*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CRGBA, CSprite2d))(AddressSetter::Get(0x3C0F00, 0x461560)))(this, bl, tl, br, tr, color, sprite);
	}
};
VALIDATE_SIZE(CDrawSpriteDC, 0x30);
VALIDATE_OFFSET(CDrawSpriteDC, m_vVerts, 0x8);
VALIDATE_OFFSET(CDrawSpriteDC, m_sSprite, 0x28);
VALIDATE_OFFSET(CDrawSpriteDC, m_nColor, 0x2C);