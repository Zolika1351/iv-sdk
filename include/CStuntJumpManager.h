class CBoundBox
{
public:
	CVector_pad m_vecMin;
	CVector_pad m_vecMax;
}; 

class CStuntJump
{
public:
	CBoundBox m_bbStart;						// 00-20
	CBoundBox m_bbEnd;							// 20-40
	CVector m_vecCamera;						// 40-4C
	uint32_t unk1;								// 4C-50
	uint32_t m_iScore;							// 50-54
	uint8_t m_bPassed;							// 54-55
	uint8_t m_bFound;							// 55-56
	uint8_t pad[0xA];							// 56-60
};
VALIDATE_SIZE(CStuntJump, 0x60);
VALIDATE_OFFSET(CStuntJump, m_vecCamera, 0x40);
VALIDATE_OFFSET(CStuntJump, m_iScore, 0x50);
VALIDATE_OFFSET(CStuntJump, m_bPassed, 0x54);

class CStuntJumpManager
{
public:
	static inline auto& m_bActive = AddressSetter::GetRef<bool>(0x11E3588, 0x1343108);
	static inline auto& m_iNumCompleted = AddressSetter::GetRef<uint32_t>(0x11E3598, 0x1343118);
	static inline auto& m_iNumJumps = AddressSetter::GetRef<uint32_t>(0x11E3594, 0x1343114);
	static inline auto& mp_poolStuntJumps = AddressSetter::GetRef<CPool<CStuntJump>*>(0x11E3580, 0x1343100);

	static bool Save()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x56D020, 0x8C4190)))();
	}
	static bool Load()
	{
		return ((int(__cdecl*)())(AddressSetter::Get(0x56D1D0, 0x8C4340)))();
	}
};