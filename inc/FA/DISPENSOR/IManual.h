

#pragma once

#include <IBase.h>

class IManualEvt_V1;
class IMotion_V1;
class IManualEvt_V2;

class IManual_V2 : public IBase
{
public:
	virtual void HomingDone() = 0;
	virtual void ReleaseSafeSensorError() = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;

public:
	virtual void AddIEvent(IManualEvt_V2* pI) = 0;

public:
	virtual bool IsDot() = 0;
	virtual bool TestRunDot() = 0;
	virtual bool TestRunLine() = 0;
	virtual void SetOffsetBetweenTipAndCamX(DWORD dwOffset) = 0;
	virtual void SetOffsetBetweenTipAndCamY(DWORD dwOffset) = 0;

public:
	virtual bool IsStateReady() = 0;
	virtual bool IsStateUnlaunch() = 0;

public:
	virtual void AddDot(POINT pt, DWORD dwTimeRemain, DWORD dwDealyStart, DWORD dwDelayEnd) = 0;
	virtual void ResetDot() = 0;
	virtual bool MoveFirstDot() = 0;
	virtual bool GetNextDot(POINT& pt, DWORD& dwTimeRemain) = 0;

public:
	virtual void AddLine(POINT ptStart, POINT ptEnd, DWORD dwTimeMoving, DWORD dwDelayStart, DWORD dwDelayEnd) = 0;
	virtual void ResetLine() = 0;
	virtual bool MoveFirstLine() = 0;
	virtual bool GetNextLine(POINT& ptStart, POINT& ptEnd, DWORD& dwTimeMoving) = 0;

public:
	virtual bool AddPathOk() = 0;

public:
	virtual void StartManual() = 0;
	virtual void StopManual() = 0;
	virtual void ZHeightOk(double dUser, double dMMD, double dFrame) = 0;
	virtual void ZHeightGet(double& dUser, double& dMMD, double& dFrame) = 0;

public:
	virtual void StartCleaning() = 0;
	virtual void SetTipClaeningHeight(double dHeight) = 0;
};

class IManualEvt_V2
{
public:
	virtual void EvtIManualTeachingStart()                                                                                                {}
	virtual void EvtIManualTeachingStop()                                                                                                 {}
	virtual void EvtIManualSebaStart()                                                                                                    {}
	virtual void EvtIManualSebaStop()                                                                                                     {}
	virtual void EvtIManualStart()                                                                                                        {}
	virtual void EvtIManualStop()                                                                                                         {}
	virtual void EvtIManualReady()                                                                                                        {}
	virtual void EvtIManualLaunch()                                                                                                       {}
	virtual void EvtIManualUnlaunch()                                                                                                     {}
	virtual void EvtIManualActionStart()                                                                                                  {}
	virtual void EvtIManualActionStop()                                                                                                   {}
	virtual void EvtIManualMoveDownImpossible()                                                                                           {}
	virtual void EvtIManualNeed2RePosZ()                                                                                                  {}
	virtual void EvtIManualNeed2ChangeCleaningCup()                                                                                       {}
};
















class IManual_V1 : public IBase
{
public:
	struct _stDISP
	{
		int iMode;	// 0 : 시작, 1 : 중간, 2 : 종료
		POINT ptPos; // 현재 위치
		DWORD dwMovingTime; // 현재 위치까지의 이동 시간.
		DWORD dwRemainTime; // 현재 위치에서 머무르는 시간.
	};

public:
	virtual void Enable(bool b) = 0;

public:
	virtual void StartManual() = 0;
	virtual void StopManual() = 0;

public:
	virtual void AddPath(_stDISP st) = 0;
	virtual void AddPathOk() = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;
	virtual void AddIEvent(IManualEvt_V1* pI) = 0;
};

class IManualEvt_V1
{
public:
	enum _eEvent
	{
		evtManualTeachingStart,
		evtManualEnd,
	};

public:
	virtual void EvtIManualV1(IManualEvt_V1::_eEvent evt)                                                                               {}

public:
	virtual void EvtIManualSebaStart()                                                                                                  {}
	virtual void EvtIManualSebaStop()                                                                                                   {}
};