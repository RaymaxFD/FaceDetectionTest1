

#pragma once

#include <IBase.h>

class IEvtFilterTransper_V1;
class IAlphaMotionBA432P_V1;
class IIO_V1;
class ICylinder_V1;
class IAxis_V1;

class IFilterTransper_V1 : public IBase
{
public:
	virtual void SetIIO(IIO_V1* pI) = 0;
	virtual void SetIAlphaMotionBA432P(IAlphaMotionBA432P_V1* pI) = 0;
	virtual void SetICylinder2(ICylinder_V1* pI) = 0;
	virtual void SetICylinder3(ICylinder_V1* pI) = 0;
	virtual void SetIAxis(IAxis_V1* pIAxis) = 0;

public:
	virtual void AddIEvent(IEvtFilterTransper_V1* pI) = 0;

public:
	virtual void SetPosOrigin(long lPos) = 0;
	virtual void SetPosVision(long lPos) = 0;
	virtual void SetPosBuffer(long lPos) = 0;

public:
	virtual bool Action(bool bFilter1) = 0;
};


class IEvtFilterTransper_V1
{
public:
	virtual void EvtFilterTransferDone()                    {}
};

