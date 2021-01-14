#pragma once

#include <IWorker.h>

class IString;
class IEvtSockNetworkSearch;
class ISockNetworkSearch : public IWorker
{
public:
	struct _stIP
	{
		USHORT usIP1;
		USHORT usIP2;
		USHORT usIP3;
		USHORT usIP4;
	};

public:
	virtual void IEvtAdd(IEvtSockNetworkSearch* pI) = 0;
	virtual void IEvtRemove(IEvtSockNetworkSearch* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void Scan(_stIP stBegin, _stIP stEnd) = 0;
};

class IEvtSockNetworkSearch
{
public:
	virtual void IEvtSNS(IString* pIStrIP) {}
	virtual void IEvtSNSDone() {}
};
