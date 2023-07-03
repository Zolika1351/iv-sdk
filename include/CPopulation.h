class CPopulation
{
public:
	static inline auto& ms_nNumCop = AddressSetter::GetRef<int32_t>(0x123F480, 0xE787F0);
	static inline auto& ms_nNumEmergency = AddressSetter::GetRef<int32_t>(0x123F484, 0xE787F4);
	static inline auto& m_AllRandomPedsThisType = AddressSetter::GetRef<int32_t>(0xB34B7C, 0xB42454);
	static inline auto& PedDensityMultiplier = AddressSetter::GetRef<float>(0xB34B70, 0xB42448);

	static inline auto& ScenarioPedDensityMultiplier = AddressSetter::GetRef<float>(0xB34B74, 0xB4244C);
	static inline auto& ScenarioPedDensityMultiplier2 = AddressSetter::GetRef<float>(0xB34B78, 0xB42450);

	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x5F87D0, 0x531010)))();
	}
	static void RemovePed(CPed* pPed, bool unk)
	{
		return ((void(__cdecl*)(CPed*, bool))(AddressSetter::Get(0x5F8D40, 0x531580)))(pPed, unk);
	}
};