

#pragma once

#include <IBase.h>

#include <fa/nccutting/Sheet.h>
#include <fa/nccutting/ICamera.h>

class IMotion_V1;
class IMotionStep_V1;
class IEvtAutoMotion_V1;
class IFindFirstLine_V1;
class IPatternMatching_V1;
class ICutting_V1;
class ICheckTwoLines_V1;

class IAutoMotion_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtAutoMotion_V1* pI) = 0;

public:
	virtual void SetMotionInterfaces(IMotion_V1* pIServo, IMotionStep_V1* pIStepFront, IMotionStep_V1* pIStepRear) = 0;
	//virtual void SetFindFirstLine(IFindFirstLine_V1* pI) = 0;
	virtual void SetICheckTwoLinesFront(ICheckTwoLines_V1* pI) = 0;
	virtual void SetICheckTwoLinesRear(ICheckTwoLines_V1* pI) = 0;

public:
	virtual void SetSheet(_stSheet& st) = 0;
	virtual void SetDelayCutting(DWORD dw) = 0;
	virtual void SetCuttingDepth(long lDepth) = 0;
	virtual void SetCuttingSpeed(long lSpeed) = 0;
	virtual void SetFind1stLineStartPos(DWORD dwFront, DWORD dwRear) = 0;	// 첫 번째 라인 찾기를 시작할 Y 위치
	virtual void ApplyCamCutterOffset(long lOffsetFront, long lOffsetRear) = 0;
	virtual void ApplyZeroPoint(DWORD dwFront, DWORD dwRear) = 0;
	virtual void SetPatternFile(ICamera_V2::_eCamIndex eCam, TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void SetIPatternMatching(IPatternMatching_V1* pI) = 0;
	virtual void SetICamera(ICamera_V2::_eCamIndex eCam, ICamera_V2* pI) = 0;
	virtual void SetICutting(ICutting_V1* pI) = 0;
	virtual void SetMargin(int iLeft, int iTop, int iRight, int iBottom) = 0;

public:
	virtual bool MotionStart(bool bSimul) = 0;
	virtual void MotionStop() = 0;
	virtual void MotionPause(bool bPause) = 0;
};

class IEvtAutoMotion_V1
{
public:
	virtual void EvtAutoMotionDone(){}
	virtual void EvtAutoMotionPause(){}
	virtual void EvtAutoMotionFail(){}
public:
	virtual void EvtAutoMotionMove2Front(){}
	virtual void EvtAutoMotionMove2Rear(){}
public:
	virtual void EvtAutoMotionFind1stLineFrontFail(){}
	virtual void EvtAutoMotionFind1stLineRearFail(){}
public:
	virtual void EvtAutoMotionFind2ndLineFrontFail(){}
	virtual void EvtAutoMotionFind2ndLineRearFail(){}
public:
	virtual void EvtAutoMotionErrLinePos(){}
};
