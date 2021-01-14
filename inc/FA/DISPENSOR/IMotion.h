

#pragma once

#include <IBase.h>

class IMotionEvt_V1;
class IMotion_V1 : public IBase
{
public:
	enum _eAxis
	{
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
	};
	enum _eDir
	{
		DIR_CW,
		DIR_CCW,
	};

public:
	static const long LIMIT_MAGIN = 0;
	static const long SPEED_DOWN_POS = 12000;
public:
	static const long MIN_X = 0;
	static const long MIN_Y = 0;
	static const long MIN_Z = 0;
public:
	static const DWORD MAX_X = 315000;
	static const DWORD MAX_Y = 397000;
	//static const DWORD MAX_Z = 138445;
	static const DWORD MAX_Z = 129000;
public:
	static const DWORD Z_DOWN = 127000;
	static const DWORD Z_UP = 97000;
	/*static const DWORD Z_DOWN = 97000;
	static const DWORD Z_UP = 37000;*/
public:
	static const DWORD SPEED_JOG_MAX = 5000;
	static const DWORD SPEED_MAX = 250000;

public:
	virtual void StartMotion() = 0;
	virtual void StopMotion() = 0;

public:
	virtual void AddIEvent(IMotionEvt_V1* pI) = 0;
	virtual void RemoveIEvent(IMotionEvt_V1* pI) = 0;

public:
	virtual void Reset(unsigned short usCard) = 0;
	virtual void ResetAlarm(_eAxis eAxis) = 0;
	virtual void SetSystemDefault(unsigned short nConNo, unsigned short nAxisNo) = 0;
	virtual void ServoOn(unsigned short nConNo, unsigned short nAxisNo,bool bEnable) = 0;
	virtual void IsServoOn(unsigned short nConNo, unsigned short nAxisNo) = 0;

public:
	virtual void GetErrorCode() = 0;
	virtual void GetErrorString(long lErr) = 0;
	virtual void GetMotionErrCod(unsigned short nConNo, unsigned short nAxisNo) = 0;

public:
	virtual bool IsORG(_eAxis eAxis) = 0;
	virtual bool IsCWLimit(_eAxis eAxis) = 0;
	virtual bool IsCCWLimit(_eAxis eAxis) = 0;
	virtual bool IsMotionDone(_eAxis eAxis) = 0;

public:
	virtual void Homing() = 0;

public:
	virtual long GetNowPosX() = 0;
	virtual long GetNowPosY() = 0;
	virtual long GetNowPosZ() = 0;
	virtual double GetmmPerPulse(long lPulse) = 0;
	virtual long GetPulsePermm(double dMM) = 0;
	virtual DWORD GetPulsePerPixel(DWORD dwPixel) = 0;
	virtual void SetPulsePerPixelRatio(DWORD dwPulse) = 0;
	virtual DWORD GetPixelPerPulse(DWORD dwPulse) = 0;

public:
	virtual void ResumeMove() = 0;
	virtual void MoveInc(_eAxis eAxis, long lPos) = 0;
	virtual void MoveAbs(_eAxis eAxis, long lPos) = 0;
	virtual void MoveJog(_eAxis eAxis, _eDir eDir) = 0;
	virtual void MoveStop(_eAxis eAxis) = 0;
	virtual void MoveXYZ(long lPosX, long lPosY, long lPosZ) = 0;
	virtual void MoveXY(long lPosX, long lPosY) = 0;
	virtual void MoveStepStart(_eAxis eAxis, _eDir eDir, double dMM, DWORD dwTime) = 0;
	virtual void MoveStepStop() = 0;
	virtual void SetSpeed(_eAxis eAxis, DWORD dwSpeed) = 0;
	virtual void SetSpeed300(_eAxis eAxis, DWORD dwPercent) = 0;
	virtual void SetSpeed100(_eAxis eAxis, DWORD dwPercent) = 0;
	virtual bool IsPossibleMovingX(DWORD dwTargte) = 0;
	virtual bool IsPossibleMovingY(DWORD dwTargte) = 0;
	virtual bool IsPossibleMovingZ(DWORD dwTargte) = 0;

public:
	virtual bool IsIOInEmergency() = 0;
	virtual bool IsIOInStart() = 0;
	virtual bool IsIOInSafe() = 0;
	virtual bool IsIOInAirPressure() = 0;
	virtual bool IsIOInServoPower() = 0;
	virtual bool IsIOInWorkLeft1() = 0;
	virtual bool IsIOInWorkLeft2() = 0;
	virtual bool IsIOInWorkRight1() = 0;
	virtual bool IsIOInWorkRight2() = 0;
	virtual bool IsIOInDoorRear() = 0;
	virtual void EnableSafeSensor(bool b) = 0;
	virtual void NeglectSafeSensor(bool b) = 0;

public:
	virtual void IOOutClamp(bool bOn) = 0;
	virtual void IOOutLight(bool bOn) = 0;
	virtual void IOOutTowerError(bool bOn) = 0;
	virtual void IOOutTowerRuning(bool bOn) = 0;
	virtual void IOOutTowerIdle(bool bOn) = 0;
	virtual void IOOutTowerBuzzer(bool bOn) = 0;

public:
	virtual bool IsIOOutClamp() = 0;
	virtual bool IsIOOutLight() = 0;
	virtual bool IsIOOutTowerError() = 0;
	virtual bool IsIOOutTowerAuto() = 0;
	virtual bool IsIOOutTowerManual() = 0;
	virtual bool IsIOOutTowerBuzzer() = 0;
};


class IMotionEvt_V1
{

public:
	enum _eError
	{
		errNone,
		errCheckMachinePower,
		errAxisX,
		errAxisY,
		errAxisZ,
		errRangeOver,
	};

public:
	virtual void EvtIMotionError(_eError err)                                                         {};
	virtual void EvtIMotionPowerOn()                                                                  {};

//public:
//	virtual void AddRef()                                                                             {};
//	virtual void Release()                                                                            {};

public:
	virtual void EvtIMotionServoOn(bool isOn)	                                                      {};  
	virtual void EvtIMotionErrorCode(long err)														  {};
	virtual void EvtIMotionErrorString(char* str)													  {};
	virtual void EvtIMotionMotionErrCod(unsigned short nConNo, unsigned short nAxisNo, long err)      {};

public:
	virtual void EvtIMotionHomingFail()                                                               {};
	virtual void EvtIMotionHomingStarted()                                                            {};
	virtual void EvtIMotionHomingDone()                                                               {};
	virtual void EvtIMotionPosChanged(long lNowX, long lNowY, long lNowZ)                             {};

public:
	virtual void EvtIMotionCardORG(DWORD dwBoard, DWORD dwAxis, bool bSet)                            {};
	virtual void EvtIMotionCardEZ(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardEMG(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardINP(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// 서보 위치 결정 완료
	virtual void EvtIMotionCardALM(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardLMTP(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardLMTM(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardRUN(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// motion 동작 수행 중
	virtual void EvtIMotionCardERR(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardHOME(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// Homing 중
	virtual void EvtIMotionCardH_OK(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionCardCCLR(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// 서보 에러(편차) 카운터 클리어
	virtual void EvtIMotionCardSON(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// 서보 on
	virtual void EvtIMotionCardARST(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};	// 서보 알람 리셋

public:
	virtual void EvtIMotionMainRun(DWORD dwBoard, DWORD dwAxis, bool bSet)                            {};
	virtual void EvtIMotionMainErr(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionMainHome(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};

public:
	virtual void EvtIMotionDrvCmpP(DWORD dwBoard, DWORD dwAxis, bool bSet)                            {};
	virtual void EvtIMotionDrvCmpM(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvASND(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvCNST(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvDSND(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvA_ASND(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionDrvA_CNST(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionDrvA_DSND(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionDrvS_ORG(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvS_EZ(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvS_LMT_P(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionDrvS_LMT_M(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionDrvALM(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionDrvEMG(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};

public:
	virtual void EvtIMotionErrSLMT_P(DWORD dwBoard, DWORD dwAxis, bool bSet)                          {};
	virtual void EvtIMotionErrSLMT_M(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHLMT_P(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHLMT_M(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrALM(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionErrEMG(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionErrHOME(DWORD dwBoard, DWORD dwAxis, bool bSet)							  {};
	virtual void EvtIMotionErrHMST_0(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHMST_1(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHMST_2(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHMST_3(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};
	virtual void EvtIMotionErrHMST_4(DWORD dwBoard, DWORD dwAxis, bool bSet)						  {};

public:
	virtual void EVTIMotionIOInputEmergency(bool bIn)                                                 {};
	virtual void EVTIMotionIOInputStart(bool bIn)                                                     {};
	virtual void EVTIMotionIOInputSafe(bool bIn)                                                      {};
	virtual void EVTIMotionIOInputAirPressure(bool bIn)                                               {};
	virtual void EVTIMotionIOInputServoPower(bool bIn)                                                {};
	virtual void EVTIMotionIOInputWorkLeft1(bool bIn)                                                 {};
	virtual void EVTIMotionIOInputWorkLeft2(bool bIn)                                                 {};
	virtual void EVTIMotionIOInputWorkRight1(bool bIn)                                                {};
	virtual void EVTIMotionIOInputWorkRight2(bool bIn)                                                {};
	virtual void EVTIMotionIOInputDoorRear(bool bIn)                                                  {};

public:
	virtual void EVTIMotionIOOutputClampSol(bool bOut)                                                {};
	virtual void EVTIMotionIOOutputLight(bool bOut)                                                   {};
	virtual void EVTIMotionIOOutputTowerError(bool bOut)                                              {};
	virtual void EVTIMotionIOOutputTowerAuto(bool bOut)                                               {};
	virtual void EVTIMotionIOOutputTowerManual(bool bOut)                                             {};
	virtual void EVTIMotionIOOutputTowerBuzzer(bool bOut)                                             {};

public:
	virtual void EVTIMotionInputORG(DWORD dwBoard, DWORD dwAxis, bool bSet)                           {};
	virtual void EVTIMotionInputEZ(DWORD dwBoard, DWORD dwAxis, bool bSet)                            {};
	virtual void EVTIMotionInputEMG(DWORD dwBoard, DWORD dwAxis, bool bSet)                           {};
	virtual void EVTIMotionInputEX_P(DWORD dwBoard, DWORD dwAxis, bool bSet)                          {};
	virtual void EVTIMotionInputEX_M(DWORD dwBoard, DWORD dwAxis, bool bSet)                          {};
	virtual void EVTIMotionInputINP(DWORD dwBoard, DWORD dwAxis, bool bSet)                           {};
	virtual void EVTIMotionInputALM(DWORD dwBoard, DWORD dwAxis, bool bSet)                           {};
	virtual void EVTIMotionInputLMT_P(DWORD dwBoard, DWORD dwAxis, bool bSet)                         {};
	virtual void EVTIMotionInputLMT_M(DWORD dwBoard, DWORD dwAxis, bool bSet)                         {};

public:
	virtual void EVTIMotionDoneX(bool bDone)                                                          {};
	virtual void EVTIMotionDoneY(bool bDone)                                                          {};
	virtual void EVTIMotionDoneZ(bool bDone)                                                          {};
																									  
};																									  

