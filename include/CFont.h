class CFont
{
public:
	static void Initialise()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x3FA730, 0x487460)))();
	}
	static void SetScale(float x, float y)
	{
		((void(__cdecl*)(float, float))(AddressSetter::Get(0x7B06B0, 0x753FD0)))(x, y);
	}
	static void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		((void(__cdecl*)(uint8_t, uint8_t, uint8_t, uint8_t))(AddressSetter::Get(0x7B3F60, 0x757880)))(r, g, b, a);
	}
};