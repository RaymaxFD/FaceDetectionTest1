

#pragma once

#include <IBase.h>

class IEvtFireGun;
class IFireGun : public IBase
{
public:
	virtual bool OpenSerial(int iSerial, int iPort) = 0;
	virtual void CloseSerial() = 0;

public:
	virtual void IEventAdd(IEvtFireGun* pI) = 0;
	virtual void IEventRemove(IEvtFireGun* pI) = 0;
	virtual void IEventReset() = 0;
};

class IEvtFireGun
{
public:
	virtual void OnGunConnection(int iID, bool bCon){}
	virtual void OnGunGyro(int iID, int iX, int iZ){}
	virtual void OnGunButton(int iID, bool bBtn){}
};