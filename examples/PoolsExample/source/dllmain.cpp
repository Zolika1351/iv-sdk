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
	auto mdlinfo = (CVehicleModelInfo*)CModelInfo::GetModelInfo(rage::atStringHash("rom"), &index);

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

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::processScriptsEvent::Add(PoolExample1);
	plugin::processScriptsEvent::Add(PoolExample2);
}