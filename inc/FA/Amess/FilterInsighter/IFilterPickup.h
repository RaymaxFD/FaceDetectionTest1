
#pragma once

#include <IBase.h>

class IEvtFilterPickup_V1;
class IAlphaMotionBA432P_V1;
class IIO_V1;
class ICylinder_V1;

class IFilterPickup_V1 : public IBase
{
public:
	virtual void SetIIO(IIO_V1* pI) = 0;
	virtual void SetIAlphaMotionBA432P(IAlphaMotionBA432P_V1* pI) = 0;
	virtual void SetCylinder1(ICylinder_V1* pI) = 0;

public:
	virtual void AddIEvent(IEvtFilterPickup_V1* pI) = 0;

public:
	virtual void SetPosLineFeeder(long lPos) = 0;
	virtual void SetPosVisionStage(long lPos) = 0;
	virtual void SetVacuumOnDelayTime(long lms) = 0;
	virtual void SetCylUpDelayTime(long lms) = 0;
	virtual void SetPosOrigin(long lPos) = 0;

public:
	virtual bool Action() = 0;
	virtual bool IsIdle() = 0;
};

class IEvtFilterPickup_V1
{
public:
	virtual void EvtFilterPickupDone()                    {}
};
