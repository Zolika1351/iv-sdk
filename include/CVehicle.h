namespace rage { class grmShaderGroup; }

enum eVehicleType
{
	VEHICLE_TYPE_AUTOMOBILE,
	VEHICLE_TYPE_BIKE,
	VEHICLE_TYPE_BOAT,
	VEHICLE_TYPE_TRAIN,
	VEHICLE_TYPE_HELI,
	VEHICLE_TYPE_PLANE,
};

enum eVehicleCameraType
{
	VEHICLE_CAMERA_AUTOMOBILE,
	VEHICLE_CAMERA_BIKE,
	VEHICLE_CAMERA_HELI,
	VEHICLE_CAMERA_PLANE,
	VEHICLE_CAMERA_BOAT,

	VEHICLE_CAMERA_BIKE_E1 = 7,
	VEHICLE_CAMERA_HELI_E2,
};

enum eVehicleCreatedBy
{
	RANDOM_VEHICLE = 1,
	MISSION_VEHICLE = 2,
	PARKED_VEHICLE = 3,
	PERMANENT_VEHICLE = 4,
};

struct tHandlingData;

class CVehicleDoor {
public:
	uint32_t m_nBoneID;					// 00-04 in the order from tVehicleStruct
	uint8_t _f4;						// 04-05
	uint8_t m_nGroupID;					// 05-06 group for detach, needs to be higher than 0
	uint8_t _f6[0x2];					// 06-08 0xcd
	float _f8;							// 08-0c
	uint8_t _fc[0x4];					// 0c-10
	uint8_t _f10;						// 10-11
	uint8_t _f11;						// 11-12 1 = closed, 4 = open?
	uint8_t _f12;						// 12-13
	uint8_t _f13;						// 13-14 door is moved??
	float _f14;							// 14-18
	float _f18;							// 18-1c
	float _f1c;							// 1c-20
	uint8_t _f20[0x4];					// 20-24
	float _f24;							// 24-28
	float _f28;							// 28-2c
	uint8_t _f2c[0x8];					// 2c-34

};
VALIDATE_SIZE(CVehicleDoor, 0x34);
VALIDATE_OFFSET(CVehicleDoor, m_nGroupID, 0x5);


class CVehicleWheel {
public:
	uint32_t m_nBoneID;					// 000-004 in the order from tVehicleStruct
	uint16_t m_nGroupID;				// 004-006 group for detach, needs to be higher than 0
	uint16_t pad;						// 006-008 0xcdcd
	float m_fRadius;					// 008-00C 
	float m_fDiscRadius;				// 00C-010 from veh.ide
	float m_fMargin;					// 010-014 margin or AABB * 2 
	uint32_t _f14;						// 014-018
	float _f18;							// 018-01C same values ​​for l and r wheels
	float _f1c;							// 01C-020 CurvedEdges unk_F?
	float _f20;							// 020-024 Z for suspension?
	float _f24;							// 024-028 has to do with suspension or wheel stability
	float _f28;							// 028-02C same values ​​for l and r wheels
	float _f2c;							// 02C-030
	CVector_pad matrix_right;			// 030-040
	CVector_pad matrix_at;				// 040-050
	CVector _f50;						// 050-05C duplicates position
	uint32_t _f5c;						// 05C-060
	CVector m_vPosition;				// 060-06C
	uint32_t _f6c;						// 06C-070 cd
	float _f70;							// 070-074
	float _f74;							// 074-078
	float _f78;							// 078-07C z position? y angle?
	float m_fRotationX;					// 07C-080
	float m_fSpeed;						// 080-084
	float m_fSpeed2;					// 084-088 duplicate
	float _f88;							// 088-08C has to do with wheel speed
	uint8_t _f8c[0x4];					// 08C-090
	CVector_pad _f90;					// 090-0A0
	CVector_pad _fa0;					// 0A0-0B0
	CVector_pad _fb0;					// 0B0-0C0
	uint8_t _fc0[0x8];					// 0C0-0C8
	float _fc8;							// 0C8-0CC
	uint8_t _fcc[0x4];					// 0CC-0D0
	uint8_t _fd0[0x10];					// 0D0-0E0
	float _fe0;							// 0E0-0E4
	float _fe4;							// 0E4-0E8
	uint8_t _fe8[0x8];					// 0E8-0F0
	float _ff0;							// 0F0-0F4 has to do with suspension. 0 if the wheel is in the air
	float _ff4;							// 0F4-0F8 has to do with suspension. 0 if the wheel is in the air
	float _ff8;							// 0F8-0FC has to do with suspension. 0 if the wheel is in the air
	uint32_t _ffс;						// 0FC-100 0xcdcdcdcd
	float _f100;						// 100-104
	float _f104;						// 104-108
	float _f108;						// 108-10C has to do with suspension. 0 if the wheel is in the air
	float _f10c;						// 10C-110 has to do with suspension. 0 if the wheel is in the air
	float _f110;						// 110-114 has to do with suspension. 0 if the wheel is in the air
	float _f114;						// 114-118
	float _f118;						// 118-11C
	float _f11c;						// 11C-120 always -1
	float _f120;						// 120-124
	float _f124;						// 124-128
	uint8_t _f128[0x8];					// 128-130
	float m_fTrackIntensity;			// 130-134
	float _f134;						// 134-138 brake mult?
	float _f138;						// 138-13C related to wheel steering
	float m_fRotationZ;					// 13C-140 rotation in z-axis.
	float _f140;						// 140-144
	float _f144;						// 144-148
	float _f148;						// 148-14C
	float m_fRotationZ2;				// 14C-150
	float _f150;						// 150-154
	float _f154;						// 154-158
	float _f158;						// 158-15C
	float m_fHealth;					// 15C-160
	float m_fTireHealth;				// 160-164
	struct
	{
		unsigned int bSpringsAreActive : 1;			// 0 if in the air
		unsigned int bNotInAir : 1;					// 0 if in the air
		unsigned int bGasPedalPressed : 1;
		unsigned int bWheelOnFire : 1;
		unsigned int _f4 : 1;
		unsigned int _f5 : 1;
		unsigned int _f6 : 1;
		unsigned int _f7 : 1;
		unsigned int _f8 : 1;
		unsigned int _f9 : 1;
		unsigned int _fa : 1;
		unsigned int _fb : 1;
		unsigned int bIsRearWheel : 1;				// this can make a double track for the front wheel and turn it off for the rear. Also if == 0 the handbrake for this wheel does not work
		unsigned int bFrontWheelSteer : 1;
		unsigned int bRearWheelSteer : 1;
		unsigned int bDriveWheel : 1;
		unsigned int bRightWheelSuspension : 1;		// 0 for 0 for wheels that have an axle (transmission_f, transmission_r or transmission_m)
		unsigned int bLeftWheelSuspension : 1;		// 0 for 0 for wheels that have an axle (transmission_f, transmission_r or transmission_m)
		unsigned int _f12 : 1;
		unsigned int _f13 : 1;
		unsigned int _f14 : 1;
		unsigned int _f15 : 1;
		unsigned int bMirrorWheel : 1;
		unsigned int _f17 : 1;
		unsigned int bScaleWheelByCollision : 1;	// for example, the rear wheel airtug is larger than the front
		unsigned int _f19 : 1;
		unsigned int bRaiseSuspension1 : 1;
		unsigned int bRaiseSuspension2 : 1;
		unsigned int _f1c : 1;
		unsigned int _f1d : 1;
		unsigned int _f1e : 1;
		unsigned int _f1f : 1;
	} m_nFlags;							// 164-168
	uint8_t _f168[0x8];					// 168-170
};
VALIDATE_SIZE(CVehicleWheel, 0x170);
VALIDATE_OFFSET(CVehicleWheel, m_nGroupID, 0x4);
VALIDATE_OFFSET(CVehicleWheel, m_fRadius, 0x8);
VALIDATE_OFFSET(CVehicleWheel, m_fDiscRadius, 0xc);
VALIDATE_OFFSET(CVehicleWheel, m_fMargin, 0x10);
VALIDATE_OFFSET(CVehicleWheel, matrix_right, 0x30);
VALIDATE_OFFSET(CVehicleWheel, matrix_at, 0x40);
VALIDATE_OFFSET(CVehicleWheel, matrix_at, 0x40);
VALIDATE_OFFSET(CVehicleWheel, m_vPosition, 0x60);
VALIDATE_OFFSET(CVehicleWheel, m_fRotationX, 0x7c);
VALIDATE_OFFSET(CVehicleWheel, m_fSpeed, 0x80);
VALIDATE_OFFSET(CVehicleWheel, m_fSpeed2, 0x84);
VALIDATE_OFFSET(CVehicleWheel, m_fTrackIntensity, 0x130);
VALIDATE_OFFSET(CVehicleWheel, m_fRotationZ, 0x13c);
VALIDATE_OFFSET(CVehicleWheel, m_fRotationZ2, 0x14c);
VALIDATE_OFFSET(CVehicleWheel, m_fHealth, 0x15c);
VALIDATE_OFFSET(CVehicleWheel, m_fTireHealth, 0x160);
VALIDATE_OFFSET(CVehicleWheel, m_nFlags, 0x164);


class CCustomShaderEffectVehicleFX : public CCustomShaderEffectBase
{
public:
	char pad[0x10];														// 000-010
	//4 - E0
	//5 - 02
	//6 - CD
	//7 - CD
	//8 - CDCDCDCD
	//C - CDCDCDCD
	CRGBFloat m_fPrimaryColor;											// 010-01C
	CRGBA m_nPrimaryColor;												// 01C-020
	CRGBFloat m_fSecondaryColor;										// 020-02C
	CRGBA m_nSecondaryColor;											// 02C-030
	CRGBFloat m_fTertiaryColor;											// 030-03C independent of spec color
	CRGBA m_nTertiaryColor;												// 03C-040
	CRGBFloat m_fQuaternaryColor;										// 040-04C
	CRGBA m_nQuaternaryColor;											// 04C-050
	CRGBFloat m_fQuinaryColor;											// 050-04C everything non colorable
	CRGBA m_nQuinaryColor;												// 05C-060
	CRGBFloat m_fSpecularColor;											// 060-06C
	CRGBA m_nSpecularColor;												// 06C-070
	rage::grmShaderGroup* m_pShaderGroup;								// 070-074
	float m_fDirtLevel;													// 074-078
	uint8_t m_bWrecked;													// 078-07C
	uint8_t pad6[0x5C];													// 07C-0D8
	int32_t m_nLivery;													// 0D8-0DC
};
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fPrimaryColor, 0x10);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fSecondaryColor, 0x20);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fTertiaryColor, 0x30);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fQuaternaryColor, 0x40);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fQuinaryColor, 0x50);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fSpecularColor, 0x60);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_nLivery, 0xD8);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_fDirtLevel, 0x74);
VALIDATE_OFFSET(CCustomShaderEffectVehicleFX, m_bWrecked, 0x78);

class CVehicle : public CPhysical
{
public:
																		// 0000-0210
	uint8_t pad[0x9D];													// 0210-02AD
	/*
	pad[0] = integer size 4
	pad[4] = cd size 60
	pad[64] = byte size 1
	pad[65] = cd size 15
	pad[80] = int size 2
	pad[82] = cd size 1
	pad[83] = int size 3
	pad[86] = cd size 10
	pad[96] = float
	pad[100] = float
	pad[104] = float
	pad[108] = 
	pad[112] = float
	pad[116] = float
	pad[120] = float
	pad[124] = cd size 4
	pad[128] = float
	pad[132] = float
	pad[136] = float
	pad[140] = poiter?
	pad[144] = float. posX?
	pad[148] = float. posY?
	pad[152] = float. posZ?
	pad[156] = 
	*/
	uint8_t m_nPrimaryColor2;											// 02AD-02AE
	uint8_t m_nSecondaryColor2;											// 02AE-02AF
	uint8_t m_nTertiaryColor2;											// 02AF-02B0
	uint8_t m_nQuaternaryColor2;										// 02B0-02B1
	uint8_t pad1[0x3D7];												// 02B1-0688
	/*
	pad[3] float
	pad[7] float zero
	pad[11] float
	pad[15] float zero
	pad[19] float
	pad[23] cd size 4
	pad[17] float zero
	pad[31] float
	pad[35] int size 8
	pad[43] float
	pad[47] float zero
	pad[51] float
	pad[55] float zero
	pad[59] float
	pad[63] cd size 4
	pad[67] float zero
	pad[71] float
	pad[75] int 4
	pad[78] cd size 1
	pad[79] float zero
	pad[83] padding. cd, 0 or 1. size 884
	pad[967] float
	pad[971] float
	pad[975] float
	pad[979] float zero
	*/
	float m_fEngineRPM;													// 0688-068C
	uint8_t pad1_[0x788];												// 068C-0E14
	phInstGta* m_pVehicleFragInst;										// 0E14-0E18
	tHandlingData* m_pHandling;											// 0E18-0E1C
	struct {
		unsigned int bSmoothCompresn : 1;
		unsigned int bNone : 1;
		unsigned int bNpcAntiRoll : 1;
		unsigned int bNpcNeutralHandl : 1;
		unsigned int bNoHandbrake : 1;
		unsigned int bSteerRearwheels : 1;
		unsigned int bHbRearwheelSteer : 1;
		unsigned int bAltSteerOpt : 1;
		unsigned int bWheelFNarrow2 : 1;
		unsigned int bWheelFNarrow : 1;
		unsigned int bWheelFWide : 1;
		unsigned int bWheelFWide2 : 1;
		unsigned int bWheelRNarrow2 : 1;
		unsigned int bWheelRNarrow : 1;
		unsigned int bWheelRWide : 1;
		unsigned int bWheelRWide2 : 1;
		unsigned int bHydraulicGeom : 1;
		unsigned int bHydraulicInst : 1;
		unsigned int bHydraulicNone : 1;
		unsigned int bNosInst : 1;
		unsigned int bOffroadAbility : 1;
		unsigned int bOffroadAbility2 : 1;
		unsigned int bHalogenLights : 1;
		unsigned int bProcRearwheel1st : 1;
		unsigned int bUseMaxspLimit : 1;
		unsigned int bLowRider : 1;
		unsigned int bStreetRacer : 1;
		unsigned int bNone2 : 1;
		unsigned int bSwingingChassis : 1;
		unsigned int bOldPhysics : 1;
		unsigned int bNone3 : 1;
		unsigned int bNone4 : 1;
	}              m_nHandlingFlags;									// 0E1C-0E20
	uint8_t pad2[0x144];												// 0E20-0F64
	struct
	{
		unsigned int _f0 : 1;
		unsigned int _f1 : 1;
		unsigned int _f2 : 1;
		unsigned int bEngineOn : 1;
		unsigned int bEngineStarting : 1;
		unsigned int _f5 : 1;
		unsigned int _f6 : 1;
		unsigned int bIsHandbrakeOn : 1;
		unsigned int bLightsOn : 1;
		unsigned int bFreebies : 1;
		unsigned int _fa : 1;
		unsigned int _fb : 1;
		unsigned int bBigVehicle : 1;
		unsigned int _fd : 1;
		unsigned int _fe : 1;
		unsigned int _ff : 1;
		unsigned int bTakesLessDamage : 1;
		unsigned int bHasBeenOwnedByPlayer : 1;
		unsigned int bNeedsToBeHotWired : 1;
		unsigned int _f14 : 1;
		unsigned int _f15 : 1;
		unsigned int _f16 : 1;
		unsigned int _f17 : 1;
		unsigned int _f18 : 1;
		unsigned int bPartOfConvoy : 1;
		unsigned int bHeliStabiliser : 1;
		unsigned int _f1b : 1;
		unsigned int bIsDead : 1;
		unsigned int bCanBurstTyres : 1;
		unsigned int _f1d : 1;
		unsigned int _f1e : 1;
		unsigned int _f1f : 1;
	} m_nVehicleFlags;													// 0F64-0F68
	struct
	{
		unsigned int _f0 : 1;
		unsigned int _f1 : 1;
		unsigned int _f2 : 1;
		unsigned int _f3 : 1;
		unsigned int _f4 : 1;
		unsigned int bAlwaysCreateSkids : 1;
		unsigned int bCanBeTargetted : 1;
		unsigned int _f7 : 1;
		unsigned int bCanBeTargetedByHSmmissile : 1;
		unsigned int bLongLight : 1;
		unsigned int _fa : 1;
		unsigned int _fb : 1;
		unsigned int bSirenSwitchedOn : 1;
		unsigned int bSirenRelated : 1; // ??
		unsigned int _fe : 1;
		unsigned int _ff : 1;
		unsigned int _f10 : 1;
		unsigned int _f11 : 1;
		unsigned int _f12 : 1;
		unsigned int bBikeRiderWillPutDownFootWhenStopped : 1;
		unsigned int bProvideCover : 1;
		unsigned int _f15 : 1;
		unsigned int _f16 : 1;
		unsigned int bVehicleIsConsideredByPlayer : 1;
		unsigned int bPetrolTankWeakpoint : 1;
		unsigned int _f19 : 1;
		unsigned int bCarBeenResprayed : 1;
		unsigned int _f1b : 1;
		unsigned int _f1c : 1;
		unsigned int _f1d : 1;
		unsigned int _f1e : 1;
		unsigned int _f1f : 1;
	} m_nVehicleFlags2;													// 0F68-0F6C
	struct
	{
		unsigned int bRightIndicator : 1;
		unsigned int bHazardLights : 1;
		unsigned int bIndicatorLights : 1;
		unsigned int _f3 : 1;
		unsigned int bInteriorLights : 1;
		unsigned int bVehicleIsHot : 1;
		unsigned int _f6 : 1;
		unsigned int _f7 : 1;
		unsigned int _f8 : 1;
		unsigned int _f9 : 1;											// -
		unsigned int bDeleted : 1;
		unsigned int _fb : 1;
		unsigned int bTiresIsDestroyed : 1;
		unsigned int bPretendOccupants : 1;
		unsigned int _fe : 1;											// respawn passengers and Niko??
		unsigned int _ff : 1;											// sometimes turns on when driving in reverse / when braking
		unsigned int _f10 : 1;
		unsigned int _f11 : 1;
		unsigned int _f12 : 1;
		unsigned int _f13 : 1;
		unsigned int _f14 : 1;
		unsigned int bHaveSiren : 1;
		unsigned int bPoliceFocusWillTrackCar : 1;
		unsigned int _f17 : 1;
		unsigned int _f18 : 1;
		unsigned int bSetBlipThrottleRandomly : 1;
		unsigned int _f1a : 1;
		unsigned int bInCutscene : 1;
		unsigned int _f1c : 1;
		unsigned int bPoliceVehicle : 1;
		unsigned int bEmergencyServicesVehicle : 1;
		unsigned int _f1f : 1;
	} m_nVehicleFlags3;													// 0F6C-0F70
	struct
	{
		unsigned int _f0 : 1;
		unsigned int _f1 : 1;
		unsigned int bCanBeVisiblyDamaged : 1;
		unsigned int bHasStrongAxles : 1;
		unsigned int _f4 : 1;
		unsigned int _f5 : 1;
		unsigned int _f6 : 1;
		unsigned int _f7 : 1;
		unsigned int _f8 : 1;
		unsigned int _f9 : 1;
		unsigned int bNitro : 1;
		unsigned int bOldCarExhaustFX : 1;								// sabre2, emperor2 etc.
		unsigned int _fc : 1;
		unsigned int _fd : 1;
		unsigned int _fe : 1;
		unsigned int _ff : 1;
		unsigned int _f10 : 1;
		unsigned int _f11 : 1;
		unsigned int _f12 : 1;
		unsigned int _f13 : 1;
		unsigned int _f14 : 1;
		unsigned int _f15 : 1;
		unsigned int _f16 : 1;
		unsigned int _f17 : 1;
		unsigned int _f18 : 1;
		unsigned int _f19 : 1;
		unsigned int _f1a : 1;
		unsigned int _f1b : 1;
		unsigned int _f1c : 1;
		unsigned int _f1d : 1;
		unsigned int _f1e : 1;
		unsigned int _f1f : 1;
	} m_nVehicleFlags4;													// 0F70-0F74
	uint8_t pad4[0x2C];													// 0F74-0FA0
	CPed* m_pDriver;													// 0FA0-0FA4
	CPed* m_pPassengers[8];												// 0FA4-0FC4
	uint8_t pad5[0xC];													// 0FC4-0FD0
	CVehicleWheel* m_pWheels;											// 0FD0-0FD4
	uint32_t m_nWheelCount;												// 0FD4-0FD8
	CVehicleDoor* m_pDoors;												// 0FD8-0FDC
	uint32_t m_nDoorCount;												// 0FDC-0FE0
	struct
	{
		unsigned int _f0 : 1;
		unsigned int _f1 : 1;
		unsigned int _f2 : 1;
		unsigned int _f3 : 1;
		unsigned int _f4 : 1;
		unsigned int _f5 : 1;
		unsigned int _f6 : 1;
		unsigned int _f7 : 1;
		unsigned int _f8 : 1;
		unsigned int _f9 : 1;
		unsigned int _fa : 1;
		unsigned int _fb: 1;
		unsigned int _fc : 1;
		unsigned int _fd : 1;
		unsigned int _fe : 1;
		unsigned int _ff : 1;
		unsigned int bAbs : 1;
		unsigned int bAbsAlt : 1;
		unsigned int _f12 : 1;
		unsigned int _f13 : 1;
		unsigned int _f14 : 1;
		unsigned int _f15 : 1;
		unsigned int _f16 : 1;
		unsigned int _f17 : 1;
		unsigned int _f18 : 1;
		unsigned int _f19 : 1;
		unsigned int _f1a : 1;
		unsigned int _f1b : 1;
		unsigned int _f1c : 1;
		unsigned int _f1d : 1;
		unsigned int _f1e : 1;
		unsigned int _f1f : 1;
	} m_nAbsFlags;														// 0FE0-0FE4
	uint8_t m_nPrimaryColor;											// 0FE4-0FE5
	uint8_t m_nSecondaryColor;											// 0FE5-0FE6
	uint8_t m_nTertiaryColor;											// 0FE6-0FE7
	uint8_t m_nQuaternaryColor;											// 0FE7-0FE8
	uint8_t pad7[0xD8];													// 0FE8-10C0
	uint8_t m_nMaxPassengers;											// 10C0-10C1
	uint8_t pad8[0x7];													// 10C1-10C8
	float m_fGasPedal;													// 10C8-10CC
	float m_fBrakePedal;												// 10CC-10D0
	float m_fSteerDesired;												// 10D0-10D4
	float m_fSteerBias;													// 10D4-10D8
	float m_fSteerActual;												// 10D8-10DC
	uint8_t pad9[0x4];													// 10DC-10E0
	uint16_t m_nCurrentGear;											// 10E0-10E2
	uint16_t _f10e2;													// 10E2-10E4
	float m_fEngineRevs;												// 10E4-10E8
	float _f10e8;														// 10E8-10EC
	float _f10ec;														// 10EC-10F0
	float _f10f0;														// 10F0-10F4
	float _f10f4;														// 10F4-10F8
	uint32_t _f10f8;													// 10F8-10FC
	float m_fEngineHealth;												// 10FC-1100
	float _f1100;														// 1100-1104
	float _f1104;														// 1104-1108
	uint8_t m_nCreatedBy;												// 1108-1109
	uint8_t pad12[0xB];													// 1109-1118
	uint8_t m_nRespotTimer;												// 1114-1116
	uint8_t pad13[0x2];													// 1116-1118
	float m_fDirtLevel;													// 1118-111C
	uint8_t pad14[0xC];													// 111C-1128
	float m_fPetrolTankHealth;											// 1128-112C
	uint8_t pad15[0xB4];												// 112C-11E0
	uint8_t m_nLights[0xD];												// 11E0-11ED
	uint8_t pad16[0x3];													// 11ED-11F0
	uint8_t m_nSirens[0x8];												// 11F0-11F8
	uint8_t pad17[0x128];												// 11F8-1320
	uint32_t m_nDoorLock;												// 1320-1324
	uint8_t pad18[0x8];													// 1324-132C
	float m_fDeformationMult;											// 132C-1330
	float m_fLightMult;													// 1330-1334
	uint8_t pad19[0x8];													// 1334-133C
	uint32_t m_nHornCounter;											// 133C-1340
	uint8_t pad20[0x14];												// 1340-1354
	uint32_t m_nVehicleType;											// 1354-1358
	uint8_t pad21[0x16C];												// 1358-14C4
	struct
	{
		unsigned int pad : 3;
		unsigned int bNotDamagedUpsideDown : 1; // unused
		unsigned int pad2 : 28;
	} m_nAutomobileFlags;												// 14C4-14C8
	uint8_t pad22[0xA38];												// 14C8-1F00
	float m_fPlaneTurn;													// 1F00-1F04
	float m_fPlaneUpDown;												// 1F04-1F08
	float m_fPlaneRotate;												// 1F08-1F0C
	float m_fPlaneThrust;												// 1F0C-1F10
	uint8_t pad23[0x2C];												// 1F10-1F3C
	float m_fPlanePropSpeed;											// 1F3C-1F40
	uint8_t pad24[0x190];												// 1F40-20D0
	//0x260->0xB03 - gps voice (byte ptr, 0-4)

	void Fix()
	{
		((void(__thiscall*)(CVehicle*))(*(void***)this)[101])(this);
	}

	void SetRemap(int id)
	{
		((void(__thiscall*)(CVehicle*, int))(AddressSetter::Get(0x5C7580, 0x4F14F0)))(this, id);
	}
	int GetRemapIndex()
	{
		return ((int(__thiscall*)(CVehicle*))(AddressSetter::Get(0x5C7560, 0x4F14D0)))(this);
	}
	void MakeDirty()
	{
		((void(__thiscall*)(CVehicle*))(AddressSetter::Get(0x5D3E90, 0x4FE1E0)))(this);
	}
	void GetVehicleLightsStatus()
	{
		((void(__thiscall*)(CVehicle*))(AddressSetter::Get(0x5C63D0, 0x4F0340)))(this);
	}
	// returns VehicleStruct part enum
	int GetSeatPartId(int seat)
	{
		return ((int(__cdecl*)(CVehicle*, int))(AddressSetter::Get(0x5C6EF0, 0x4F0E60)))(this, seat);
	}
	// see eVehicleCameraType
	bool GetCameraType(int* type)
	{
		return ((bool(__stdcall*)(CVehicle*, int*))(AddressSetter::Get(0x5D68F0, 0x679B50)))(this, type);
	}
	void ProcessRespot(float delta)
	{
		((void(__thiscall*)(CVehicle*, float))(AddressSetter::Get(0x5D3A10, 0x4FDD60)))(this, delta);
	}
	void ProcessAirControl(void* unk)
	{
		((void(__thiscall*)(CVehicle*, void*))(AddressSetter::Get(0x7FD450, 0x651580)))(this, unk);
	}

	static float HeightAboveCeiling(float height, int flightModel)
	{
		return ((float(__stdcall*)(float, int))(AddressSetter::Get(0x5C6100, 0x4F0070)))(height, flightModel);
	}
	static bool UsesSiren(int32_t id)
	{
		return ((bool(__cdecl*)(int32_t))(AddressSetter::Get(0x5C5F50, 0x4EFEC0)))(id);
	}
};
VALIDATE_SIZE(CVehicle, 0x20D0);
VALIDATE_OFFSET(CVehicle, m_fEngineRPM, 0x688);
VALIDATE_OFFSET(CVehicle, m_nDoorLock, 0x1320);
VALIDATE_OFFSET(CVehicle, m_nVehicleType, 0x1354);
VALIDATE_OFFSET(CVehicle, m_fLightMult, 0x1330);
VALIDATE_OFFSET(CVehicle, m_nHornCounter, 0x133C);
VALIDATE_OFFSET(CVehicle, m_nVehicleFlags, 0xF64);
VALIDATE_OFFSET(CVehicle, m_nVehicleFlags2, 0xF68);
VALIDATE_OFFSET(CVehicle, m_nVehicleFlags3, 0xF6C);
VALIDATE_OFFSET(CVehicle, m_nVehicleFlags4, 0xF70);
VALIDATE_OFFSET(CVehicle, m_nCreatedBy, 0x1108);
VALIDATE_OFFSET(CVehicle, m_pVehicleFragInst, 0xE14);
VALIDATE_OFFSET(CVehicle, m_nRespotTimer, 0x1114);
VALIDATE_OFFSET(CVehicle, m_fDirtLevel, 0x1118);
VALIDATE_OFFSET(CVehicle, m_fDeformationMult, 0x132C);
VALIDATE_OFFSET(CVehicle, m_pDriver, 0xFA0);
VALIDATE_OFFSET(CVehicle, m_nPrimaryColor, 0xFE4);
VALIDATE_OFFSET(CVehicle, m_nMaxPassengers, 0x10C0);
VALIDATE_OFFSET(CVehicle, m_fGasPedal, 0x10C8);
VALIDATE_OFFSET(CVehicle, m_nCurrentGear, 0x10E0);
VALIDATE_OFFSET(CVehicle, m_fEngineHealth, 0x10FC);
VALIDATE_OFFSET(CVehicle, m_fPetrolTankHealth, 0x1128);
VALIDATE_OFFSET(CVehicle, m_pHandling, 0xE18);
VALIDATE_OFFSET(CVehicle, m_pDoors, 0xFD8);
VALIDATE_OFFSET(CVehicle, m_fEngineRevs, 0x10E4);
VALIDATE_OFFSET(CVehicle, m_nLights, 0x11E0);
VALIDATE_OFFSET(CVehicle, m_nSirens, 0x11F0);
VALIDATE_OFFSET(CVehicle, m_fPlaneTurn, 0x1F00);
VALIDATE_OFFSET(CVehicle, m_fPlaneUpDown, 0x1F04);
VALIDATE_OFFSET(CVehicle, m_fPlaneRotate, 0x1F08);
VALIDATE_OFFSET(CVehicle, m_fPlaneThrust, 0x1F0C);
VALIDATE_OFFSET(CVehicle, m_fPlanePropSpeed, 0x1F3C);
VALIDATE_OFFSET(CVehicle, m_nAbsFlags, 0xFE0);