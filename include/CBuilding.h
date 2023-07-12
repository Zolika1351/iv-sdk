class CBuilding : public CEntity
{
public:

	void ReplaceWithNewModel(int32_t index)
	{
		return ((void(__thiscall*)(CBuilding*, int32_t))(AddressSetter::Get(0x71B430, 0x4DDD00)))(this, index);
	}
};

VALIDATE_SIZE(CBuilding, 0x70);
