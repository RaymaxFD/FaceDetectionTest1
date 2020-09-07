
#pragma once

#include <IBase.h>

class IEvtFindFirstLine_V1;
class IMotion_V1;
class IMotionStep_V1;
class ICamera_V2;
class IBuffer;
class IBufferPool;

class IFindFirstLine_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtFindFirstLine_V1* pI) = 0;

public:
	virtual void SetServoInterface(IMotion_V1* pIServo) = 0;
	virtual void SetCameraInterfaces(ICamera_V2* pICamFrontLeft, ICamera_V2* pICamFrontRight, ICamera_V2* pICamRearLeft, ICamera_V2* pICamRearRight) = 0;
	virtual void SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual void SetThresLevel(BYTE ucThres) = 0;
	virtual void SetCuttingLineLen(DWORD dwLen) = 0;
	virtual void SetROIWidth(DWORD dwWidth) = 0;

public:
	virtual bool Find1stLine(bool bFront, DWORD dwYFrom, bool bOneTime, BYTE ucRetry = 3) = 0;
	virtual void FindLineStop() = 0;
	virtual void SetParameter(DWORD dwLineArea, double dLineRatio) = 0;
	virtual void ResumeFromErrLinePos() = 0;
};

class IEvtFindFirstLine_V1
{
public:
	virtual void EvtFindFirstLineOk(DWORD dwY){}
	virtual void EvtFindFirstLineFail(){}
	virtual void EvtFindFirstLineLinePosErr(){}
	virtual void EvtFindFirstLineFrontDone(){}
	virtual void EvtFindFirstLineRearDone(){}
	virtual void EvtFindFirstLineStart(){}
public:
	virtual void EvtFindFirstLineThresImg(IBuffer* pILeft, IBuffer* pIRight){}

};
