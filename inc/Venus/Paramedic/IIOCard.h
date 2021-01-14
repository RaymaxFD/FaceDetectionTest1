#pragma once
#include <IWorker.h>

class IEvtIOCard;
class IIOCard : public IWorker
{
public:
	virtual void IEvtAdd(IEvtIOCard* pI) = 0;
	virtual void IEvtRemove(IEvtIOCard* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool OpenPort(BYTE ucPort) = 0;
	virtual void ClosePort() = 0;

public:
	virtual void ReadIO() = 0;
};

class IEvtIOCard
{
public:
	virtual void IEvtIOCardChanged(BYTE ucIO) {}
};
