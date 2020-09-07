
#pragma once

#include <IBase.h>

class IMotion_V1;
class IMotionStep_V1;
class ITableInEvt_V1;

class ITableIn_V1 : public IBase
{
public:
	virtual void SetIMotion(IMotion_V1* pIServo, IMotionStep_V1* pIStepFront, IMotionStep_V1* pIStepRear) = 0;
	virtual void AddIEvent(ITableInEvt_V1* pI) = 0;

public:
	virtual bool StartLoad() = 0;
	virtual void CancelLoad() = 0;
	virtual void SheetOnTable() = 0;
};


class ITableInEvt_V1
{
public:
	virtual void EvtTableInEvtCamMovingOut(){}
	virtual void EvtTableInEvtYUnderFrontCutter(){}
	virtual void EvtTableInEvtDone(){}
};
