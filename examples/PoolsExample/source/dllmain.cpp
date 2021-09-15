#include "../../../include/IVSDK.cpp"

// set all peds to 100% accuracy and firerate, with natives
void PoolExample1()
{
	auto pool = CPools::ms_pPedPool;
	for (int i = 0; i < pool->m_dwCount; i++)
	{
		if (auto ped = (CPed*)&pool->m_pObjects[pool->m_dwEntrySize * i])
		{
			int handle = pool->GetIndex(ped);
			Scripting::SET_CHAR_ACCURACY(handle, 100);
			Scripting::SET_CHAR_SHOOT_RATE(handle, 100);
		}
	}
}

// make all romans taxis fly up
void PoolExample2()
{
	int index;
	auto mdlinfo = (CVehicleModelInfo*)CModelInfo::GetModelInfo(CKeyGen::GetKey("rom"), &index);

	auto pool = CPools::ms_pVehiclePool;
	for (int i = 0; i < pool->m_dwCount; i++)
	{
		if (auto veh = (CVehicle*)&pool->m_pObjects[pool->m_dwEntrySize * i])
		{
			if (veh->m_nModelIndex == index)
			{
				if (auto collider = veh->GetConstrainedCollider())
				{
					collider->m_pUnkParameters->m_pParams2->m_vVelocity.z += 1;
				}
			}
		}
	}
}

// every frame while in-game
void plugin::processScriptsEvent()
{
	PoolExample1();
	PoolExample2();
}

// basically just DllMain but fancier and with the sdk initialized
void plugin::gameStartupEvent()
{
	
}

// right after gta.dat loads, put any extra loading related things here
void plugin::gameLoadEvent()
{
	CFileLoader::LoadLevel("test.dat", 0);
	CdStreamAddImage("mods/mods.img", 0, -1);
}