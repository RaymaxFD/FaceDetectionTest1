

#pragma once

#include <IBase.h>

#include <fa/nccutting/IMotion.h>

class IEvtICutting_V1;
class IMotion_V1;

class ICutting_V1 : public IBase
{
public:
	enum _eMode
	{
		eAuto,
		eSemiAuto,
	};

public:
	virtual void AddIEvent(IEvtICutting_V1* pI) = 0;

public:
	virtual void SetMotionInterface(IMotion_V1* pI) = 0;
	virtual void SetDelayCutting(DWORD dw) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void SetCuttingDepth(long lDepth) = 0;
	virtual void SetCuttingSpeed(long lSpeed) = 0;
	virtual void ApplyZeroPoint(DWORD dwFront, DWORD dwRear) = 0;

public:
	virtual bool Start() = 0;

public:
	virtual void SetMode(_eMode eMode) = 0;
};

class IEvtICutting_V1
{
public:
	virtual void EvtICuttingDone(){}
};
