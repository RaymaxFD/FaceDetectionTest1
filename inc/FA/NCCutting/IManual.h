
#pragma once

#include <IBase.h>

#include <fa/nccutting/IMotion.h>
#include <fa/nccutting/ICamera.h>

class IEvtManual_V1;
class IFindFirstLine_V1;
class IEvtManual_V1;
class ICutting_V1;

class IManual_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtManual_V1* pI) = 0;

public:
	virtual void SetInterfaces(IMotion_V1* pIServo, IFindFirstLine_V1* pIFindLine, ICutting_V1* pICutting) = 0;

public:
	virtual void SetOffsetFront(int iOffset) = 0;
	virtual void SetOffsetRear(int iOffset) = 0;
	virtual void SetIdle() = 0;

public:
	virtual void Move2Front() = 0;
	virtual void Move2Rear() = 0;
	virtual void FindLine(IMotion_V1::_eFrontRear eFrontRear, DWORD dwFrom, BYTE ucRetry = 3) = 0;
};

class IEvtManual_V1
{
public:
	virtual void IEvtManualV1FindLineFail(){}
	virtual void IEvtManualV1FindLineFrontDone(){}
	virtual void IEvtManualV1FindLineRearDone(){}
public:
	virtual void IEvtManualV1ProcDoc(){}
};


class IEvtManual_V2;
class ICheckTwoLines_V1;

class IManual_V2 : public IBase
{
public:
	virtual void AddIEvent(IEvtManual_V2* pI) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;
	virtual void SetICheckTwoLines(ICheckTwoLines_V1* pI) = 0;
	virtual void SetICutting(ICutting_V1* pI) = 0;
	virtual void SetCamCutterOffset(long lOffset) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;
	virtual void SetMargin(long lBefore, long lAfter) = 0;
	virtual void SetICam(ICamera_V2* pILeft, ICamera_V2* pIRight) = 0;

public:
	virtual void SetROI(RECT& rtROI) = 0;

public:
	virtual void ResetPosition() = 0;
	virtual void AddPosition(DWORD dwY) = 0;

public:
	virtual void Simulation() = 0;
	virtual bool Start() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;
};


class IEvtManual_V2
{
public:
	virtual void IEvtManualDone(){}
};
