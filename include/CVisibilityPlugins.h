class CVisibilityPlugins
{
public:
	static inline float& m_pedLodDistanceHigh = AddressSetter::GetRef<float>(0xB36D8C, 0xB5C98C);
	static inline float& m_pedInCarLodDistanceHigh = AddressSetter::GetRef<float>(0xB36D90, 0xB5C990);
	static inline float& m_pedLodDistanceMed = AddressSetter::GetRef<float>(0xB36D94, 0xB5C994);
	static inline float& m_pedLodDistanceLow = AddressSetter::GetRef<float>(0xB36D98, 0xB5C998);
	static inline float& m_pedLodDistanceVlow = AddressSetter::GetRef<float>(0xB36D9C, 0xB5C99C);
	static inline float& m_pedLodDistanceSlod = AddressSetter::GetRef<float>(0xB36DA0, 0xB5C9A0); // all non-mission peds change their modelindex to superlod past this distance
	static inline float& m_carLodDistanceHigh = AddressSetter::GetRef<float>(0xB33A44, 0xB4149C);
	static inline float& m_carLodDistanceMed = AddressSetter::GetRef<float>(0xB33A48, 0xB414A0);

	static inline char*& sStipplePath = AddressSetter::GetRef<char*>(0x3DB970, 0x55A920);
};