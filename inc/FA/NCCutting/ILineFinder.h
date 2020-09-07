

#pragma once

#include <IBase.h>
#include <fa/nccutting/ICamera.h>
#include <fa/nccutting/IMotion.h>

class IEvtLineFinder_V1;

class ILineFinder_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtLineFinder_V1* pI) = 0;

public:
	virtual void SetPatternFile(char (&str)[MAX_PATH]) = 0;
	virtual void SetStartPosY(DWORD dwPos) = 0;
	virtual void SetCheckTime(DWORD dwTime) = 0;
	virtual void SetPagePitch(DWORD dwPitch) = 0;
	virtual void SetROI(RECT& rtROI) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pIServo) = 0;
	virtual void SetICamera(ICamera_V2::_eCamIndex eCam, ICamera_V2* pICam) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void FindLines() = 0;
};

class IEvtLineFinder_V1
{
public:
	virtual void LineFound(DWORD dwY){}
	virtual void LineFoundDone(){}
};


class IEvtLineFinder_V2;
class IPatternMatching_V1;

class ILineFinder_V2 : public IBase
{
public:
	virtual void AddIEvent(IEvtLineFinder_V2* pI) = 0;

public:
	virtual void SetIPatternMatching(IPatternMatching_V1* pI) = 0;
	virtual void SetPatternFile(char (&str)[MAX_PATH]) = 0;
	virtual void SetPagePitch(DWORD dwPitch) = 0;
	virtual void SetROI(RECT rtROI) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pIServo) = 0;
	virtual void SetICam(ICamera_V2::_eCamIndex eCam, ICamera_V2* pICam) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void FindLines() = 0;
	virtual void FindStop() = 0;
};

class IEvtLineFinder_V2
{
public:
	virtual void LineFound(ICamera_V2::_eCamIndex eCam, DWORD dwY){}
	virtual void LineFoundDone(ICamera_V2::_eCamIndex eCam){}
	virtual void LineFoundFail(){}
};
