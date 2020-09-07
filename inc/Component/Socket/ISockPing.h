#pragma once

#include <IWorker.h>

class IString;
class IEvtSockPing;
class ISockPing : public IWorker
{
public:
	virtual void IEvtAdd(IEvtSockPing* pI) = 0;
	virtual void IEvtRemove(IEvtSockPing* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void Ping(IString* pIStr) = 0;
};

class IString;

class IEvtSockPing
{
public:
	virtual void IEvtSockPingHostNotFound(IString* pIStrIP) {}
	virtual void IEvtSockPingTimeOut(IString* pIStrIP) {}
	virtual void IEvtSockPingFound(IString* pIStrIP) {}
	virtual void IEvtSockFinish(IString* pIStrIP) {}
	virtual void IEvtSockError(IString* pIStrError) {}
};
