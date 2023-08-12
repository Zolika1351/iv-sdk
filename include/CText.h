class CText
{
public:
	const wchar_t* Get(const char* Ident)
	{
		return ((const wchar_t*(__thiscall*)(CText*, const char*))(AddressSetter::Get(0x3B54C0, 0x4A4000)))(this, Ident);
	}
};
auto& TheText = AddressSetter::GetRef<CText>(0xCF4CE8, 0xDFB4C8);