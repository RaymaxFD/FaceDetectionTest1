
#pragma once

#include <IBase.h>
#include <fa/nccutting/IMotion.h>

class IEvtFindZeroPosition_V1;
class IFindZeroPosition_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtFindZeroPosition_V1* pI) = 0;

public:
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void SetIServo(IMotion_V1* pI) = 0;

public:
	virtual void Start() = 0;
};

class IEvtFindZeroPosition_V1
{
public:
	virtual void OnFoundFrontZeroPosition(DWORD dwPos){}
	virtual void OnFoundRearZeroPosition(DWORD dwPos){}
};