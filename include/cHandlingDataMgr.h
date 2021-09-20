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
		unsigned int m_bIsVan : 1;
		unsigned int m_bIsBus : 1;
		unsigned int m_bIsLow : 1;
		unsigned int m_bIsBig : 1;
		unsigned int m_bAbsStd : 1;
		unsigned int m_bAbsOption : 1;
		unsigned int m_bAbsAltStd : 1;
		unsigned int m_bAbsAltOption : 1;
		unsigned int m_bNoDoors : 1;
		unsigned int m_bTandemSeats : 1;
		unsigned int m_bSitInBoat : 1;
		unsigned int m_bNone : 1;
		unsigned int m_bNoExhaust : 1;
		unsigned int m_bDoubleExhaust : 1;
		unsigned int m_bNo1fpsLookBehind : 1;
		unsigned int m_bCanEnterIfNoDoor : 1;
		unsigned int m_bAxleFNotilt : 1;
		unsigned int m_bAxleFSolid : 1;
		unsigned int m_bAxleFMcpherson : 1;
		unsigned int m_bAxleFReverse : 1;
		unsigned int m_bAxleRNotilt : 1;
		unsigned int m_bAxleRSolid : 1;
		unsigned int m_bAxleRMcpherson : 1;
		unsigned int m_bAxleRReverse : 1;
		unsigned int m_bIsBike : 1;
		unsigned int m_bIsHeli : 1;
		unsigned int m_bIsPlane : 1;
		unsigned int m_bIsBoat : 1;
		unsigned int m_bBouncePanels : 1;
		unsigned int m_bDoubleRWheels : 1;
		unsigned int m_bForceGroundClearance : 1;
		unsigned int m_bIsHatchback : 1;
	} m_mFlags;													// 0EC-0F0
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
	} m_hFlags;													// 0F0-0F4
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
VALIDATE_OFFSET(tHandlingData, m_mFlags, 0xEC);
VALIDATE_OFFSET(tHandlingData, m_hFlags, 0xF0);

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
};