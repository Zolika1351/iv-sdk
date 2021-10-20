class CTaskSimpleSidewaysDive : public CTaskSimple
{
public:
	CTaskSimpleSidewaysDive(bool bDirection)
	{
		((void(__thiscall*)(CTaskSimpleSidewaysDive*, bool))(AddressSetter::Get(0xEDBC0, 0x302F30)))(this, bDirection);
	}
};