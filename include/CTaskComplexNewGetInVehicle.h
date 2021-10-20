enum eNewGetInVehicleType
{
	GET_IN_NETWORK = -5, // get into the passenger seat if the driver is friendly
	GET_IN_TRAIN = -6, // trains will only work using this type but regular cars are unaffected
	GET_IN_DEFAULT_PLAYER = -7,
};

class CTaskComplexNewGetInVehicle : public CTaskComplex
{
public:
	CTaskComplexNewGetInVehicle(CVehicle* veh, int32_t getInType, uint32_t unk27, int32_t unk, float fUnk)
	{
		((void(__thiscall*)(CTaskComplexNewGetInVehicle*, CVehicle*, int32_t, uint32_t, int32_t, float))(AddressSetter::Get(0x62BCF0, 0x86DFD0)))(this, veh, getInType, unk27, unk, fUnk);
	}
};