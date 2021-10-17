class CTaskComplexNM : public CTaskComplex
{
public:
	//CTaskComplexNM::CTaskComplexNM(v35, 2000, 10000, v34, COERCE_INT(0.0))
	void New(uint32_t nUnk, uint32_t nUnk2, CTaskSimple* pSubTask, float fUnk)
	{
		((void(__thiscall*)(CTaskComplexNM*, uint32_t, uint32_t, CTaskSimple*, float))(AddressSetter::Get(0x85DBE0, 0x7D9100)))(this, nUnk, nUnk2, pSubTask, fUnk);
	}
};