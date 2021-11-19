class CDrawSpriteUVDC : public CBaseDC
{
public:
	CVector2D m_vVerts[4];						// 08-28
	CVector2D m_vUVVerts[4];					// 28-48
	CSprite2d m_sSprite;						// 48-4C
	CRGBA m_nColor;								// 4C-50
	// coords are ratio of screen (0-1)
	// first set is for position
	// second set is for uv multiplier? all 4 vertices
	// 0 1, 0 0, 1 1, 1 0 draws exactly like CDrawSpriteDC
	CDrawSpriteUVDC(CVector2D* bl, CVector2D* tl, CVector2D* br, CVector2D* tr, CVector2D* bl2, CVector2D* tl2, CVector2D* br2, CVector2D* tr2, CRGBA color, CSprite2d sprite)
	{
		((void(__thiscall*)(CDrawSpriteUVDC*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CVector2D*, CRGBA, CSprite2d))(AddressSetter::Get(0x3C1050, 0x4616B0)))(this, bl, tl, br, tr, bl2, tl2, br2, tr2, color, sprite);
	}
};
VALIDATE_SIZE(CDrawSpriteUVDC, 0x50);