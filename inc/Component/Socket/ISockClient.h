

#pragma once
#include <IWorker.h>

class ISockClientEvt;
class ISockClient : public IWorker
{
public:
	virtual bool IsConnected() = 0;
	virtual bool Connect(TCHAR* strServer, DWORD dwPort) = 0;
	virtual void Disconnect() = 0;

	virtual bool Send(BYTE* pData, DWORD dwData) = 0;

	virtual bool SetupConnectionCheckTimer(DWORD dwSec) = 0;

	virtual bool AddEvent(ISockClientEvt* p) = 0;

	virtual int GetHostIP(TCHAR (&strURL)[MAX_PATH], BYTE (&ucIP)[4]) = 0;

	virtual bool GetDestMacAddr(BYTE (&IP)[4], BYTE (&MAC)[6]) = 0;
};

class ISockClientEvt
{
public:
	virtual void OnConnected(){}
	virtual void OnDisconnected(){}
	virtual void OnConnectionFail(){}

	virtual DWORD OnReceive(BYTE* pData, DWORD dwData){	return 0;}

	virtual void OnConnectionCheckTime(){}
};
