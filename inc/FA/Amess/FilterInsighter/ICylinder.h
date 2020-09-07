

#pragma once

#include <IBase.h>

class IIO_V1;
class IEvtCylinder_V1;
class IIO_V1;

class ICylinder_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtCylinder_V1* pI) = 0;
	virtual void SetIIO(IIO_V1* pI) = 0;

public:
	virtual void SetCylNbr(long lNbr) = 0;
	virtual void SetVacuumDelayTime(long lms) = 0;
	virtual void SetCylUpDelayTime(long lms) = 0;

public:
	virtual bool Action(bool bGet = true) = 0;

public:
	virtual bool IsReady() = 0;
};


class IEvtCylinder_V1
{
public:
	virtual void EvtCylinderDone(long lCylNbr)                               {}
};
