enum eCamType
{
	CAM_SKELETON = 0,
	CAM_FOLLOW_PED = 1,
	CAM_FOLLOW_VEHICLE = 2,
	CAM_INTERP = 3,
	CAM_SHAKE = 4,
	CAM_FINAL = 5,
	CAM_SCRIPT = 6,
	CAM_GAME = 7,
	CAM_TRANS = 8,
	CAM_AIM_WEAPON = 9,
	CAM_BUSTED = 10,
	CAM_PHOTO = 11,
	CAM_IDLE = 12,
	CAM_2_PLAYER = 13,
	CAM_SCRIPTED = 14,
	CAM_CUTSCENE = 15,
	CAM_WASTED = 16,
	CAM_1ST_PERSON = 17,
	CAM_2_PLAYER_VEH = 18,
	CAM_AIM_WEAPON_VEH = 19,
	CAM_VIEWPORTS = 20,
	CAM_HISTORY = 21,
	CAM_CINEMATIC = 22,
	CAM_CINEMATIC_HELI_CHASE = 23,
	CAM_CINEMATIC_CAM_MAN = 24,
	CAM_SPLINE = 25,
	CAM_CINEMATOGRAPHY = 26,
	CAM_FPS_WEAPON = 27,
	CAM_FIRE_TRUCK = 28,
	CAM_RADAR = 29,
	CAM_WEAPON_AIMING = 30,
	CAM_ANIMATED = 31,
	CAM_INTERMEZZO = 32,
	CAM_VIEW_SEQ = 33,
	CAM_VIEWFIND = 34,
	CAM_PLAYER_SETTINGS = 35,
	CAM_CINEMATIC_VEH_OFFSET = 36,
	CAM_REPLAY = 37,
	CAM_FREE = 38,
	CAM_DEBUG = 39,
	CAM_MARKET = 40,
	CAM_SECTOR = 41,
};

class CCam
{
public:
	uint8_t pad[0x10];													// 000-010
	CMatrix m_mMatrix;													// 010-050
	uint8_t pad2[0x10];													// 050-060
	float m_fFOV;														// 060-064
	float m_fNearZ;														// 064-068
	float m_fFarZ;														// 068-06C
	float m_fNearDOF;													// 06C-06C
	float m_fFarDOF;													// 070-074
	uint8_t pad3[0xCC];													// 074-140

	CCam* GetCamOfType(int type, int unk)
	{
		return ((CCam*(__thiscall*)(CCam*, int, int))(AddressSetter::Get(0x5AD2D0, 0x5DEEB0)))(this, type, unk);
	}
	CCam* Activate()
	{
		return ((CCam * (__thiscall*)(CCam*))(AddressSetter::Get(0x5ACC00, 0x5DE7E0)))(this);
	}
	bool Process()
	{
		return ((bool(__thiscall*)(CCam*))(*(void***)this)[4])(this);
	}
};
VALIDATE_SIZE(CCam, 0x140); // probably?
VALIDATE_OFFSET(CCam, m_mMatrix, 0x10);
VALIDATE_OFFSET(CCam, m_fFOV, 0x60);
VALIDATE_OFFSET(CCam, m_fNearZ, 0x64);
VALIDATE_OFFSET(CCam, m_fFarZ, 0x68);
VALIDATE_OFFSET(CCam, m_fNearDOF, 0x6C);
VALIDATE_OFFSET(CCam, m_fFarDOF, 0x70);

class CCamFollowVehicle : public CCam
{
public:
																		// 000-140
	uint8_t pad[0x40];													// 140-180
	float m_fTargetFOV;													// 180-184
};
VALIDATE_OFFSET(CCamFollowVehicle, m_fTargetFOV, 0x180);