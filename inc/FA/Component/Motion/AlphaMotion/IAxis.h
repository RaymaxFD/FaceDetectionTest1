
#pragma once

#include <IBase.h>

class IEvtAxis_V1;
class IAxis_V1 : public IBase
{
public:
	enum _eStage
	{
		eError,
		eReady,
		eMoving,
		eHoming,
	};

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

public:
	virtual bool IsReady() = 0;
	virtual bool IsEmergency() = 0;
	virtual bool IsAlarm() = 0;
	virtual bool IsLimitP() = 0;
	virtual bool IsLimitM() = 0;
	virtual bool IsOrg() = 0;
	virtual bool IsInpos() = 0;
	virtual bool IsAmp() = 0;

public:
	virtual void SetAmp(bool bState) = 0;
	virtual void SetHomeVelProf(double dVel, double dTacc, double dTdec) = 0;
	virtual void SetJogVelProf(double dVel, double dTacc) = 0;
	virtual void SetVelProf(double dVel, double dTacc, double dTdec) = 0;
	virtual void SetOriginPos(long lPos) = 0;
	virtual void SetServoReset(DWORD dwDelay) = 0;

public:
	virtual void AddIEvent(IEvtAxis_V1* pI) = 0;

public:
	virtual void SetBoardNbr(USHORT usBoard) = 0;
	virtual void SetMotionNbr(USHORT usAxis) = 0;

public:
	virtual bool Homing() = 0;

public:
	virtual bool MoveAbs(long lPos) = 0;
	virtual bool MoveInc(long lInc) = 0;
	virtual bool MoveCW() = 0;
	virtual bool MoveCCW() = 0;
	virtual void Stop() = 0;

public:
	virtual long GetCmdPos() = 0;
	virtual long GetActPos() = 0;
	virtual bool GetHomeVelProf(double& dVel, double& dTacc, double& dTdec) = 0;
	virtual bool GetJogVelProf(double& dVel, double& dTacc) = 0;
	virtual bool GetVelProf(double& dVel, double& dTacc, double& dTdec) = 0;
};


class IEvtAxis_V1
{
public:
	virtual void EvtHomingDone(USHORT usAxis)                                         {}
	virtual void EvtMotionDone(USHORT usAxis)                                         {}

	virtual void EvtEmergency(USHORT usAxis, bool bEvt)								  {}
	virtual void EvtAlarm(USHORT usAxis, bool bEvt)									  {}
	virtual void EvtLimitP(USHORT usAxis, bool bEvt)								  {}
	virtual void EvtLimitM(USHORT usAxis, bool bEvt)								  {}
	virtual void EvtOrg(USHORT usAxis, bool bEvt)									  {}
	virtual void EvtInpos(USHORT usAxis, bool bEvt)									  {}
};
