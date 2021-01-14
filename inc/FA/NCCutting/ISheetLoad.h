

#pragma once

#include <IBase.h>

class IMotion_V1;
class IMotionStep_V1;
class ISheetLoadEvt_V1;

class ISheetLoad_V1 : public IBase
{
public:
	virtual void SetIMotion(IMotion_V1* pIServo) = 0;
	virtual void AddIEvent(ISheetLoadEvt_V1* pI) = 0;

public:
	virtual bool StartLoad() = 0;
	virtual void CancelLoad() = 0;
	virtual void PauseLoad(bool bPause) = 0;
};


class ISheetLoadEvt_V1
{
public:
	virtual void EvtSheetLoadCamMovingOut(){}
	virtual void EvtSheetLoadYReady(){}
	virtual void EvtSheetLoadYUnderFrontCutter(){}
	virtual void EvtSheetLoadDone(){}
};
