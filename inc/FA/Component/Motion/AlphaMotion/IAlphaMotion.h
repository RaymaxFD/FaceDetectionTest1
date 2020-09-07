
#pragma once


#include <IBase.h>

class IEvtAlphaMotionBA432P_V1;
class IAxis_V1;

class IAlphaMotionBA432P_V1 : public IBase
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
	virtual void SetMotionCardNo(USHORT usCard) = 0;

public:
	virtual void StartServo() = 0;
	virtual void StopServo() = 0;

public:
	virtual void AddIEvent(IEvtAlphaMotionBA432P_V1* pI) = 0;

public:
	virtual void SetSWLimit(_eAxis eAxis, long lMax, long lMin) = 0;

public:
	virtual bool IsEmergency(USHORT usAxis) = 0;
	virtual bool IsAlarm(USHORT usAxis) = 0;
	virtual bool IsLimitP(USHORT usAxis) = 0;
	virtual bool IsLimitM(USHORT usAxis) = 0;
	virtual bool IsOrg(USHORT usAxis) = 0;
	virtual bool IsInpos(USHORT usAxis) = 0;
	virtual bool IsAmp(USHORT usAxis) = 0;

public:
	virtual void SetAmp(USHORT usAxis, bool bState) = 0;
	virtual void SetHomeVelProf(USHORT usAxis, double dVel, double dTacc, double dTec) = 0;
	virtual void SetJogVelProf(USHORT usAxis, double& dVel, double dTacc) = 0;
	virtual void SetVelProf(USHORT usAxis, double dVel, double dTacc, double dTdec) = 0;
	virtual void SetOriginPos(USHORT usAxis, long lPos) = 0;
	virtual void SetServoReset(USHORT usAxis, DWORD dwDelay) = 0;

public:
	virtual bool Homing(_eAxis eAxis) = 0;

public:
	virtual bool MoveInc(_eAxis eAxis, long lPos) = 0;
	virtual bool MoveAbs(_eAxis eAxis, long lPos) = 0;
	virtual bool MoveJog(_eAxis eAxis, _eDir eDir) = 0;
	virtual void MoveStop(_eAxis eAxis) = 0;
	virtual void MoveInterpolation(int (&iAxis)[4], long (&lTarget)[4]) = 0;

public:
	virtual long GetCmdPos(_eAxis eAxis) = 0;
	virtual long GetActPos(_eAxis eAxis) = 0;
	virtual bool GetHomeVelProf(_eAxis eAxis, double& dVel, double& dTacc, double& dTdec) = 0;
	virtual bool GetJogVelProf(_eAxis eAxis, double& dVel, double& dTacc) = 0;
	virtual bool GetVelProf(_eAxis eAxis, double& dVel, double& dTacc, double& dTdec) = 0;

public:
	virtual void Output(long lPort, long lPin, bool bOut) = 0;

public:
	virtual bool IsInput(long lPort, long lPin) = 0;
	virtual unsigned int DiGetData() = 0;

	virtual bool IsOutput(long lPort, long lPin) = 0;
	virtual unsigned int DoGetData() = 0;

public:
	virtual IAxis_V1* GetIAxis(_eAxis eAxis) = 0;
};


class IEvtAlphaMotionBA432P_V1
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

public:
	virtual void EvtInputChaned(unsigned int uiInput)								  {}
	virtual void EvtOutputChaned(unsigned int uiOutput)	        					  {}
};
