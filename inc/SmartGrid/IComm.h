

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
		float fBatteryVolt;            // ���͸� ����
		float fBatteryCurrent;         // ���͸� ����
		float fDCPower;                // ��������
		float fACVoltU;                // ��������(U��)
		float fACVoltV;                // ��������(V��)
		float fACCurrentU;             // ��������(U��)
		float fACCurrentV;             // ��������(V��)
		float fACPower;                // ��������
		float fFreq;                   // ���ļ�
		float fDCVolt1;                // �������� 1
		float fDCVolt2;                // �������� 2
		float fTargetPowerCharge;      // �������·�����ġ
		float fTargetPowerDischarge;   // �������·�����ġ
		_eState eState;                // State of PCS
		USHORT usError1;               // ����1
		USHORT usError2;               // ����2
		float fTargetVoltCharge;       // �������� ����ġ
		float fTargetVoltDischarge;    // �������� ����ġ
		float fTargetCurrentCharge;    // �������� ����ġ
		float fTargetCurrentDischarge; // �������� ����ġ
		float fIqe_Ref;                // Iqe_Ref
		float fVdc_Ref;                // Vdc_Ref
		float fPowerEnergy;            // ���¿�������
		float fCurrentEnergy;          // ������������
		_eMode eMode;        // Charge Mode
		//float fVdc_Ref;              // �ߺ���........
	};
	struct _stSystemRead
	{
		float fESSID;                  // ESS ID
		float fCapacity;               // �뷮
		float fInputVolt;              // �����Է�����
		float fInputCurrent;           // �����Է�����
		float fInputVoltMin;           // ���������Է�����Min
		float fInputVoltMax;           // ���������Է�����Max
		float fInputCurrentMax;        // ���������Է�����Max
		float fSWVersion;              // S/W ��������
		float fSystemInputVolt;        // ������������
		float fSystemInputCurrent;     // ������������
		float fSystemInputFreq;        // �����������ļ�
		float fSwitchingFreq;          // ����Ī���ļ�
		float fSystemLevelOverVolt;    // ��������� Level
		float fSystemLevelLackVolt;    // ���������� Level
		float fSystemLevelOverCurrent; // ��������� Level
		float fSystemFreqMin;          // �������ļ� Min
		float fSystemFreqMax;          // �������ļ� Max
		float fLevelDCOverVolt;        // ���������� Level
		float fLevelDCLackVolt;        // ���������� Level
		float fLevelDCOverCurrent;     // ���������� Level
	};
	struct _stBatteryRead
	{
		float fMaxVoltCharge;          // �ִ���������
		float fMaxVoltDischarge;       // �ִ��������
		float fMaxCurrentCharge;       // �ִ���������
		float fMaxCurrentDischarge;    // �ִ��������
		float fMaxPowerCharge;         // �ִ���������
		float fMaxPowerDischarge;      // �ִ��������
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