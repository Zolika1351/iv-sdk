class CCam
{
public:
	uint8_t pad[0x10];													// 000-010
	CMatrix m_mMatrix;													// 010-050
	uint8_t pad2[0x10];													// 050-060
	float m_fFOV;														// 060-064
	float m_fFarZ;														// 064-068
	uint8_t pad3[0xD8];													// 068-140
};
VALIDATE_SIZE(CCam, 0x140); // probably?
VALIDATE_OFFSET(CCam, m_mMatrix, 0x10);
VALIDATE_OFFSET(CCam, m_fFOV, 0x60);
VALIDATE_OFFSET(CCam, m_fFarZ, 0x64);

class CCamFollowVehicle : public CCam
{
public:
																		// 000-140
	uint8_t pad[0x40];													// 140-180
	float m_fTargetFOV;													// 180-184
};
VALIDATE_OFFSET(CCamFollowVehicle, m_fTargetFOV, 0x180);