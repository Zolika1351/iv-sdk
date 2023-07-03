class CAnimManager
{
public:
	class AnimDescriptor;

	class AnimAssocDefinition
	{
	public:
		char pName[32];						// 00-20
		char pBlockName[32];				// 20-40
		void* pUnknown;						// 40-44
		AnimDescriptor* aAnimDesc;			// 44-48
		uint8_t pad[0x10];					// 48-58
	};
	VALIDATE_SIZE(AnimAssocDefinition, 0x58);
	VALIDATE_OFFSET(AnimAssocDefinition, pName, 0x0);
	VALIDATE_OFFSET(AnimAssocDefinition, pBlockName, 0x20);
	VALIDATE_OFFSET(AnimAssocDefinition, pUnknown, 0x40);
	VALIDATE_OFFSET(AnimAssocDefinition, aAnimDesc, 0x44);

	static inline auto& ms_aAnimAssocDefinitions = AddressSetter::GetRef<AnimAssocDefinition*>(0x1148F90, 0x127623C);
	static inline auto& ms_numAnimAssocDefinitions = AddressSetter::GetRef<int32_t>(0x1148F84, 0x1276230);

	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x531120, 0x78DFE0)))();
	}
	static void AddAnimAssocDefinition(int id, const char* pName, const char* pFile, uint32_t numAnims, const char** pAnimNames, AnimDescriptor* pAnimDescs, int unk1, int unk2, int unk3, bool unk4)
	{
		return ((void(__stdcall*)(int, const char*, const char*, uint32_t, const char**, AnimDescriptor*, int, int, int, bool))(AddressSetter::Get(0x530F70, 0x78DE00)))(id, pName, pFile, numAnims, pAnimNames, pAnimDescs, unk1, unk2, unk3, unk4);
	}
};
