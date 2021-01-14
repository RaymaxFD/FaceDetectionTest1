
#pragma once

#include <IBase.h>

class IString;

class IEvtH11890_V1;
class IH11890_V1 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V1* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start(bool bConti = true) = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void Capture(bool bCapture) = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(double dCapturePeriod, int iCaptureCount) = 0;

public:
	virtual void SetEvent(HANDLE hEvtCapture) = 0;
};

class IEvtH11890_V1
{
public:
	enum _eErrCode
	{
		errFailToOpen = -1,
		errOverLightDetect,
	};
public:
	virtual void EvtOnErr(_eErrCode eErr){}
	virtual void EvtDeviceOpen(bool b){}
	virtual void EvtSerialNumber1(TCHAR* pSerial){}
	virtual void EvtGateTime(DWORD dw){}
	virtual void EvtGateNumber(DWORD dw){}
	virtual void EvtHighVolatage(bool b){}
	virtual void EvtReadData(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadDone(){}
	virtual void EvtRunningDone(){}
};















//#define NO_PMT

class IEvtH11890_V2;
class IH11890_V2 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V2* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V2* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void CheckPMT() = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(DWORD dwAllCaptureRunning, DWORD dwCapturePeriod) = 0;

public:
	virtual void SetOpticalMax(DWORD dw) = 0; // 광이 dw보다 크게 들어왔을 때 다시 시도
	virtual void SetTrying2CaptureMax(BYTE uc) = 0; // 광이 크거나 0으로 들어와 다시 시도하는 횟수

#ifdef NO_PMT
public:
	virtual void SetRandomRange(int iDrug, ULONG ulMin, ULONG ulMax) = 0;
#endif

public:
	virtual void EnablePMT1(bool b) = 0;
	virtual void EnablePMT2(bool b) = 0;

public:
	virtual void SetPMTSerial1(IString* pIStr) = 0;
	virtual void SetPMTSerial2(IString* pIStr) = 0;

public:
	virtual void GetPMTSerial1() = 0;
	virtual void GetPMTSerial2() = 0;
};

class IEvtH11890_V2
{
public:
	enum _eErrCode
	{
		errFailToOpen = -1,
		errOverLightDetect,
	};
public:
	virtual void EvtOnErr(_eErrCode eErr){}
	virtual void EvtDeviceOpen(bool b){}
	virtual void EvtSerialNumber1(IString* pIStr){}
	virtual void EvtSerialNumber2(IString* pIStr){}
	virtual void EvtGateTime(DWORD dw){}
	virtual void EvtGateNumber(DWORD dw){}
	virtual void EvtHighVolatage(bool b){}
	virtual void EvtReadData1(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadData2(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadDone(){}
	virtual void EvtRunningDone(){}
};

class IEvtH11890_V3;
class IH11890_V3 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V3* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V3* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void CheckCamera() = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(double dCapturePeriod, int iCaptureCount) = 0;

public:
	virtual void SetEvent(HANDLE hEvtCapture) = 0;
};

class IEvtH11890_V3
{
public:
	enum _eErrCode
	{
		errFailToOpen = -1,
		errOverLightDetect,
	};
public:
	virtual void EvtOnErr(_eErrCode eErr){}
	virtual void EvtDeviceOpen(bool b){}
	virtual void EvtSerialNumber1(IString* pIStr){}
	virtual void EvtSerialNumber2(IString* pIStr){}
	virtual void EvtGateTime(DWORD dw){}
	virtual void EvtGateNumber(DWORD dw){}
	virtual void EvtHighVolatage(bool b){}
	virtual void EvtReadData(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadDone(){}
	virtual void EvtRunningDone(){}
};


class IEvtH11890_V4;
class IH11890_V4 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V4* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V4* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void CheckPMT() = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(DWORD dwAllCaptureRunning, DWORD dwCapturePeriod) = 0;

public:
	virtual void SetOpticalMax(DWORD dw) = 0; // 광이 dw보다 크게 들어왔을 때 다시 시도
	virtual void SetTrying2CaptureMax(BYTE uc) = 0; // 광이 크거나 0으로 들어와 다시 시도하는 횟수

#ifdef NO_PMT
public:
	virtual void SetRandomRange(int iDrug, ULONG ulMin, ULONG ulMax) = 0;
#endif

public:
	virtual void EnablePMT1(bool b) = 0;
	virtual void EnablePMT2(bool b) = 0;

public:
	virtual void SetPMTSerial(IString* pIStr) = 0;

public:
	virtual void GetPMTSerial() = 0;
};

class IEvtH11890_V4
{
public:
	enum _eErrCode
	{
		errFailToOpen = -1,
		errOverLightDetect,
	};
public:
	virtual void EvtOnErr(_eErrCode eErr){}
	virtual void EvtDeviceOpen(bool b){}
	virtual void EvtSerialNumber(IString* pIStr){}
	virtual void EvtGateTime(DWORD dw){}
	virtual void EvtGateNumber(DWORD dw){}
	virtual void EvtHighVolatage(bool b){}
	virtual void EvtReadData1(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadData2(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadDone(){}
	virtual void EvtRunningDone(){}
};

class IEvtH11890_V5;
class IH11890_V5 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V5* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V5* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void CheckPMT() = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(DWORD dwAllCaptureRunning, DWORD dwCapturePeriod) = 0;

public:
	virtual void SetOpticalMax(DWORD dw) = 0; // 광이 dw보다 크게 들어왔을 때 다시 시도
	virtual void SetTrying2CaptureMax(BYTE uc) = 0; // 광이 크거나 0으로 들어와 다시 시도하는 횟수

#ifdef NO_PMT
public:
	virtual void SetRandomRange(int iDrug, ULONG ulMin, ULONG ulMax) = 0;
#endif

public:
	virtual void EnablePMT1(bool b) = 0;
	virtual void EnablePMT2(bool b) = 0;

public:
	virtual void SetPMTSerial1(IString* pIStr) = 0;
	virtual void SetPMTSerial2(IString* pIStr) = 0;

public:
	virtual void GetPMTSerial1() = 0;
	virtual void GetPMTSerial2() = 0;
};




class IEvtH11890_V6;
class IH11890_V6 : public IBase
{
public:
	virtual void IEvtAdd(IEvtH11890_V6* pI) = 0;
	virtual void IEvtRemove(IEvtH11890_V6* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Start() = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool b) = 0;
	virtual void CheckPMT() = 0;

public:
	virtual void SetGateTime(DWORD dw) = 0;
	virtual void SetNumberOfGate(DWORD dw) = 0;
	virtual void SetHighVoltage(bool b) = 0;

public:
	virtual void ReadConfig() = 0;

public:
	virtual void Setup(DWORD dwAllCaptureRunning, DWORD dwCapturePeriod) = 0;

public:
	virtual void SetOpticalMax(DWORD dw) = 0; // 광이 dw보다 크게 들어왔을 때 다시 시도
	virtual void SetTrying2CaptureMax(BYTE uc) = 0; // 광이 크거나 0으로 들어와 다시 시도하는 횟수

#ifdef NO_PMT
public:
	virtual void SetRandomRange(int iDrug, ULONG ulMin, ULONG ulMax) = 0;
#endif

public:
	virtual void EnablePMT1(bool b) = 0;
	virtual void EnablePMT2(bool b) = 0;

public:
	virtual void SetPMTSerial1(IString* pIStr) = 0;
	virtual void SetPMTSerial2(IString* pIStr) = 0;

public:
	virtual void GetPMTSerial1() = 0;
	virtual void GetPMTSerial2() = 0;

public:
	virtual void WarmingUp() = 0;
};

class IEvtH11890_V6
{
public:
	enum _eErrCode
	{
		errFailToOpen = -1,
		errOverLightDetect,
	};
public:
	virtual void EvtOnErr(_eErrCode eErr){}
	virtual void EvtDeviceOpen(bool b){}
	virtual void EvtSerialNumber1(IString* pIStr){}
	virtual void EvtSerialNumber2(IString* pIStr){}
	virtual void EvtGateTime(DWORD dw){}
	virtual void EvtGateNumber(DWORD dw){}
	virtual void EvtHighVolatage(bool b){}
	virtual void EvtReadData1(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadData2(DWORD dwGateNumber, DWORD dwCountData){}
	virtual void EvtReadDone(){}
	virtual void EvtRunningDone(){}
};