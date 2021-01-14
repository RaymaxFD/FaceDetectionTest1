#pragma once

#include <IWorker.h>

class IEvtRemocon;

class IRemocon : public IWorker
{
public:
	virtual void IEvtAdd(IEvtRemocon* pI) = 0;
	virtual void IEvtRemove(IEvtRemocon* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool OpenPort(BYTE ucPort) = 0;
	virtual void ClosePort() = 0;
};

class IEvtRemocon
{
public:
	enum _eKey
	{
		eKeyNone,
		eKeyPower,
		eKeyMute,
		eKeyPrev,
		eKeyNext,
		eKeyBP,
		eKeyOxi,
		eKeyTemper,
		eKeyIntro,
		eKeyHome,
		eKeyOrientation,
		eKeyFieldExercise,
		eKeyReview,
	};

public:
	virtual void OnConnection(bool bSucc) {}
	virtual void OnRemocon(_eKey) {}
};
