class CAudioZones
{
public:
	static inline auto& m_NumSpheres = AddressSetter::GetRef<uint32_t>(0x1293278, 0xF59AC8);
	static inline auto m_aActiveSpheres = (int32_t*)AddressSetter::Get(0x129327C, 0xF59ACC);
	static inline auto& m_NumActiveSpheres = AddressSetter::GetRef<uint32_t>(0x129324C, 0xF59A9C);
	static inline auto& m_NumBoxes = AddressSetter::GetRef<uint32_t>(0x1293244, 0xF59A94);
	static inline auto m_aActiveBoxes = (int32_t*)AddressSetter::Get(0x1293250, 0xF59AA0);
	static inline auto& m_NumActiveBoxes = AddressSetter::GetRef<uint32_t>(0x1293240, 0xF59A90);

	static void Update(bool bForceUpdate, CVector TestCoors)
	{
		((void(__cdecl*)(bool, CVector))(AddressSetter::Get(0x73CDB0, 0x5B1F90)))(bForceUpdate, TestCoors);
	}
};
auto& LastUpdateCoors = AddressSetter::GetRef<CVector>(0x12932B0, 0xF59B00);