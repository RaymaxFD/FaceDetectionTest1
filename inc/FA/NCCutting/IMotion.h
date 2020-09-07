

#pragma once
#include <IBase.h>

class IUtilYCH;
class IMotionEvt_V1;

class IMotion_V1 : public IBase
{
public:
	enum _eFrontRear
	{
		eFront,
		eRear,
	};
public:
	enum _eAxis
	{
		AXIS_Z_FRONT,
		AXIS_Z_REAR,
		AXIS_Y,
		AXIS_T,
		AXIS_MAX,
	};
	enum _eDir
	{
		DIR_CW,
		DIR_CCW,
	};
public:
	//static const DWORD SPEED_MAX = 250000;
	//static const DWORD SPEED_MAX = 100000;
	static const DWORD SPEED_MAX = 300000;
	static const DWORD SPEED_DEACEL = 100000;
	static const DWORD SPEED_CUTTING = 2000;

	// 여기!!!!!
public:
	static const DWORD Y_POS_TABLE_READY = 0;
	static const DWORD Y_POS_CUTTING_READY = 92000;
	static const DWORD Y_POS_CUTTING_FRONT = 125000;
	static const DWORD Y_POS_CUTTING_REAR = 473000;
	//static const DWORD T_OFFSET = 2519;
	//static const DWORD T_OFFSET = 1100;
	static const DWORD T_OFFSET = 775;
	static const DWORD T_POS_0 = 0 + T_OFFSET;
	//static const DWORD T_POS_90 = 268858 + T_OFFSET;
	static const DWORD T_POS_90 = 271500;
	static const DWORD Z_POS_IDLE = 3000;
	static const DWORD Z_POS_READY = 17000;
	//static const DWORD Z_POS_CUTTING_DOWN = 19000;
	//static const DWORD Z_POS_CUTTING_UP = 20000;
	//static const DWORD Z_POS_DEACEL = 21000;
	//static const DWORD Z_POS_CUTTING = 22000; // 이 위치를 기준으로 blade 마다 offset 적용
#if 0
	//static const DWORD Z_OFFSET_FRONT = 27000;
	static const DWORD Z_OFFSET_FRONT = 20000;
	static const DWORD Z_POS_CUTTING_DOWN_FRONT = 17500 + Z_OFFSET_FRONT;
	static const DWORD Z_POS_CUTTING_UP_FRONT = 18000 + Z_OFFSET_FRONT;
	static const DWORD Z_POS_DEACEL_FRONT = 21500 + Z_OFFSET_FRONT;
	static const DWORD Z_POS_CUTTING_FRONT = 22000 + Z_OFFSET_FRONT; // 이 위치를 기준으로 blade 마다 offset 적용

	//static const DWORD Z_OFFSET_REAR = 27000 - 559;
	static const DWORD Z_OFFSET_REAR = 2700 - 559;
	static const DWORD Z_POS_CUTTING_DOWN_REAR = 17500 + Z_OFFSET_REAR;
	static const DWORD Z_POS_CUTTING_UP_REAR = 18000 + Z_OFFSET_REAR;
	static const DWORD Z_POS_DEACEL_REAR = 21500 + Z_OFFSET_REAR;
	static const DWORD Z_POS_CUTTING_REAR = 22000 + Z_OFFSET_REAR; // 이 위치를 기준으로 blade 마다 offset 적용
#else
	static const DWORD Z_FRONT_MAX = 50000;
	static const DWORD Z_REAR_MAX = 50000;
	static const DWORD Y_MAX = 616000;
	static const DWORD Y_FRONT_MAX = 251000;
	static const DWORD Y_REAR_MAX = 600000;
	static const DWORD T_MAX = 280000;

	//static const DWORD Z_OFFSET = 15000;
	static const DWORD Z_OFFSET = 0;
	static const DWORD Z_POS_CUTTING_DOWN_FRONT = 38000 - Z_OFFSET;
	static const DWORD Z_POS_CUTTING_UP_FRONT = 40000 - Z_OFFSET;
	static const DWORD Z_POS_DEACEL_FRONT = 45000 - Z_OFFSET;

	static const DWORD Z_POS_CUTTING_DOWN_REAR = 38000 - Z_OFFSET;
	static const DWORD Z_POS_CUTTING_UP_REAR = 40000 - Z_OFFSET;
	static const DWORD Z_POS_DEACEL_REAR = 45000 - Z_OFFSET;
#endif

public:
	virtual bool IsStateNotInited() = 0;
	virtual bool IsStateEmergency() = 0;
	virtual bool IsStateHomingZ()   = 0;
	virtual bool IsStateHomingY()   = 0;
	virtual bool IsStateHomingT()   = 0;
	virtual bool IsStateIdle()      = 0;
	virtual bool IsStateMoving()    = 0;
	virtual bool IsStateError()     = 0;
public:
	virtual bool IsTableOut()       = 0;

public:
	virtual void AddIEvent(IMotionEvt_V1* pI) = 0;
	virtual void EnableEvent(bool b) = 0;

public:
	virtual bool Homing() = 0;
public:
	virtual bool HomingZFront() = 0;
	virtual bool HomingZRear() = 0;
	virtual bool HomingY() = 0;
	virtual bool HomingT() = 0;

public:
	virtual bool ZFrontUp(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool ZFrontDown(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool ZFrontMove(DWORD dwTarget, DWORD dwSpeed) = 0;
	virtual bool ZFrontJog(DWORD dwSpeed, bool bCW) = 0;
	virtual void ZFrontStop() = 0;
	virtual void ZFrontEStopEnable(bool b) = 0; // contact시 채터링 방지용으로 사용

public:
	virtual bool ZRearUp(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool ZRearDown(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool ZRearMove(DWORD dwTarget, DWORD dwSpeed) = 0;
	virtual bool ZRearJog(DWORD dwSpeed, bool bCW) = 0;
	virtual void ZRearStop() = 0;
	virtual void ZRearEStopEnable(bool b) = 0; // contact시 채터링 방지용으로 사용

public:
	virtual bool YFront(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool YRear(double dStepMM, DWORD dwSpeed) = 0;
	virtual bool YMove(DWORD dwTarget, DWORD dwSpeed) = 0;
	virtual bool YJog(DWORD dwSpeed, bool bCW) = 0;
	virtual void YStop() = 0;

public:
	virtual bool ThetaCW(double dStepDeg, DWORD dwSpeed) = 0;
	virtual bool ThetaCCW(double dStepDeg, DWORD dwSpeed) = 0;
	virtual bool ThetaMove(DWORD dwTarget, DWORD dwSpeed) = 0;
	virtual bool TJog(DWORD dwSpeed, bool bCW) = 0;
	virtual void TStop() = 0;

public:
	virtual bool TableTurn_0(long lTheta = T_POS_0) = 0;
	virtual bool TableTurn_90(long lTheta = T_POS_90) = 0;

public:
	virtual bool IsMotionDone(_eAxis eAxis) = 0;

public:	
	virtual void MoveStepStart(_eAxis eAxis, _eDir eDir, double dMM, DWORD dwTime) = 0;
	virtual void MoveStepStop() = 0;

public:
	virtual long GetPulsePermm(double dMM) = 0;
	virtual double GetmmPerPulse(DWORD dwPulse) = 0;
	virtual long GetPulsePerDeg(double dMM) = 0;
	virtual double GetDegPerPulse(DWORD dwPulse) = 0;
	virtual long GetNowPosZFront() = 0;
	virtual long GetNowPosZRear() = 0;
	virtual long GetNowPosY() = 0;
	virtual long GetNowPosT() = 0;

public:
	virtual bool IsPossibleMovingZFront(long lTarget) = 0;
	virtual bool IsPossibleMovingZRear(long lTarget) = 0;
	virtual bool IsPossibleMovingY(long lTarget) = 0;
	virtual bool IsPossibleMovingT(long lTarget) = 0;

public:
	virtual void TableVacuum(bool bOn) = 0;

public:
	virtual void OutBoxResetSWLamp(bool bOnOff)                          = 0;
	virtual void OutBoxInitSwLamp(bool bOnOff)                           = 0;
	virtual void OutLeftBoxPauseSWLamp(bool bOnOff)                      = 0;
	virtual void OutRightBoxPauseSWLamp(bool bOnOff)                     = 0;
	virtual void OutJIGVacuumSWLamp(bool bOnOff)                         = 0;
	virtual void OutHotPlateTemp1SWLamp(bool bOnOff)                     = 0;
	virtual void OutHotPlateTemp2SWLamp(bool bOnOff)                     = 0;


	virtual void OutTableVacuumSol1(bool bOnOff)                         = 0;
	virtual void OutTableVacuumSol2(bool bOnOff)                         = 0;
	virtual void OutFrontCutterClamp(bool bOnOff)                        = 0;	
	virtual void OutFrontCutterStripperUp(bool bOnOff)                   = 0;
	virtual void OutFrontCutterStripperDown(bool bOnOff)                 = 0;
	virtual void OutFrontCutterCleanSol(bool bOnOff)                     = 0;
	virtual void OutRearCutterClamp(bool bOnOff)                         = 0;

	virtual void OutRearCutterStripperUp(bool bOnOff)                    = 0;
	virtual void OutRearCutterStripperDown(bool bOnOff)                  = 0;
	virtual void OutRearCutterCleanSol(bool bOnOff)                      = 0;
	virtual void OutJIGVacuumSol(bool bOnOff)                            = 0;

	virtual void OutLight(bool bOnOff)                                   = 0;
	virtual void OutZFrontRearServo(bool bOnOff)                         = 0;
	virtual void OutYThetaSevo(bool bOnOff)                              = 0;
	virtual void OutTableHeater(bool bOnOff)                             = 0;
	virtual void OutHotPlateHeater1(bool bOnOff)                         = 0;
	virtual void OutHotPlateHeater2(bool bOnOff)                         = 0;

	virtual void OutTowerRed(bool bOnOff)                                = 0;
	virtual void OutTowerYellow(bool bOnOff)                             = 0;
	virtual void OutTowerGreen(bool bOnOff)                              = 0;
	virtual void OutTowerBuzzer(bool bOnOff)                             = 0;
public:
	virtual bool IsOutBoxResetSWLamp()                                   = 0;
	virtual bool IsOutBoxInitSwLamp()                                    = 0;
	virtual bool IsOutLeftBoxPauseSWLamp()                               = 0;
	virtual bool IsOutRightBoxPauseSWLamp()                              = 0;
	virtual bool IsOutJIGVacuumSWLamp()                                  = 0;
	virtual bool IsOutHotPlateTemp1SWLamp()                              = 0;
	virtual bool IsOutHotPlateTemp2SWLamp()                              = 0;
	virtual bool IsOutTableVacuumSol1()                                  = 0;
	virtual bool IsOutTableVacuumSol2()                                  = 0;
	virtual bool IsOutFrontCutterClamp()                                 = 0;	
	virtual bool IsOutFrontCutterStripperUp()                            = 0;
	virtual bool IsOutFrontCutterStripperDown()                          = 0;
	virtual bool IsOutFrontCutterCleanSol()                              = 0;
	virtual bool IsOutRearCutterClamp()                                  = 0;
	virtual bool IsOutRearCutterStripperUp()                             = 0;
	virtual bool IsOutRearCutterStripperDown()                           = 0;
	virtual bool IsOutRearCutterCleanSol()                               = 0;
	virtual bool IsOutJIGVacuumSol()                                     = 0;
	virtual bool IsOutLight()                                            = 0;
	virtual bool IsOutZFrontRearServo()                                  = 0;
	virtual bool IsOutYThetaSevo()                                       = 0;
	virtual bool IsOutTableHeater()                                      = 0;
	virtual bool IsOutHotPlateHeater1()                                  = 0;
	virtual bool IsOutHotPlateHeater2()                                  = 0;
	virtual bool IsOutTowerRed()                                         = 0;
	virtual bool IsOutTowerYellow()                                      = 0;
	virtual bool IsOutTowerGreen()                                       = 0;
	virtual bool IsOutTowerBuzzer()                                      = 0;

public:
	virtual bool IsEMG_LEFT() = 0;
	virtual bool IsEMG_RIGHT() = 0;
	virtual bool IsEMG_BOX() = 0;
	virtual bool IsSTART_LEFT() = 0;
	virtual bool IsSTART_RIGHT() = 0;
	virtual bool IsRESET() = 0;
	virtual bool IsINIT() = 0;
	virtual bool IsPAUSE_LEFT() = 0;

	virtual bool IsPAUSE_RIGHT() = 0;
	virtual bool IsMAIN_AIR() = 0;
	virtual bool IsSAFETY_1() = 0;
	virtual bool IsSAFETY_2() = 0;
	virtual bool IsCHUCK_VACUUM_1() = 0;
	virtual bool IsCHUCK_VACUUM_2() = 0;
	virtual bool IsFRONT_CUTTER_CHANGE_OPEN() = 0;
	virtual bool IsFRONT_CUTTER_CHANGE_CLOSE() = 0;

	virtual bool IsFRONT_CLEAN_FWD() = 0;
	virtual bool IsFRONT_CLEAN_REV() = 0;
	virtual bool IsREAR_CUTTER_CHANGE_OPEN() = 0;
	virtual bool IsREAR_CUTTER_CHANGE_CLOSE() = 0;
	virtual bool IsREAR_CLEAN_FWD() = 0;
	virtual bool IsREAR_CLEAN_REV() = 0;
	virtual bool IsCHUCK_TURN_0() = 0;
	virtual bool IsCHUCK_TURN_1() = 0;

	virtual bool IsFRONT_CUTTER_CONTACT() = 0;
	virtual bool IsREAR_CUTTER_CONTACT() = 0;
	virtual bool IsJIG_VACUUM_SW() = 0;
	virtual bool IsJIG_VACUUM_SENSOR() = 0;
	virtual bool IsHOT_PLATE_TEMP_LEFT() = 0;
	virtual bool IsHOT_PLATE_TEMP_RIGHT() = 0;

	virtual bool IsCHUCK_TEMP_ERROR() = 0;
	virtual bool IsCHUCK_TEMP_OK() = 0;
	virtual bool IsHOT_PLATE_LEFT_ERROR() = 0;
	virtual bool IsHOT_PLATE_LEFT_OK() = 0;
	virtual bool IsHOT_PLATE_RIGHT_ERROR() = 0;
	virtual bool IsHOT_PLATE_RIGHT_OK() = 0;

	virtual bool IsLEFT_DOOR() = 0;
	virtual bool IsRIGHT_DOOR() = 0;
	virtual bool IsFRONT_LEFT_DOOR_OPEN() = 0;
	virtual bool IsFRONT_RIGHT_DOOR_OPEN() = 0;
	virtual bool IsREAR_LEFT_DOOR_OPEN() = 0;
	virtual bool IsREAR_RIGHT_DOOR_OPEN() = 0;

public:
	virtual void SetUtilYCH(IUtilYCH* pI) = 0;

};

class IMotionEvt_V1
{
public:
	enum _eError
	{
		errNone,
		errCheckMachinePower,
		errAxisZFront,
		errAxisZRear,
		errAxisY,
		errAxisT,
		errRangeOver,
	};

public:
	virtual void EvtIServoError(_eError err)                                                         {}
public:
	virtual void EvtIServoHomingDone()                                                               {}
public:
	virtual void EvtIServoHomingDoneOnlyZFront()                                                     {}
	virtual void EvtIServoHomingDoneOnlyZRear()                                                      {}
	virtual void EvtIServoHomingDoneOnlyY()                                                          {}
	virtual void EvtIServoHomingDoneOnlyT()                                                          {}

public:
	virtual void EVTIServoDoneZFront(bool bDone)                                                     {}
	virtual void EVTIServoDoneZRear(bool bDone)                                                      {}
	virtual void EVTIServoDoneY(bool bDone)                                                          {}
	virtual void EVTIServoDoneT(bool bDone)                                                          {}

	// IO Input Start
public:
	virtual void EVTIServoEmgLeft(bool bOnOff){}
	virtual void EVTIServoEmgRight(bool bOnOff){}
	virtual void EVTIServoEmgBox(bool bOnOff){}
	virtual void EVTIServoStartLeft(bool bOnOff){}
	virtual void EVTIServoStartRight(bool bOnOff){}
	virtual void EVTIServoReset(bool bOnOff){}
	virtual void EVTIServoInit(bool bOnOff){}
	virtual void EVTIServoPauseLeft(bool bOnOff){}

	virtual void EVTIServoPauseRight(bool bOnOff){}
	virtual void EVTIServoMainAir(bool bOnOff){}
	virtual void EVTIServoSafety1(bool bOnOff){}
	virtual void EVTIServoSafety2(bool bOnOff){}
	virtual void EVTIServoChuckVacuum1(bool bOnOff){}
	virtual void EVTIServoChuckVacuum2(bool bOnOff){}
	virtual void EVTIServoFrontCutterChangeOpen(bool bOnOff){}
	virtual void EVTIServoFrontCutterChangeClose(bool bOnOff){}

	virtual void EVTIServoFrontCleanFWD(bool bOnOff){}
	virtual void EVTIServoFrontCleanREV(bool bOnOff){}
	virtual void EVTIServoRearCutterChangeOpen(bool bOnOff){}
	virtual void EVTIServoRearCutterChangeClose(bool bOnOff){}
	virtual void EVTIServoRearCleanFWD(bool bOnOff){}
	virtual void EVTIServoRearCleanREV(bool bOnOff){}
	virtual void EVTIServoChuckTurn0(bool bOnOff){}
	virtual void EVTIServoChuckTurn1(bool bOnOff){}
	
	virtual void EVTIServoFrontCutterContact(bool bOnOff){}
	virtual void EVTIServoRearCutterContact(bool bOnOff){}
	virtual void EVTIServoJigVacuumSW(bool bOnOff){}
	virtual void EVTIServoJigVacuumSensor(bool bOnOff){}
	virtual void EVTIServoHotPlateTempLeft(bool bOnOff){}
	virtual void EVTIServoHotPlateTempRight(bool bOnOff){}
	//
	//
	
	virtual void EVTIServoChuckTempError(bool bOnOff){}
	virtual void EVTIServoChuckTempOk(bool bOnOff){}
	virtual void EVTIServoHotPlateLeftError(bool bOnOff){}
	virtual void EVTIServoHotPlateLeftOk(bool bOnOff){}
	virtual void EVTIServoHotPlateRightError(bool bOnOff){}
	virtual void EVTIServoHotPlateRightOk(bool bOnOff){}
	//
	//
	
	//
	//
	virtual void EVTIServoElectricUintLeftDoor(bool bOnOff){}
	virtual void EVTIServoElectricUintRightDoor(bool bOnOff){}
	virtual void EVTIServoFrontLeftDoorOpen(bool bOnOff){}
	virtual void EVTIServoFrontRightDoorOpen(bool bOnOff){}
	virtual void EVTIServoRearLeftDoorOpen(bool bOnOff){}
	virtual void EVTIServoRearRightDoorOpen(bool bOnOff){}
	// IO Input End



public:
	enum _eAxisStatus
	{
		eEmergency,
		eAlarm,
		eELP,
		eELM,
		eHome,
		eDirP,
		eHomingOk,
		ePCS,
		eCRC,
		eZ,
		eCLR,
		eLATCH,
		eSD,
		eINP,
		eServoOn,
		eALMReset,
		eSTA,
		eSTP,
		eMasterSlaveOffetError,
		eGantryOffetError,
	};
	virtual void EVTIMotionAxisStatus(IMotion_V1::_eAxis eAxis, _eAxisStatus eStatus, bool bStatus){}
};


class ISerial;
class IMotionStepEvt_V1;

class IMotionStep_V1 : public IBase
{
public:
	//static const DWORD POS_OUT = 8000;
	static const DWORD POS_OUT = 0;
	static const DWORD POS_WORKING_FRONT_LEFT_X = 23000;
	static const DWORD POS_WORKING_FRONT_LEFT_D = 11900;
	static const DWORD POS_WORKING_FRONT_RIGHT_X = 21000;
	static const DWORD POS_WORKING_FRONT_RIGHT_D = 12000;
	static const DWORD POS_WORKING_REAR_LEFT_X = 33500;
	static const DWORD POS_WORKING_REAR_LEFT_D = 10000;
	static const DWORD POS_WORKING_REAR_RIGHT_X = 23200;
	static const DWORD POS_WORKING_REAR_RIGHT_D = 12000;

public:
	static const DWORD POS_LIMIT_X = 75000;
	static const DWORD POS_LIMIT_D = 19000;

public:
	enum _eMotor
	{
		eMotorLeftX = 0,
		eMotorLeftD,
		eMotorRightX,
		eMotorRightD,
		eMotorMax = 4,
	};
public:
	enum _eFrontRear
	{
		eFront,
		eRear,
		eFrontRearMax,
	};

public:
	virtual void MoveStepMM(_eMotor eMotor, double dMM) = 0;
	virtual void GetTargetPosPulse(_eMotor eMotor, long& lPos) = 0;
	virtual void SetTargetPosPulse(_eMotor eMotor, long lPos) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0; // IO를 받아야 하므로

public:
	virtual void AddIEvent(IMotionStepEvt_V1* pI) = 0;
	virtual void EnableEvent(bool b) = 0;

public:
	virtual bool IsStateNotInited(_eMotor e) = 0;
	virtual bool IsStateEmergency(_eMotor e) = 0;
	virtual bool IsStateIdle(_eMotor e)      = 0;
	virtual bool IsStateMoving(_eMotor e)    = 0;
	virtual bool IsStateError(_eMotor e)     = 0;

public:
	virtual bool IsHomingDone(_eMotor e)     = 0;
	virtual bool IsReady(_eMotor e)          = 0;
	virtual bool isAlarm(_eMotor e)          = 0;
	virtual bool isMoving(_eMotor e)         = 0;
	virtual bool IsDone(_eMotor e)           = 0;

public:
	virtual bool Homing() = 0;

public:
	virtual void Start() = 0;
	virtual void SetFrontRear(_eFrontRear eFrontRear) = 0;
	virtual void AllCamMoveOut() = 0;
	virtual void AllCamMoveIn() = 0;
	virtual void AllCamMove2Target() = 0;
	virtual DWORD GetNowPos(_eMotor eMotor) = 0;
	virtual void GetNowPos(_eMotor eMotor, DWORD& dwPos) = 0;

public:
	virtual void SetISerial(ISerial* pISerial) = 0;


public:
	virtual void INA_AR_START(int nSlaveNo, int nDataIndex) = 0;
	virtual void INA_AR_HOME(int nSlaveNo) = 0;
	virtual void INA_AR_STOP(int nSlaveNo) = 0;
	virtual void INA_AR_FREE(int nSlaveNo, bool bOnOff) = 0;
	virtual void INA_AR_FWD(int nSlaveNo, int nDataIndex, bool bOnOff) = 0;
	virtual void INA_AR_RVS(int nSlaveNo, int nDataIndex, bool bOnOff) = 0;
	virtual void INA_RK_MS0(int nSlaveNo) = 0;
	virtual void INA_RK_MS1(int nSlaveNo) = 0;
	virtual void INA_RK_MS2(int nSlaveNo) = 0;
	virtual void INA_AR_Clear(int nSlaveNo) = 0;			

	virtual bool INA_AR_OUTFLAG(int nSlaveNo) = 0;
	virtual void INA_AR_MAIN_ALARM_RESET(int nSlaveNo) = 0;
	virtual void INA_AR_ABSOLUTE_POS_ALARM_RESET(int nSlaveNo) = 0;
	virtual void INA_AR_P_PRESET(int nSlaveNo) = 0;
	virtual void INA_AR_MAIN_NVMEMORY_WRITE(int nSlaveNo) = 0;
	virtual bool INA_AR_MONITOR_ALARM(int nSlaveNo) = 0;
	virtual bool INA_AR_MONITOR_WARNING(int nSlaveNo) = 0;
	virtual void INA_AR_MONITOR_POSITION(int nSlaveNo) = 0;
	virtual void INA_AR_MONITOR_VELOCITY(int nSlaveNo) = 0;
	virtual void INA_AR_MONITOR_FEEDBACK_POSITION(int nSlaveNo) = 0;
	virtual void INA_AR_MONITOR_DIRECT_IO(int nSlaveNo) = 0;
	virtual void INA_AR_SET_POSITION(int nSlaveNo, int nAddIndex, int nPosition) = 0;
	virtual bool INA_AR_GET_POSITION(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_VELOCITY(int nSlaveNo, int nAddIndex, int nVelocity) = 0;
	virtual bool INA_AR_GET_VELOCITY(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_POSITION_MODE(int nSlaveNo, int nAddIndex, int nPositionMode) = 0;
	virtual bool INA_AR_GET_POSITION_MODE(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_OPERATING_MODE(int nSlaveNo, int nAddIndex, int OperatorMode) = 0;
	virtual bool INA_AR_GET_OPERATING_MODE(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_ACC_TIME(int nSlaveNo, int nAddIndex, int nAccTime) = 0;
	virtual bool INA_AR_GET_ACC_TIME(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_DEC_TIME(int nSlaveNo, int nAddIndex, int nDecTime) = 0;
	virtual bool INA_AR_GET_DEC_TIME(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_DWELL_TIME(int nSlaveNo, int nAddIndex, int nDwell) = 0;
	virtual bool INA_AR_GET_DWELL_TIME(int nSlaveNo, int nAddIndex) = 0;
	virtual void INA_AR_SET_HOME_OPERATOR_VELOCITY(int nSlaveNo, int nVelociry) = 0;
	virtual bool INA_AR_GET_HOME_OPERATOR_VELOCITY(int nSlaveNo) = 0;
	virtual void INA_AR_SET_HOME_STARTUP_VELOCITY(int nSlaveNo, int nVelociry) = 0;
	virtual bool INA_AR_GET_HOME_STARTUP_VELOCITY(int nSlaveNo) = 0;
};

class IMotionStepEvt_V1
{
public:
	virtual void EvtIMotionStepCommError(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep)                                                                                    {}

public:
	virtual void EvtIMotionStepHomingDone(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, bool bDone)                                                                       {}
	virtual void EvtIMotionStepMotionDone(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, bool bDone)                                                                       {}
	virtual void EvtIMotionStepReady(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, bool bReady)                                                                           {}
	virtual void EvtIMotionStepAlarm(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, bool bAlarm)                                                                           {}
	virtual void EvtIMotionStepMove(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, bool bMove)                                                                             {}

public:
	virtual void EvtIMotionStepRstCmdMonitorCurrentAlarm(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                        {}
	virtual void EvtIMotionStepRstCmdMonitorCurrentWarning(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                      {}
	virtual void EvtIMotionStepRstCmdParameterPosition(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                          {}
	virtual void EvtIMotionStepRstCmdParameterVelocity(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                          {}
	virtual void EvtIMotionStepRstCmdParameterPositionMode(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                      {}
	virtual void EvtIMotionStepRstCmdParameterOperatingMode(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                     {}
	virtual void EvtIMotionStepRstCmdParameterAccelation(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                        {}
	virtual void EvtIMotionStepRstCmdParameterDecelation(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                        {}
	virtual void EvtIMotionStepRstCmdParameterDwell(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                             {}
	virtual void EvtIMotionStepRstUserHomeOperatorVelocity(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                      {}
	virtual void EvtIMotionStepRstUserHomeStartupVelocity(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                       {}
	virtual void EvtIMotionStepRstCmdMotionOutput(IMotionStep_V1::_eFrontRear eFrontRear, IMotionStep_V1::_eMotor eStep, int iParam)                                                               {}
};
