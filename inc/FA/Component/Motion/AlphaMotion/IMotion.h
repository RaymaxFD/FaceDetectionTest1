
#pragma once

#include <IBase.h>

class IEvtMotion_V1;

class IMotion_V1 : public IBase
{
public:
	enum _eAxis
	{
		AXIS_0,
		AXIS_1,
		AXIS_2,
		AXIS_3,
		AXIS_MAX,
	};

	enum _eDir
	{
		DIR_CW,
		DIR_CCW,
	};

public:
	virtual void AddIEvent(IEvtMotion_V1* pI) = 0;

public:
	virtual void SetBoardNbr(USHORT usBoard) = 0;

public:
	virtual bool Homing(USHORT usAxis) = 0;

public:
	virtual bool IsReady(USHORT usAxis) = 0;
	virtual bool IsEmergency(USHORT usAxis) = 0;
	virtual bool IsAlarm(USHORT usAxis) = 0;
	virtual bool IsLimitP(USHORT usAxis) = 0;
	virtual bool IsLimitM(USHORT usAxis) = 0;
	virtual bool IsOrg(USHORT usAxis) = 0;
	virtual bool IsInpos(USHORT usAxis) = 0;
	virtual bool IsAmp(USHORT usAxis) = 0;

public:
	virtual void SetAmp(USHORT usAxis, bool bState) = 0;
	virtual void SetHomeVelProf(USHORT usAxis, double dVel, double dTacc, double dTdec) = 0;
	virtual void SetJogVelProf(USHORT usAxis, double dVel, double dTacc) = 0;
	virtual void SetVelProf(USHORT usAxis, double dVel, double dTacc, double dTdec) = 0;

public:
	virtual bool MoveAbs(USHORT usAxis, long lPos) = 0;
	virtual bool MoveInc(USHORT usAxis, long lInc) = 0;
	virtual bool MoveCW(USHORT usAxis) = 0;
	virtual bool MoveCCW(USHORT usAxis) = 0;
	virtual void Stop(USHORT usAxis) = 0;

public:
	virtual bool InterpolationMoveAbs(int (&iAxis)[4], long (&lTarget)[4]) = 0;

public:
	virtual long GetCmdPos(USHORT usAxis) = 0;
	virtual long GetActPos(USHORT usAxis) = 0;
	virtual bool GetHomeVelProf(USHORT usAxis, double& dVel, double& dTacc, double& dTdec) = 0;
	virtual bool GetJogVelProf(USHORT usAxis, double& dVel, double& dTacc) = 0;
	virtual bool GetVelProf(USHORT usAxis, double& dVel, double& dTacc, double& dTdec) = 0;
};

class IEvtMotion_V1
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

public:
	virtual void EvtInterpolationDone()                                               {}
};
