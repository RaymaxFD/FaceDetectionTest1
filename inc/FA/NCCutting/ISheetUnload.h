

#pragma once

#include <IBase.h>

class IEvtSheetUnload_V1;
class IMotion_V1;
class IMotionStep_V1;

class ISheetUnload_V1 : public IBase
{	
public:
	virtual void SetIMotion(IMotion_V1* pIServo) = 0;

public:
	virtual bool StartUnload() = 0;
	virtual void CancelLoad() = 0;
	virtual void PauseUnload(bool bPause) = 0;

public:
	virtual void AddIEvent(IEvtSheetUnload_V1* pI) = 0;
};

class IEvtSheetUnload_V1
{
public:
	virtual void EvtSheetUnloadYFront(){}
	virtual void EvtSheetUnloadDone(){}
};
