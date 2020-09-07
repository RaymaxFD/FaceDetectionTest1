#pragma once

#include <IWorker.h>

class IString;
class IEvtServer;

class IServer : public IWorker
{
public:
	virtual void IEvtAdd(IEvtServer* pI) = 0;
	virtual void IEvtRemove(IEvtServer* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SendNameThermometer(IString* pIStr) = 0;
	virtual void SendNamePulseOximeter(IString* pIStr) = 0;
	virtual void SendNameBloodPressure(IString* pIStr) = 0;

public:
	virtual void SendIDThermometer(IString* pIStr) = 0;
	virtual void SendIDPulseOximeter(IString* pIStr) = 0;
	virtual void SendIDBloodPressure(IString* pIStr) = 0;

public:
	virtual void QueryBLEs() = 0;
	virtual void BLERestart() = 0;
};

class IEvtServer
{
public:
	virtual void IEvtLogedOn() {};

	virtual void IEvtPulseOximeter(int iSpO2, int iPR) {};
	virtual void IEVTThermoMeter(double dTemp) {};
	virtual void IEvtBP(int iLow, int iHIgh) {};

	virtual void IEvtPulseOximeterID(IString* pIStr) {};
	virtual void IEvtThermoMeterID(IString* pIStr) {};
	virtual void IEvtBPID(IString* pIStr) {};
	virtual void IEvtBTName(IString* pIStr) {};
	virtual void IEvtBTID(IString* pIStr) {};
	virtual void IEvtBTSearchDone() {};
	virtual void IEvtRequestRestart() {};
};


class IEvtServer2;

class IServer2 : public IWorker
{
public:
	virtual void IEvtAdd(IEvtServer2* pI) = 0;
	virtual void IEvtRemove(IEvtServer2* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SendNameThermometer(IString* pIStr) = 0;
	virtual void SendNamePulseOximeter(IString* pIStr) = 0;
	virtual void SendNameBloodPressure(IString* pIStr) = 0;

public:
	virtual void SendIDThermometer(IString* pIStr) = 0;
	virtual void SendIDPulseOximeter(IString* pIStr) = 0;
	virtual void SendIDBloodPressure(IString* pIStr) = 0;

public:
	virtual void QueryBLEs() = 0;
	virtual void BLERestart() = 0;

public:
	virtual void SetUWPDataPath(TCHAR* pStr) = 0;
};

class IEvtServer2
{
public:
	virtual void IEvtLogedOn() {};

	virtual void IEvtPulseOximeter(int iSpO2/*, int iPR*/) {};
	virtual void IEVTThermoMeter(double dTemp) {};
	virtual void IEvtBP(int iLow, int iHIgh, int iPR) {};

	virtual void IEvtPulseOximeterID(IString* pIStr) {};
	virtual void IEvtThermoMeterID(IString* pIStr) {};
	virtual void IEvtBPID(IString* pIStr) {};
	virtual void IEvtBTName(IString* pIStr) {};
	virtual void IEvtBTID(IString* pIStr) {};
	virtual void IEvtBTSearchDone() {};
	virtual void IEvtRequestRestart() {};
};