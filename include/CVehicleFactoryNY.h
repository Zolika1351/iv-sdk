class CVehicleFactory
{
public:

};

class CVehicleFactoryNY : CVehicleFactory
{
public:

	CVehicle* CreateVehicle(int32_t model, int32_t createdBy, CMatrix* mat, bool bNetwork)
	{
		return ((CVehicle * (__thiscall*)(CVehicleFactoryNY*, int32_t, int32_t, CMatrix*, bool))(*(void***)this)[1])(this, model, createdBy, mat, bNetwork);
	}
};

CVehicleFactoryNY*& VehicleFactory = AddressSetter::GetRef<CVehicleFactoryNY*>(0x11F5514, 0xE52DE8);