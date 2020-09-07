

#pragma once

#include <IBase.h>

class IIO_V1;
class IEvtPartFeeder_V1;

class IPartFeeder_V1 : public IBase
{
public:
	virtual void SetIIO(IIO_V1* pIIO) = 0;

public:
	virtual void AddIEvent(IEvtPartFeeder_V1* pI) = 0;

public:
	virtual bool RunFeeder() = 0;
};

class IEvtPartFeeder_V1
{
public:
	virtual void EvtStepRunBallFeederDone()                     {}
	virtual void EvtStepRunLineFeederDone()                     {}
};
