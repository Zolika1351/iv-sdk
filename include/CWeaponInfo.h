class CWeaponInfo
{
public:
	uint32_t m_nWeaponType;									// 000-004
	uint32_t m_nSlot;										// 004-008
	uint32_t m_nFireType;									// 008-00C
	uint32_t m_nDamageType;									// 00C-010
	uint32_t m_nGroup;										// 010-014
	float m_fTargetRange;									// 014-018
	float m_fWeaponRange;									// 018-01C
	uint32_t m_nStatType;									// 01C-020
	struct {
		unsigned int bCanAim : 1;
		unsigned int bCanAimWithArm : 1;
		unsigned int bCanFreeAim : 1;
		unsigned int bFirstPerson : 1;
		unsigned int bKeepCameraBehind : 1;
		unsigned int bGun : 1;
		unsigned int bThrown : 1;
		unsigned int bHeavy : 1;
		unsigned int bSilenced : 1;
		unsigned int bMeleeClub : 1;
		unsigned int bMeleeBlade : 1;
		unsigned int bArmourPenetrating : 1;
		unsigned int b2Handed : 1;
		unsigned int bTreatAs2HandedInCover : 1;
		unsigned int bAnimReload : 1;
		unsigned int bAnimCrouchFire : 1;
		unsigned int bCreateVisibleOrdnance : 1;
		unsigned int bExplosionBasedOnImpact : 1;
		unsigned int bAddSmokeOnExplosion : 1;
		unsigned int bInstantKillInMP : 1;
		unsigned int bHigherBreakForce : 1;
		unsigned int bCanBeUsedAsDriveBy : 1;
		unsigned int bHeavyWeaponUsesRifleAnims : 1;
		unsigned int bMissionCanForceDriveByUse : 1;
		unsigned int bDontRumbleWhenDoingDriveBy : 1;
	} m_nWeaponFlags;										// 020-024
	uint32_t m_nModelHash;									// 024-028
	uint32_t m_nAnimation;									// 028-02C
	float m_fFireRate;										// 02C-030
	float m_fBlindFireRate;									// 030-034
	float m_fAccuracy;										// 034-038
	float m_fAccuracyFPS;									// 038-03C
	uint8_t pad[0x4];										// 03C-040
	CVector_pad m_vOffset;									// 040-050
	CVector_pad m_vCrouchOffset;							// 050-060
	float m_fAimingPitch;									// 060-064
	float m_fReticuleStanding;								// 064-068
	float m_fReticuleDucked;								// 068-06C
	float m_fReticuleScale;									// 06C-070
	uint32_t m_nRumbleDuration;								// 070-074
	float m_fRumbleIntensity;								// 074-078
	uint32_t m_nPickupRegenTime;							// 078-07C
	uint8_t pad2[0x4];										// 07C-080
	uint16_t m_nPickupAmmoOnStreet;							// 080-082
	uint16_t m_nDamage;										// 082-084
	uint16_t m_nDamageFPS;									// 084-086
	uint16_t m_nClipSize;									// 086-088
	uint32_t m_nMaxAmmo;									// 088-08C
	uint32_t m_nTimeBetweenShots;							// 08C-090
	float m_fPhysicsForce;									// 090-094
	uint32_t m_nReloadTimeNormal;							// 094-098
	uint32_t m_nReloadTimeFast;								// 098-09C
	uint32_t m_nReloadTimeCrouch;							// 09C-0A0
	uint32_t m_nProjectileType;								// 0A0-0A4
	uint32_t m_nProjectileFuseTime;							// 0A4-0A8
	uint32_t m_nProjectileToCreate;							// 0A8-0AC
	uint32_t m_nProjectileExplosionType;					// 0AC-0B0
	CVector_pad m_vProjectileOffset;						// 0B0-0C0
	CVector_pad m_vProjectileRotOffset;						// 0C0-0D0
	float m_fProjectilePhysicsExplodeImpactThreshold;		// 0D0-0D4
	float m_fProjectilePhysicsExplodeImpactVehicleThreshold;// 0D4-0D8
	float m_fProjectilePhysicsVehicleVelocity;				// 0D8-0DC
	uint32_t m_nMeleeAnim;									// 0DC-0E0
	uint8_t pad3[0x4];										// 0E0-0E4
	uint32_t m_nMuzzleFx;									// 0E4-0E8
	uint32_t m_nShellFx;									// 0E8-0EC
	uint32_t m_nProjectileTrailFx;							// 0EC-0F0
	float m_fNetworkPlayerMod;								// 0F0-0F4
	float m_fNetworkPedMod;									// 0F4-0F8
	float m_fAimingAccuracyTime;							// 0F8-0FC
	uint32_t m_nAimingPellets;								// 0FC-100
	uint32_t m_nShotsFired;									// 100-104
	uint8_t pad4[0xC];										// 104-110

	static inline char** ms_aWeaponNames = (char**)AddressSetter::Get(0xB27A88, 0xB3ECA8);
	static inline CWeaponInfo* ms_WeaponInfo = (CWeaponInfo*)AddressSetter::Get(0x1140A20, 0xE4A600); // ms_WeaponInfo[60]

	static CWeaponInfo* GetWeaponInfo(uint32_t type)
	{
		return ((CWeaponInfo*(__cdecl*)(uint32_t))(AddressSetter::Get(0x524E80, 0x4DDEB0)))(type);
	}
};
VALIDATE_SIZE(CWeaponInfo, 0x110);