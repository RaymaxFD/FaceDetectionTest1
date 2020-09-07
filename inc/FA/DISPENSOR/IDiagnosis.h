

#pragma once

#include <IBase.h>

class IDiagnosis_V1 : public IBase
{
public:
	virtual void InStart() = 0;
	virtual void InEmergency() = 0;
	virtual void InPower() = 0;
	virtual void InSafeSensor() = 0;
	virtual void InMoldLeft() = 0;
	virtual void InMoldRight() = 0;
	virtual void InAirCylindar1Front() = 0;
	virtual void InAirCylindar1Rear() = 0;
	virtual void InAirCylindar2Front() = 0;
	virtual void InAirCylindar2Rear() = 0;
	virtual void InPressure() = 0;

public:
	virtual void OutPowerLamp() = 0;
	virtual void OutSafeSensor() = 0;
	virtual void OutTowerLampError() = 0;
	virtual void OutTowerLampManualMode() = 0;
	virtual void OutTowerLampAutoMode() = 0;
	virtual void OutSol() = 0;
	virtual void OutLight() = 0;

public:
	virtual void DispensorStart() = 0;
	virtual void DispensorStop() = 0;
};

class IDiagnosisEVT_V1
{
};
