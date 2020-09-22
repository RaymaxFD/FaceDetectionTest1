
#pragma once

#include <IWorker.h>

class IBufferPool;
class IBuffer;
class IEvtSockServer;
class ISockServer : public IWorker
{
public:
	virtual void IEvtAdd(IEvtSockServer* pI) = 0;
	virtual void IEvtRemove(IEvtSockServer* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void ServerOpen(int iPort) = 0;
	virtual void ServerClose() = 0;

public:
	virtual void SetPool4Recv(IBufferPool* pI) = 0;

public:
	virtual void Send(UINT_PTR sock, IBuffer* pIBuff) = 0;

public:
	virtual void Kill(UINT_PTR sock) = 0;
};

class IEvtSockServer
{
public:
	virtual void OnServerStarted(){}
	virtual void OnServerStartFail(){}
	virtual void OnServerNewClient(UINT_PTR sock){}
	virtual void OnServerRecieved(UINT_PTR sock, IBuffer* pIBuff){}
	virtual void OnServerDisconnected(UINT_PTR sock){}
};