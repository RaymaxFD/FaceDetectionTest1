#pragma once

#include <IWorker.h>

class IString;

class IEvtSockUtil;
class ISockUtil : public IWorker
{
public:
	virtual void IEvtAdd(IEvtSockUtil* pI) = 0;
	virtual void IEvtRemove(IEvtSockUtil* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool ReadMyIP(BYTE& ip0, BYTE& ip1, BYTE& ip2, BYTE& ip3) = 0;
	virtual bool GetMac(unsigned char* mac, char* dest) = 0;
	virtual bool GetName(unsigned char* name, char* dest) = 0;
	virtual void PortScan(IString* pIStrIP, UINT uiPort) = 0;
	virtual void PortScanEnd() = 0;
	virtual bool GetGateWay(BYTE (&gateway)[4]) = 0;
};

class IEvtSockUtil
{
public:
	virtual void IEvtSU_PortSuccess(IString* pIStrIP, UINT uiPort) {}
	virtual void IEvtSU_PortFail(IString* pIStrIP) {}
	virtual void IEvtSU_PortScanEnd() {}
};