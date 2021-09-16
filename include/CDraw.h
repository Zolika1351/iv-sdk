class CDraw
{
public:
	static float CalculateAspectRatio(uint32_t* pUnk, bool bUnk) // bUnk = 1 forces it to 1.777... if pUnk + 0x453 byte is non-zero
	{
		return ((float(__thiscall*)(uint32_t*, bool))(Addresses::nCalculateAspectRatio))(pUnk, bUnk);
	}
};