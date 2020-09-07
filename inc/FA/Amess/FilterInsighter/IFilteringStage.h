
#pragma once

#include <IBase.h>

class IEvtFilteringStage_V1;
class IAlphaMotionBA432P_V1;
class IAxis_V1;

class IFilteringStage_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilteringStage_V1* pI) = 0;

public:
	virtual void SetIAlphaMotionBA432P(IAlphaMotionBA432P_V1* pI) = 0;
	virtual void SetAxis(IAxis_V1* pIX, IAxis_V1* pIY) = 0;

public:
	virtual void SetOrgX(long lX) = 0;
	virtual void SetOrgY(long lY) = 0;
	virtual void SetPitchX(long lX) = 0;
	virtual void SetPitchY(long lY) = 0;
	virtual void PreparePos() = 0;
	virtual void SetMaxBinCount(long lMax) = 0;

public:
	virtual bool Action(long lPos) = 0;
};

class IEvtFilteringStage_V1
{
public:
	virtual void EvtFilteringDone()                     {}
	virtual void EvtFilterBiinFulled(long lBin)         {}
};

