

#pragma once

#include <IBase.h>
#include "Global.h"

class ISerial;
class IEVTComm_V1;

class IComm_V1 : public IBase
{	
public:
	enum _eState
	{
		eStateInit1 = 1,
		eStateInit2,
		eStateReady,
		eStateCharge,
		eStateDischarge,
		eStateError,
		eStateTestReady,
	};

public:
	struct _stMonitoringRead
	{
		float fBatteryVolt;            // 배터리 전압
		float fBatteryCurrent;         // 배터리 전류
		float fDCPower;                // 직류전력
		float fACVoltU;                // 교류전압(U상)
		float fACVoltV;                // 교류전압(V상)
		float fACCurrentU;             // 교류전류(U상)
		float fACCurrentV;             // 교류전류(V상)
		float fACPower;                // 교류전력
		float fFreq;                   // 주파수
		float fDCVolt1;                // 직류전압 1
		float fDCVolt2;                // 직류전압 2
		float fTargetPowerCharge;      // 충전전력량설정치
		float fTargetPowerDischarge;   // 방전전력량설정치
		_eState eState;                // State of PCS
		USHORT usError1;               // 고장1
		USHORT usError2;               // 고장2
		float fTargetVoltCharge;       // 충전전압 설정치
		float fTargetVoltDischarge;    // 방전전압 설정치
		float fTargetCurrentCharge;    // 충전전류 설정치
		float fTargetCurrentDischarge; // 방전전류 설정치
		float fIqe_Ref;                // Iqe_Ref
		float fVdc_Ref;                // Vdc_Ref
		float fPowerEnergy;            // 전력에너지량
		float fCurrentEnergy;          // 전류에너지량
		_eMode eMode;        // Charge Mode
		//float fVdc_Ref;              // 중복임........
	};
	struct _stSystemRead
	{
		float fESSID;                  // ESS ID
		float fCapacity;               // 용량
		float fInputVolt;              // 정격입력전압
		float fInputCurrent;           // 정격입력전류
		float fInputVoltMin;           // 운전가능입력전압Min
		float fInputVoltMax;           // 운전가능입력전압Max
		float fInputCurrentMax;        // 운전가능입력전류Max
		float fSWVersion;              // S/W 버전정보
		float fSystemInputVolt;        // 계통정격전압
		float fSystemInputCurrent;     // 계통정격전류
		float fSystemInputFreq;        // 계통정격주파수
		float fSwitchingFreq;          // 스위칭주파수
		float fSystemLevelOverVolt;    // 계통과전압 Level
		float fSystemLevelLackVolt;    // 계통저전압 Level
		float fSystemLevelOverCurrent; // 계통과전류 Level
		float fSystemFreqMin;          // 계통주파수 Min
		float fSystemFreqMax;          // 계통주파수 Max
		float fLevelDCOverVolt;        // 직류과전압 Level
		float fLevelDCLackVolt;        // 직류저전압 Level
		float fLevelDCOverCurrent;     // 직류과전류 Level
	};
	struct _stBatteryRead
	{
		float fMaxVoltCharge;          // 최대충전전압
		float fMaxVoltDischarge;       // 최대방전전압
		float fMaxCurrentCharge;       // 최대충전전류
		float fMaxCurrentDischarge;    // 최대방전전류
		float fMaxPowerCharge;         // 최대충전전력
		float fMaxPowerDischarge;      // 최대방전전력
	};

public:
	virtual void AddIEvent(IEVTComm_V1* pI) = 0;

public:
	virtual ISerial* GetISerial() = 0;

public:
	virtual bool MonitoringRead() = 0;
	virtual bool SystemRead() = 0;
	virtual bool BatteryRead() = 0;

public:
	virtual bool SetMaxChargeVoltage(float fVolt) = 0;
	virtual bool SetMaxDischargeVoltage(float fVolt) = 0;
	virtual bool SetMaxChargeCurrent(float fCurrent) = 0;
	virtual bool SetMaxDishargeCurrent(float fCurrent) = 0;
	virtual bool SetMaxChargePower(float fPower) = 0;
	virtual bool SetMaxDischargePower(float fPower) = 0;
public:
	virtual bool WriteChargeVoltage(float fVolt) = 0;
	virtual bool WriteDischargeVoltage(float fVolt) = 0;
	virtual bool WriteChargeCurrent(float fCurrent) = 0;
	virtual bool WriteDischargeCurrent(float fCurrent) = 0;
	virtual bool WriteChargePower(float fPower) = 0;
	virtual bool WriteDischargePower(float fPower) = 0;
public:
	virtual bool StartCharge() = 0;
	virtual bool StartDischarge() = 0;
	virtual bool Stop() = 0;
	virtual bool ResetPCS() = 0;
public:
	virtual bool SetMode(_eMode eMode) = 0;
};

class IEVTComm_V1
{
public:
	virtual void IEVTCommMonitoringRead(IComm_V1::_stMonitoringRead& st){}
	virtual void IEVTCommSystemRead(IComm_V1::_stSystemRead& st){}
	virtual void IEVTCommBatteryRead(IComm_V1::_stBatteryRead& st){}
};