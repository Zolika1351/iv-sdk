class CVisibilityPlugins
{
public:
	static inline float& m_pedLodDistanceHigh = *(float*)nullptr;
	static inline float& m_pedInCarLodDistanceHigh = *(float*)nullptr;
	static inline float& m_pedLodDistanceMed = *(float*)nullptr;
	static inline float& m_pedLodDistanceLow = *(float*)nullptr;
	static inline float& m_pedLodDistanceVlow = *(float*)nullptr;
	static inline float& m_pedLodDistanceSlod = *(float*)nullptr; // all non-mission peds change their modelindex to superlod past this distance
	static inline float& m_carLodDistanceHigh = *(float*)nullptr;
	static inline float& m_carLodDistanceMed = *(float*)nullptr;
};