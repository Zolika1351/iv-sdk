class CDrawCurvedWindowDC : public CBaseDC
{
public:
	uint8_t pad[0x14];						// 08-1C
	// coords are ratio of screen (0-1)
	// RGB is ignored, only alpha used
	CDrawCurvedWindowDC(CVector2D* v, float xsize, float ysize, CRGBA color)
	{
		((void(__thiscall*)(CDrawCurvedWindowDC*, CVector2D*, float, float, CRGBA))(AddressSetter::Get(0x3C1190, 0x461800)))(this, v, xsize, ysize, color);
	}
};
VALIDATE_SIZE(CDrawCurvedWindowDC, 0x1C);