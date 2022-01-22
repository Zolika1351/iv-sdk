struct tHandlingData
{
	char m_sName[16];											// 000-010
	float m_fMass;												// 010-014
	float m_fDragMult;											// 014-018
	uint8_t pad[0x8];											// 018-020 always 0
	CVector_pad m_vCenterOfMass;								// 020-02C
	uint32_t m_nPercentSubmerged;								// 030-034
	float m_fPercentSubmerged;									// 034-038 100.0 / m_nPercentSubmerged
	float m_fDriveBiasF;										// 038-03C
	float m_fDriveBiasR;										// 03C-040
	uint32_t m_nDriveGears;										// 040-044
	float m_fDriveForce;										// 044-048
	float m_fDriveInertia;										// 048-04C
	float m_fV_times12;											// 04C-050 m_fV * 1.2
	float m_fV;													// 050-054
	float m_fV_gearR;											// 054-058
	float m_fV_gear1;											// 058-05C
	float m_fV_gear2;											// 05C-060
	float m_fV_gear3;											// 060-064
	float m_fV_gear4;											// 064-068
	float m_fV_gear5;											// 068-06C
	float m_fV_gear6;											// 06C-070
	float m_fV_gear7;											// 070-074
	float m_fBrakeForce;										// 074-078
	float m_fBrakeForceF;										// 078-07C
	float m_fBrakeForceR;										// 07C-080
	float m_fHBias;												// 080-084
	float m_fSteeringLock;										// 084-088
	float m_fSteeringLockPercent;								// 088-08C 1.0 / m_fSteeringLock
	float m_fTractionCurveMax;									// 08C-090
	float m_fTractionCurveMaxPercent;							// 090-094 1.0 / m_fTractionCurveMaxPercent
	float m_fTractionCurveMin;									// 094-098
	float m_fTractionCurvePercent;								// 098-09C
	float m_fTractionCurveLateral;								// 09C-0A0
	float m_fTractionCurveLateralPercent;						// 0A0-0A4 1.0 / m_fTractionCurveLateral
	float m_fTractionSpringDeltaMax;							// 0A4-0A8
	float m_fTractionSpringDeltaMaxPercent;						// 0A8-0AC 1.0 / m_fTractionSpringDeltaMax
	float m_fTractionBiasF;										// 0AC-0B0
	float m_fTractionBiasR;										// 0B0-0B4
	float m_fSuspensionForce;									// 0B4-0B8
	float m_fSuspensionCompDamp;								// 0B8-0BC
	float m_fSuspensionReboundDamp;								// 0BC-0C0
	float m_fSuspensionUpperLimit;								// 0C0-0C4
	float m_fSuspensionLowerLimit;								// 0C4-0C8
	float m_fSuspensionRaise;									// 0C8-0CC
	float m_fSuspensionBiasF;									// 0CC-0D0
	float m_fSuspensionBiasR;									// 0D0-0D4
	float m_fCollisionDamageMult;								// 0D4-0D8
	float m_fWeaponDamageMult;									// 0D8-0DC
	float m_fDeformationDamageMult;								// 0DC-0E0
	float m_fEngineDamageMult;									// 0E0-0E4
	float m_fSeatOffsetDist;									// 0E4-0E8
	uint32_t m_nMonetaryValue;									// 0E8-0EC
	struct {
		unsigned int bIsVan : 1;
		unsigned int bIsBus : 1;
		unsigned int bIsLow : 1;
		unsigned int bIsBig : 1;
		unsigned int bAbsStd : 1;
		unsigned int bAbsOption : 1;
		unsigned int bAbsAltStd : 1;
		unsigned int bAbsAltOption : 1;
		unsigned int bNoDoors : 1;
		unsigned int bTandemSeats : 1;
		unsigned int bSitInBoat : 1;
		unsigned int bNone : 1;
		unsigned int bNoExhaust : 1;
		unsigned int bDoubleExhaust : 1;
		unsigned int bNo1fpsLookBehind : 1;
		unsigned int bCanEnterIfNoDoor : 1;
		unsigned int bAxleFNotilt : 1;
		unsigned int bAxleFSolid : 1;
		unsigned int bAxleFMcpherson : 1;
		unsigned int bAxleFReverse : 1;
		unsigned int bAxleRNotilt : 1;
		unsigned int bAxleRSolid : 1;
		unsigned int bAxleRMcpherson : 1;
		unsigned int bAxleRReverse : 1;
		unsigned int bIsBike : 1;
		unsigned int bIsHeli : 1;
		unsigned int bIsPlane : 1;
		unsigned int bIsBoat : 1;
		unsigned int bBouncePanels : 1;
		unsigned int bDoubleRWheels : 1;
		unsigned int bForceGroundClearance : 1;
		unsigned int bIsHatchback : 1;
	} m_nModelFlags;											// 0EC-0F0
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
	} m_nHandlingFlags;											// 0F0-0F4
	uint8_t pad2[0x1C];											// 0F4-110
};

VALIDATE_SIZE(tHandlingData, 0x110);
VALIDATE_OFFSET(tHandlingData, m_fMass, 0x10);
VALIDATE_OFFSET(tHandlingData, m_fDragMult, 0x14);
VALIDATE_OFFSET(tHandlingData, m_vCenterOfMass, 0x20);
VALIDATE_OFFSET(tHandlingData, m_nPercentSubmerged, 0x30);
VALIDATE_OFFSET(tHandlingData, m_nDriveGears, 0x40);
VALIDATE_OFFSET(tHandlingData, m_fDriveForce, 0x44);
VALIDATE_OFFSET(tHandlingData, m_fBrakeForce, 0x74);
VALIDATE_OFFSET(tHandlingData, m_fTractionCurveMax, 0x8C);
VALIDATE_OFFSET(tHandlingData, m_fTractionCurveMin, 0x94);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionForce, 0xB4);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionCompDamp, 0xB8);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionReboundDamp, 0xBC);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionUpperLimit, 0xC0);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionLowerLimit, 0xC4);
VALIDATE_OFFSET(tHandlingData, m_fSuspensionRaise, 0xC8);
VALIDATE_OFFSET(tHandlingData, m_fCollisionDamageMult, 0xD4);
VALIDATE_OFFSET(tHandlingData, m_fWeaponDamageMult, 0xD8);
VALIDATE_OFFSET(tHandlingData, m_fDeformationDamageMult, 0xDC);
VALIDATE_OFFSET(tHandlingData, m_fEngineDamageMult, 0xE0);
VALIDATE_OFFSET(tHandlingData, m_fSeatOffsetDist, 0xE4);
VALIDATE_OFFSET(tHandlingData, m_nMonetaryValue, 0xE8);
VALIDATE_OFFSET(tHandlingData, m_nModelFlags, 0xEC);
VALIDATE_OFFSET(tHandlingData, m_nHandlingFlags, 0xF0);

class cHandlingDataMgr
{
public:
	static inline tHandlingData* HandlingData = (tHandlingData*)AddressSetter::Get(0x11E3BF0, 0x12773B0); // HandlingData[160]

	static void Initialise()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x571FC0, 0x7A2C10)))();
	}
	static void LoadHandlingData(char* sPath)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x571D60, 0x7A29B0)))(sPath);
	}
	static tHandlingData* GetHandlingData(int id)
	{
		return ((tHandlingData*(__cdecl*)(int))(AddressSetter::Get(0x5719C0, 0x7A2610)))(id);
	}
	static int GetHandlingId(char* handlingName)
	{
		return ((int(__cdecl*)(char*))(AddressSetter::Get(0x571BF0, 0x7A2840)))(handlingName);
	}
};