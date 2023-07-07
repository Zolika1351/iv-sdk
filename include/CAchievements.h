class CAchievements
{
public:

	static void AwardAchievement(int id)
	{
		return ((void(__cdecl*)(int))(AddressSetter::Get(0x67D30, 0x2CC2D0)))(id);
	}
	static bool IsAchievementUnlocked(int id)
	{
		return ((bool(__cdecl*)(int))(AddressSetter::Get(0x67E30, 0x2CC3D0)))(id);
	}
};