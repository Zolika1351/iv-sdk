struct tHandlingData
{
	char m_sName[16]; // 00-10
	float m_fMass; // 10-14
	float m_fDragMult; // 14-18
	float unk1; // 18-1C always 0
	float unk2; // 1C-20 always 0
	CVector m_vCenterOfMass; // 20-2C
	uint32_t vector3pad; // 2C-30
	int m_nPercentSubmerged; // 30-34
	float m_fPercentSubmerged; // 34-38 100.0 / m_nPercentSubmerged
	float m_fDriveBiasF; // 38-3C
	float m_fDriveBiasR; // 3C-40
	int m_nDriveGears; // 40-44
	float m_fDriveForce; // 44-48
	float m_fDriveInertia; // 48-4C
	float m_fV_times12; // 50 m_fV * 1.2
	float m_fV; // 50-54
	float m_fV_gearR; // 54
	float m_fV_gear1; // 58
	float m_fV_gear2; // 5C
	float m_fV_gear3; // 60
	float m_fV_gear4; // 64
	float m_fV_gear5; // 68
	float m_fV_gear6; // 6C
	float m_fV_gear7; // 70
	float m_fBrakeForce; // 74-78
	float m_fBrakeForceF; // 78-7C
	float m_fBrakeForceR; // 7C-80
	float m_fHBias; // 80
	float m_fSteeringLock; // 84
	float m_fSteeringLockPercent; // 88 1.0 / m_fSteeringLock
	float m_fTractionCurveMax; // 8C-90
	float m_fTractionCurveMaxPercent; // 90-94 1.0 / m_fTractionCurveMaxPercent
	float m_fTractionCurveMin; // 94-98
	float m_fTractionCurvePercent; // 98
	float m_fTractionCurveLateral; // 9C
	float m_fTractionCurveLateralPercent; // A0-A4 1.0 / m_fTractionCurveLateral
	float m_fTractionSpringDeltaMax; // A4-A8
	float m_fTractionSpringDeltaMaxPercent; // A8-AC 1.0 / m_fTractionSpringDeltaMax
	float m_fTractionBiasF; // AC
	float m_fTractionBiasR; // B0
	float m_fSuspensionForce; // B4-B8
	float m_fSuspensionCompDamp; // B8-BC
	float m_fSuspensionReboundDamp; // BC-C0
	float m_fSuspensionUpperLimit; // C0-C4
	float m_fSuspensionLowerLimit; // C4-C8
	float m_fSuspensionRaise; // C8-CC
	float m_fSuspensionBiasF; // CC-D0
	float m_fSuspensionBiasR; // D0-D4
	float m_fCollisionDamageMult; // D4-D8
	float m_fWeaponDamageMult; // D8-DC
	float m_fDeformationDamageMult; // DC-E0
	float m_fEngineDamageMult; // E0-E4
	float m_fSeatOffsetDist; // E4-E8
	int m_nMonetaryValue; // E8-EC
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
	}              m_mFlags; // EC-F0
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
	}              m_hFlags; // F0-F4
	uint8_t padend[0x1C];	// F4-110
};

tHandlingData* m_aHandlingData; // m_aHandlingData[160]

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
	static inline tHandlingData* HandlingData; // HandlingData[160]
};