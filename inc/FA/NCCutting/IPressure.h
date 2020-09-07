

#pragma once

#include <IBase.h>

class IEvtPresure;
class ISerial;

class IPressure : public IBase
{
public:
	virtual bool SET(USHORT usData) = 0;
	virtual bool INC() = 0;
	virtual bool DEC() = 0;
	virtual bool REQ() = 0;
	virtual bool MON() = 0;

public:
	virtual void AddIEvent(IEvtPresure* pI) = 0;
	virtual void SetISerial(ISerial* pI) = 0;
};

class IEvtPresure
{
public:
	virtual void EvtPressureSET(USHORT us){}
	virtual void EvtPressureINC(USHORT us){}
	virtual void EvtPressureDEC(USHORT us){}
	virtual void EvtPressureREQ(USHORT us){}
	virtual void EvtPressureMON(USHORT us){}
};
