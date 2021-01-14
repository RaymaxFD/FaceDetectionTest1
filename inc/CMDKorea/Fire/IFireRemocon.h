

#pragma once

#include <IBase.h>

class IEvtFireRemocon;
class IFireRemocon : public IBase
{
public:
	virtual bool OpenSerial(int iSerial, int iPort) = 0;
	virtual void CloseSerial() = 0;

public:
	virtual void IEvtAdd(IEvtFireRemocon* pI) = 0;
	virtual void IEvtRemove(IEvtFireRemocon* pI) = 0;
	virtual void IEvtReset() = 0;
};

class IEvtFireRemocon
{
public:
	virtual void OnRMCConnection(bool bCon){}
	virtual void OnRMCMenuP(){}
	virtual void OnRMCMenu1(){}
	virtual void OnRMCMenu2(){}
	virtual void OnRMCMenu3(){}
	virtual void OnRMCMenu4(){}
};