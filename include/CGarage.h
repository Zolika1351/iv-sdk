class CStoredCar
{
public:
	CVector m_vPos;										// 00-0C
	uint8_t pad[0x4];									// 0C-10
	uint16_t m_nModelIndex;								// 10-12
	uint8_t pad2[0x1E];									// 12-30
	uint16_t m_nFlags;									// 30-32 proofs, etc
	uint8_t m_nPrimaryColor;							// 32-33
	uint8_t m_nSecondaryColor;							// 33-34
	uint8_t m_nTertiaryColor;							// 34-35
	uint8_t m_nQuaternaryColor;							// 35-36
	uint8_t pad3[0x6];									// 36-3C
	uint32_t m_nLivery;									// 3C-40
	uint8_t pad4[0x3];									// 40-43
	uint8_t m_nMatrixUp[3];								// 43-46
	uint16_t pad5;										// 46-48
};
VALIDATE_SIZE(CStoredCar, 0x48);
VALIDATE_OFFSET(CStoredCar, m_vPos, 0x0);
VALIDATE_OFFSET(CStoredCar, m_nFlags, 0x30);
VALIDATE_OFFSET(CStoredCar, m_nPrimaryColor, 0x32);
VALIDATE_OFFSET(CStoredCar, m_nSecondaryColor, 0x33);
VALIDATE_OFFSET(CStoredCar, m_nTertiaryColor, 0x34);
VALIDATE_OFFSET(CStoredCar, m_nQuaternaryColor, 0x35);
VALIDATE_OFFSET(CStoredCar, m_nLivery, 0x3C);
VALIDATE_OFFSET(CStoredCar, m_nMatrixUp, 0x43);

class CGarage
{
public:
	static inline CStoredCar* m_sStoredCars = (CStoredCar*)AddressSetter::Get(0xF54A88, 0xECBE00); // m_sStoredCars[20]
};