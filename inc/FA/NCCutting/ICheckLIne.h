
#pragma once

#include <IBase.h>

#include <fa/nccutting/ICamera.h>
class IMotion_V1;
class IEvtCheckLine_V1;
class IPatternMatching_V1;

class ICheckLine_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtCheckLine_V1* pI) = 0;

public:
	virtual void SetIServo(IMotion_V1* pI) = 0;
	virtual void SetICam(ICamera_V2::_eCamIndex eCam, ICamera_V2* pI) = 0;
	virtual void SetROI(RECT& rt) = 0;
	virtual void SetPatternFile(ICamera_V2::_eCamIndex eCam, TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void SetIPatternMatching(IPatternMatching_V1* pI) = 0;

public:
	virtual void CheckLinePos(ICamera_V2::_eCamIndex eCam) = 0;
};

class IEvtCheckLine_V1
{
public:
	virtual void IEvtCheckLineFound(ICamera_V2::_eCamIndex eCam, long lCenterY){}
};
