template<typename T>
class CStore
{
public:
	uint32_t m_maxItems;				// 00-04
	uint32_t m_nextItem;				// 04-08
	T* m_storeArray;					// 08-0C
};

auto& ms_vehicleModelStore = AddressSetter::GetRef<CStore<CVehicleModelInfo>>(0xB2C14C, 0xB3E8E8);
auto& ms_pedModelStore = AddressSetter::GetRef<CStore<CPedModelInfo>>(0xB2C158, 0xB3E8F4);