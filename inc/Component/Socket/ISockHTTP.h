
#pragma once
#include <IWorker.h>

class IBufferPool;
class IBuffer;

class IEvtSockHTTP
{
public:
	virtual void IEvtSockHTTPData(IBuffer* pIBuff){}
};

class ISockHTTP_V1 : public IWorker
{
public:
	virtual void IEvtAdd(IEvtSockHTTP* pI) = 0;
	virtual void IEvtRemove(IEvtSockHTTP* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual void Request(TCHAR* pStrURL) = 0;
};