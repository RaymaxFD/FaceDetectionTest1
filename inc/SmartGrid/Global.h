

#pragma once

#include <WTypes.h>

enum _eMode
{
	eCC,
	eCV,
	eCP,
};

// 이행 조건
struct _stCheckingConditions
{
	bool bCheckingVoltHigh;
	float fCheckingVoltHigh;
	
	bool bCheckingVoltLow;
	float fCheckingVoltLow;
	
	bool bCheckingSOCHigh;
	float fCheckingSOCHigh;
	
	bool bCheckingSOCLow;
	float fCheckingSOCLow;
	
	bool bCheckingCapacityHigh;
	float fCheckingCapacityHigh;
	
	bool bCheckingCapacityLow;
	float fCheckingCapacityLow;

	DWORD dwIteration;
};

// charge/discharge/rest
struct _stProcess
{
	_eMode eMode;
	float fMode;

	bool bTargetVoltHigh;
	float fTargetVoltHigh;

	bool bTargetVoltLow;
	float fTargetVoltLow;

	bool bTargetCurrent;
	float fTargetCurrent;

	bool bTargetTime;
	DATE dtTargetTime;

	bool bTargetCapacity;
	float fTargetCapacity;

	bool bTargetWattHour;
	float fTargetWattHour;

	bool bTargetPower;
	float fTargetPower;

	bool bTargetSOCHigh;
	float fTargetSOCHigh;

	bool bTargetSOCLow;
	float fTargetSOCLow;
};
