#include "ePadControls.h"

class CPed;

struct tValueHistoryItem
{
	uint8_t m_nValue;//0x0
	uint8_t pad[3];//0x1
	uint32_t m_nLastUpdateTime;//0x4
};
VALIDATE_SIZE(tValueHistoryItem, 0x8);

class tValueHistory
{
	tValueHistoryItem m_aItems[64];//0x0
};
VALIDATE_SIZE(tValueHistory, 0x200);

struct tPadValues
{
	uint32_t m_vfTable;//0x0
	uint8_t m_nUnknown4;//0x4
	uint8_t m_nContext;//0x5
	uint8_t m_nCurrentValue;//0x6
	uint8_t m_nLastValue;//0x7
	uint8_t m_nHistoryIndex;//0x8
	uint8_t pad[3];//0x9
	tValueHistory* m_pHistory;//0xC
};
VALIDATE_SIZE(tPadValues, 0x10);

class CPad
{
public:
	uint8_t pad[0x2698];						// 0000-328C
	tPadValues m_aValues[187];					// 2698-3248
	uint8_t pad2[0x41];							// 3248-3289
	uint8_t m_bIsUsingKeyboardForAim;			// 3289-328A
	uint8_t pad3[0x3];							// 324A-328D
	uint8_t m_bIsUsingKeyboardForHeli;			// 328D-328E
	uint8_t pad4[0x7DE];						// 328E-3A6C
	uint32_t m_nLastUpdateTime;					// 3A6C-3A70
	uint8_t pad5[0x14];							// 3A70-3A84

	static CPad* GetPad()
	{
		return ((CPad*(__cdecl*)())(Addresses::nGetPad))();
	}
};
VALIDATE_SIZE(CPad, 0x3A84);
VALIDATE_OFFSET(CPad, m_bIsUsingKeyboardForAim, 0x3289);
VALIDATE_OFFSET(CPad, m_bIsUsingKeyboardForHeli, 0x328D);
VALIDATE_OFFSET(CPad, m_nLastUpdateTime, 0x3A6C);
VALIDATE_OFFSET(CPad, m_aValues, 0x2698);
