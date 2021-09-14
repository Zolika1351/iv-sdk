enum eVehicleType
{
	VEHICLE_TYPE_AUTOMOBILE,
	VEHICLE_TYPE_BIKE,
	VEHICLE_TYPE_BOAT,
	VEHICLE_TYPE_TRAIN,
	VEHICLE_TYPE_HELI,
	VEHICLE_TYPE_PLANE,
};

struct tHandlingData;

struct tDoor
{
	uint32_t m_nBoneID;		// in the order from tVehicleStruct
	uint8_t pad;
	uint8_t m_nBoneIndex;	// group for detach, needs to be higher than 0
	uint8_t pad2[0x2E];
};
VALIDATE_SIZE(tDoor, 0x34);

struct tDoors
{
	tDoor m_sDoors[6];
};

class CVehicle : public CPhysical
{
public:
																		// 0000-0210
	uint8_t pad[0x9D];													// 0210-02AD
	uint8_t m_nPrimaryColor2;											// 02AD-02AE
	uint8_t m_nSecondaryColor2;											// 02AE-02AF
	uint8_t m_nTertiaryColor2;											// 02AF-02B0
	uint8_t m_nQuaternaryColor2;										// 02B0-02B1
	uint8_t pad1[0xB63];												// 02B1-0E14
	phInstGta* m_pVehicleFragInst;										// 0E14-0E18
	tHandlingData* m_pHandling;												// 0E18-0E1C
	struct {
		unsigned int m_bSmoothCompresn : 1;
		unsigned int m_bNone : 1;
		unsigned int m_bNpcAntiRoll : 1;
		unsigned int m_bNpcNeutralHandl : 1;
		unsigned int m_bNoHandbrake : 1;
		unsigned int m_bSteerRearwheels : 1;
		unsigned int m_bHbRearwheelSteer : 1;
		unsigned int m_bAltSteerOpt : 1;
		unsigned int m_bWheelFNarrow2 : 1;
		unsigned int m_bWheelFNarrow : 1;
		unsigned int m_bWheelFWide : 1;
		unsigned int m_bWheelFWide2 : 1;
		unsigned int m_bWheelRNarrow2 : 1;
		unsigned int m_bWheelRNarrow : 1;
		unsigned int m_bWheelRWide : 1;
		unsigned int m_bWheelRWide2 : 1;
		unsigned int m_bHydraulicGeom : 1;
		unsigned int m_bHydraulicInst : 1;
		unsigned int m_bHydraulicNone : 1;
		unsigned int m_bNosInst : 1;
		unsigned int m_bOffroadAbility : 1;
		unsigned int m_bOffroadAbility2 : 1;
		unsigned int m_bHalogenLights : 1;
		unsigned int m_bProcRearwheel1st : 1;
		unsigned int m_bUseMaxspLimit : 1;
		unsigned int m_bLowRider : 1;
		unsigned int m_bStreetRacer : 1;
		unsigned int m_bNone2 : 1;
		unsigned int m_bSwingingChassis : 1;
		unsigned int m_bOldPhysics : 1;
		unsigned int m_bNone3 : 1;
		unsigned int m_bNone4 : 1;
	}              m_nHandlingFlags; // 0E1C-0E20
	uint8_t pad2[0x150];												// 0E20-0F70
	struct
	{
		unsigned int pad : 2;
		unsigned int m_bCanBeVisiblyDamaged : 1;
		unsigned int pad2 : 29;
	} m_nVehicleFlags;													// 0F70-0F74
	uint8_t pad3[0x2C];													// 0F74-0FA0
	CPed* m_pDriver;													// 0FA0-0FA4
	CPed* m_pPassengers[8];												// 0FA4-0FC4
	uint8_t pad4[0x14];													// 0FC4-0FD8
	tDoors* m_pDoors;													// 0FD8-0FDC
	uint32_t m_nDoorCount;												// 0FDC-0FE0
	uint8_t pad5[0x4];													// 0FE0-0FE4
	uint8_t m_nPrimaryColor;											// 0FE4-0FE5
	uint8_t m_nSecondaryColor;											// 0FE5-0FE6
	uint8_t m_nTertiaryColor;											// 0FE6-0FE7
	uint8_t m_nQuaternaryColor;											// 0FE7-0FE8
	uint8_t pad6[0xD8];													// 0FE8-10C0
	uint8_t m_nMaxPassengers;											// 10C0-10C1
	uint8_t pad7[0x7];													// 10C1-10C8
	float m_fGasPedal;													// 10C8-10CC
	float m_fBrakePedal;												// 10CC-10D0
	float m_fSteerDesired;												// 10D0-10D4
	float m_fSteerBias;													// 10D4-10D8
	float m_fSteerActual;												// 10D8-10DC
	uint8_t pad8[0x4];													// 10DC-10E0
	uint8_t m_nCurrentGear;												// 10E0-10E2
	uint8_t pad9[0x1A];													// 10E2-10FC
	float m_fEngineHealth;												// 10FC-1100
	uint8_t pad10[0x8];													// 1100-1108
	uint8_t m_nCreatedBy;												// 1108-1109
	uint8_t pad11[0xB];													// 1109-1118
	uint8_t m_nRespotTimer;												// 1114-1116
	uint8_t pad12[0x2];													// 1116-1118
	float m_fDirtLevel;													// 1118-111C
	uint8_t pad13[0xC];													// 111C-1128
	float m_fPetrolTankHealth;											// 1128-112C
	uint8_t pad14[0xB4];												// 112C-11E0
	uint8_t m_nLights[0xD];												// 11E0-11ED
	uint8_t pad15[0x3];													// 11ED-11F0
	uint8_t m_nSirens[0x8];												// 11F0-11F8
	uint8_t pad16[0x134];												// 11F8-132C
	float m_fDeformationMult;											// 132C-1330
	float m_fLightMult;													// 1330-1334
	uint8_t pad17[0x8];													// 1334-133C
	uint32_t m_nHornCounter;											// 133C-1340
	uint8_t pad18[0x14];												// 1340-1354
	uint32_t m_nVehicleType;											// 1354-1358
	uint8_t pad19[0xBA8];												// 1358-20D0
	float m_fPlaneTurn;													// 1F00-1F04
	float m_fPlaneUpDown;												// 1F04-1F08
	float m_fPlaneRotate;												// 1F08-1F0C
	float m_fPlaneThrust;												// 1F0C-1F10
	uint8_t pad20[0x2C];												// 1F10-1F3C
	float m_fPlanePropSpeed;											// 1F3C-1F40
	uint8_t pad21[0x190];												// 1F40-20D0
	//0x260->0xB03 - gps voice (byte ptr, 0-4)
};
VALIDATE_SIZE(CVehicle, 0x20D0);
VALIDATE_OFFSET(CVehicle, m_nVehicleType, 0x1354);
VALIDATE_OFFSET(CVehicle, m_fLightMult, 0x1330);
VALIDATE_OFFSET(CVehicle, m_nHornCounter, 0x133C);
VALIDATE_OFFSET(CVehicle, m_nVehicleFlags, 0xF70);
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
VALIDATE_OFFSET(CVehicle, m_fPetrolTankHealth, 0x1128);
VALIDATE_OFFSET(CVehicle, m_fEngineHealth, 0x10FC);
VALIDATE_OFFSET(CVehicle, m_pHandling, 0xE18);
VALIDATE_OFFSET(CVehicle, m_pDoors, 0xFD8);
VALIDATE_OFFSET(CVehicle, m_nLights, 0x11E0);
VALIDATE_OFFSET(CVehicle, m_nSirens, 0x11F0);
VALIDATE_OFFSET(CVehicle, m_fPlaneTurn, 0x1F00);
VALIDATE_OFFSET(CVehicle, m_fPlaneUpDown, 0x1F04);
VALIDATE_OFFSET(CVehicle, m_fPlaneRotate, 0x1F08);
VALIDATE_OFFSET(CVehicle, m_fPlaneThrust, 0x1F0C);
VALIDATE_OFFSET(CVehicle, m_fPlanePropSpeed, 0x1F3C);