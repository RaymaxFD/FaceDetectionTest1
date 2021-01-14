

#pragma once

#include <IBase.h>

#include <fa/nccutting/Sheet.h>
#include <fa/nccutting/ICamera.h>

class IEvtProcGroup_V1;
class IPatternMatching_V1;
class IFindFirstLine_V1;

class IProcGroup_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtProcGroup_V1* pI) = 0;

public:
	virtual void SetCuttingDepth(long lZOffset) = 0;
	virtual void SetDelayCutting(DWORD dwDelayCutting) = 0;
	virtual void ApplyCamCutterOffsetFront(long lOffset) = 0;
	virtual void ApplyCamCutterOffsetRear(long lOffset) = 0;
	virtual void ApplyZeroPoint(DWORD dwFront, DWORD dwRear) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;
	virtual void SetGroupOrg(DWORD dwY) = 0;
	virtual void SetGroup(_stGroup& st) = 0;
	virtual void SetCuttingPos(IMotion_V1::_eFrontRear eFrontRear, DWORD dwPos) = 0;

public:
	virtual bool StartGroup(bool bFront, bool bSimul, bool bFirstGroup) = 0;
	virtual void PauseGroup(bool bPause) = 0;
	virtual void StopGroup() = 0;
};

class IEvtProcGroup_V1
{
public:
	virtual void EvtProcGroupDone(){}
};





class IEvtProcGroup_V2;
class ICutting_V1;
class ICheckTwoLines_V1;

class IProcGroup_V2 : public IBase
{
public:
	virtual void AddIEvent(IEvtProcGroup_V2* pI) = 0;

public:
	virtual void SetCuttingDepth(long lDepth) = 0;
	virtual void SetCuttingSpeed(long lSpeed) = 0;
	virtual void SetDelayCutting(DWORD dwDelayCutting) = 0;
	virtual void ApplyCamCutterOffsetFront(long lOffset) = 0;
	virtual void ApplyCamCutterOffsetRear(long lOffset) = 0;
	virtual void ApplyZeroPoint(DWORD dwFront, DWORD dwRear) = 0;
	//virtual void SetFindFirstLine(IFindFirstLine_V1* pI) = 0;
	virtual void SetICTLFront(ICheckTwoLines_V1* pI) = 0;
	virtual void SetICTLRear(ICheckTwoLines_V1* pI) = 0;
	virtual void SetSheet(_stSheet& st) = 0;
	virtual void SetPause(bool b) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;
	virtual void SetGroupOrg(DWORD dwY) = 0;
	virtual void SetGroup(_stGroup& st) = 0;
	virtual void SetCuttingPos(IMotion_V1::_eFrontRear eFrontRear, DWORD dwPos) = 0;
	virtual void SetMargin(int iLeft, int iTop, int iRight, int iBottom) = 0; // 제품을 절단할 때의 offset. 가로/세로 방향별로 offset을 준다.
	virtual void SetPatternFile(ICamera_V2::_eCamIndex eCam, TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void SetIPatternMatching(IPatternMatching_V1* pI) = 0;
	virtual void SetICamera(ICamera_V2::_eCamIndex eCam, ICamera_V2* pI) = 0;
	virtual void SetICutting(ICutting_V1* pI) = 0;

public:
	virtual bool StartGroup(bool bFront, bool bSimul, bool bFirstGroup) = 0;
	virtual void PauseGroup(bool bPause) = 0;
	virtual void StopGroup() = 0;
	virtual void ResumeFromErrLinePos() = 0;
};

class IEvtProcGroup_V2
{
public:
	virtual void EvtProcGroupDone(){}
	virtual void EvtProcGroupErrLinePos(){}
};
