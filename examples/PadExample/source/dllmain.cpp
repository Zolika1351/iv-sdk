#include "../../../include/IVSDK.cpp"

// launch player when jump is held
void PadExample1()
{
	auto ped = CPlayerInfo::GetPlayerInfo(CWorld::PlayerInFocus)->m_pPlayerPed;
	if (ped)
	{
		auto pad = ped->GetPadFromPlayer(); // can also use CPad::GetPad()
		int value = pad->m_aValues[CONTROL_JUMP].m_nCurrentValue;
		// while SET_CHAR_VELOCITY would be better suited for this, the buggy velocity by using the collider is too good
		if (auto collider = ped->GetConstrainedCollider())
		{
			collider->m_vPedVelocity.z += CTimer::ms_fTimeStep * value * 100;
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