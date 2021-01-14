
#pragma once

#include <IBase.h>

class IEvtClientMV_V1;
class IBuffer;

class IClientMV_V1 : public IBase
{
public:
	virtual void IEventAdd(IEvtClientMV_V1* pI) = 0;
	virtual void IEventRemove(IEvtClientMV_V1* pI) = 0;

public:
	virtual bool IsConnected() = 0;
	virtual bool Connect(TCHAR (&strIP)[MAX_PATH]) = 0;
	virtual void Disconnect() = 0;

public:
	virtual void QueryIdle() = 0;
	virtual bool IsIdle() = 0;
	virtual void Reset() = 0;
	virtual void StartCRC() = 0;
	virtual void Stop() = 0;
	virtual void PrepareT2D() = 0;
	virtual void PrepareTXT() = 0;
	virtual void SendScreenee(TCHAR (&strScreenee)[MAX_PATH]) = 0;
	virtual void SendScreeneeID(int iID) = 0;
	virtual void SendFile(TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void SendScreeningDate(double dt) = 0;
};

class IEvtClientMV_V1
{
public:
	virtual void IEvtClientMV_TryingToConnect(){}
	virtual void IEvtClientMV_Idle(bool bIdle){}
	virtual void IEvtClientMV_Connected(bool bConnected){}
	virtual void IEvtClientMV_ConnectFail(){}
	virtual void IEvtClientMV_MVCompleted(){}	
	virtual void IEvtClientMV_OnStateIdle(){}
	virtual void IEvtClientMV_OnStateBatch(){}
	virtual void IEvtClientMV_OnStateReArrange(){}
	virtual void IEvtClientMV_OnStateNomalize(){}
	virtual void IEvtClientMV_OnStatePareto(){}
	virtual void IEvtClientMV_OnStateWeighting(){}
	virtual void IEvtClientMV_OnStateCompleted(){}
	virtual void IEvtClientMV_OnScreeneeDone(IBuffer*){}
	virtual void IEvtClientMV_ScreeneeFileDone(){}
};
