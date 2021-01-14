
#pragma once

#include <IBase.h>
#include <fa/nccutting/ICamera.h>
#include <fa/nccutting/IMotion.h>

class IEvtLineFindRough_V1;
class IMotion_V1;

class IFindLineRough_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtLineFindRough_V1* pI) = 0;

public:
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void SetMotion(IMotion_V1* pIMotion) = 0;
	virtual void SetICamera(ICamera_V2::_eCamIndex eCam, ICamera_V2* pICam) = 0;
	virtual void SetStartFront(DWORD dwPos) = 0;
	virtual void SetStartRear(DWORD dwPos) = 0;
	virtual bool FindRough() = 0;

public:
	virtual void Teaching(RECT rtROI) = 0;
};

class IEvtLineFindRough_V1
{
public:
	virtual void FoundLeft(DWORD dwPos) = 0;
	virtual void FoundRight(DWORD dwPos) = 0;
	virtual void FoundDone() = 0;
};

class IEvtLineFindFine_V1;

class IFindLineFine_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtLineFindFine_V1* pI) = 0;

public:
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void SetMotion(IMotion_V1* pIMotion) = 0;
	virtual void SetICamera(ICamera_V2::_eCamIndex eCam, ICamera_V2* pICam) = 0;
	virtual void SetStartFront(DWORD dwPos) = 0;
	virtual void SetStartRear(DWORD dwPos) = 0;
	virtual bool FindFine(DWORD dwRough) = 0;

public:
	virtual void SetPatternFileLeft(char* strPattern) = 0;
	virtual void SetPatternFileRight(char* strPattern) = 0;

public:
	virtual void ResetRoughPos() = 0;
	virtual void AddRoughPos(DWORD dwPos) = 0;
};

class IEvtLineFindFine_V1
{
public:
	virtual void FoundLeft(DWORD dwPos) = 0;
	virtual void FoundRight(DWORD dwPos) = 0;
};
