
#pragma once

#include <winsock2.h>
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
	virtual void Send(SOCKET sock, IBuffer* pIBuff) = 0;

public:
	virtual void Kill(SOCKET sock) = 0;
};

class IEvtSockServer
{
public:
	virtual void OnServerStarted(){}
	virtual void OnServerStartFail(){}
	virtual void OnServerNewClient(SOCKET sock){}
	virtual void OnServerRecieved(SOCKET sock, IBuffer* pIBuff){}
	virtual void OnServerDisconnected(SOCKET sock){}
};