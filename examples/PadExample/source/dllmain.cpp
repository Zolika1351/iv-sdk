#include "../../../include/IVSDK.cpp"

// launch player when jump is held
void PadExample1()
{
	auto ped = CPlayerInfo::GetPlayerInfo(CWorld::PlayerInFocus)->m_pPlayerPed;
	if (ped)
	{
		auto pad = ped->GetPadFromPlayer(); // can also use CPad::GetPad()
		int value = pad->m_aValues[INPUT_JUMP].m_nCurrentValue;
		if (ped->m_pInstGta->m_nRigidBodyIndex != -1)
		{
			CVector v;
			ped->GetVelocity(&v);
			v.z += CTimer::ms_fTimeStep * value * 10;
			ped->GetConstrainedCollider()->SetVelocity(&v);
		}
	}
}

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::processScriptsEvent::Add(PadExample1);
}