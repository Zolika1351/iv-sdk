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

// every frame while in-game
void plugin::processScriptsEvent()
{
	PadExample1();
}

// basically just DllMain but fancier and with the sdk initialized
void plugin::gameStartupEvent()
{
	
}

// right after gta.dat loads, put any extra loading related things here
void plugin::gameLoadEvent()
{
	
}
