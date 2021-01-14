

#pragma once

#include <IBase.h>
#include <fa/nccutting/Sheet.h>

class IMotion_V1;
class IMotionStep_V1;
class IEvtAutoMotionSemi_V1;
class ICamera_V2;
class IFindFirstLine_V1;
class IBufferPool;
class ICutting_V1;

class IAutoMotionSemi_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtAutoMotionSemi_V1* pI) = 0;

public:
	virtual void SetCameraInterfaces(ICamera_V2* pICamFrontLeft, ICamera_V2* pICamFrontRight, ICamera_V2* pICamRearLeft, ICamera_V2* pICamRearRight) = 0;
	virtual void SetMotionInterfaces(IMotion_V1* pIServo, IMotionStep_V1* pIStepFront, IMotionStep_V1* pIStepRear) = 0;
	virtual void SetFindFirstLine(IFindFirstLine_V1* pI) = 0;
	virtual void SetCutting(ICutting_V1* pI) = 0;

public:
	virtual void SetDelayCutting(DWORD dw) = 0;
	virtual void SetCuttingDepth(long lZOffset) = 0;
	virtual void SetFind1stLineStartPos(DWORD dwFront, DWORD dwRear) = 0;	// 첫 번째 라인 찾기를 시작할 Y 위치

public:
	virtual bool MotionStart(bool bSimul) = 0;
	virtual void MotionStop() = 0;
	virtual void MotionPause(bool bPause) = 0;
};

class IEvtAutoMotionSemi_V1
{
public:
	virtual void EvtAutoMotionSemiDone(){}
	virtual void EvtAutoMotionSemiPause(){}
	virtual void EvtAutoMotionSemiFail(){}
public:
	virtual void EvtAutoMotionSemiMove2Front(){}
	virtual void EvtAutoMotionSemiMove2Rear(){}
};
