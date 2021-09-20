class CTaskComplexWander : public CTask
{
public:
	uint8_t pad[0x80];											// 00-80
	float m_fUnk;												// 80-84 set to 0 upon initializing CTaskComplexWanderStandard

	CTaskComplexWander(uint32_t moveState, float initialDir, bool bSensibly, float targetRadius, uint32_t unk1)
	{
		((void(__thiscall*)(CTaskComplexWander*, uint32_t, float, bool, float, uint32_t))(AddressSetter::Get(0x618C70, 0x7FA900)))(this, moveState, initialDir, bSensibly, targetRadius, unk1);
	}
};

class CTaskComplexWanderStandard : public CTaskComplexWander
{
public:
	CTaskComplexWanderStandard(uint32_t moveState, float initialDir, bool bSensibly, float targetRadius, uint32_t unk1) : CTaskComplexWander(moveState, initialDir, bSensibly, targetRadius, unk1)
	{
		// set vftable
		*(uint32_t*)this = AddressSetter::Get(0x969794, 0x995474);

		this->m_fUnk = 0;
	}
};