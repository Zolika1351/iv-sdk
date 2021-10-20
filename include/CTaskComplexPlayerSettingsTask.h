class CTaskComplexPlayerSettingsTask : public CTaskComplex
{
public:
	uint8_t pad[0x14];										// 00-14
	uint32_t m_nUnk0;										// 14-18
	int32_t m_nUnkNeg1;										// 18-1C
	int32_t m_nUnkNeg1_2;									// 1C-20
	uint32_t m_nUnkFromPed;									// 20-24 pedPtr + 0xE80
	CTaskComplexPlayerSettingsTask(uint32_t unkFromPed)
	{
		// this was inlined
		((void(__thiscall*)(CTaskComplex*))(AddressSetter::Get(0x628AF0, 0x703040)))(this); // CTaskComplex::CTaskComplex
		m_nUnk0 = 0;
		m_nUnkNeg1 = -1;
		m_nUnkNeg1_2 = -1;
		m_nUnkFromPed = unkFromPed;
	}
};
VALIDATE_OFFSET(CTaskComplexPlayerSettingsTask, m_nUnk0, 0x14);
VALIDATE_OFFSET(CTaskComplexPlayerSettingsTask, m_nUnkNeg1, 0x18);
VALIDATE_OFFSET(CTaskComplexPlayerSettingsTask, m_nUnkNeg1_2, 0x1C);
VALIDATE_OFFSET(CTaskComplexPlayerSettingsTask, m_nUnkFromPed, 0x20);