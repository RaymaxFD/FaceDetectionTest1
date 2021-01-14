

#pragma once
#include <IWorker.h>
#include <debug.h>

class ISystemInfoEvt;
class ISystemInfo : public IWorker
{
public:
	enum _eType
	{
		Win32_HardDisks,
		Win32_MainBoard,
		Win32_BIOS,
		Win32_OperatingSystem_Name,
		Win32_Processor,
		Win32_NetworkAdapterConfiguration,
		Win32_ComputerSystem,
	};

public:
	struct _stHardDisk
	{
		TCHAR strDeviceID[_MAX_DRIVE];
		TCHAR strVolumeName[_MAX_PATH];
		TCHAR strVolumeSerialNumber[_MAX_PATH];
		TCHAR strFreeSpace[_MAX_PATH];
		TCHAR strSize[_MAX_PATH];
		TCHAR strDriveType[_MAX_PATH];
	};
	struct _stMainBoard
	{
		TCHAR strManufacturer[_MAX_PATH];
		TCHAR strProduct[_MAX_PATH];
	};
	struct _stBios
	{
		TCHAR strCaption[_MAX_PATH];
		TCHAR strManufacturer[_MAX_PATH];
		TCHAR strSerialNumber[_MAX_PATH];
	};
	struct _stProcessor
	{
		TCHAR strProcessorId[_MAX_PATH];
		TCHAR strCaption[_MAX_PATH];
		TCHAR strName[_MAX_PATH];
		long lNumberOfCores;
		long lProcessorType;
		TCHAR strVersion[_MAX_PATH];
	};
	struct _stNetwork
	{
		TCHAR strMacAddr[_MAX_PATH];
		TCHAR strIP[_MAX_PATH];
		bool bEnabled;
	};
	struct _stSystem
	{
		TCHAR strSystemDomain[_MAX_PATH];
		TCHAR strSystemName[_MAX_PATH];
		TCHAR strSystemPrimaryOwnerName[_MAX_PATH];
		TCHAR strSystemUserName[_MAX_PATH];
	};

public:
	virtual void SetType(_eType eType) = 0;

public:
	virtual void GetHardDisk() = 0;
	virtual void GetMainBoard() = 0;
	virtual void GetBIOS() = 0;
	virtual void GetOSName() = 0;
	virtual void GetProcessor() = 0;
	virtual void GetNetworkAdapter() = 0;
	virtual void GetComputerInfo() = 0;

public:
	virtual void AddIEvent(ISystemInfoEvt* pIEvt) = 0;
	virtual void RemoveIEvent(ISystemInfoEvt* pIEvt) = 0;
};

class ISystemInfoEvt
{
public:
	virtual void EvtHardwareInfoQuery(TCHAR str[MAX_PATH])                                                                                                                                                       {}
	virtual void EvtHardwareInfoError(HRESULT hr)                                                                                                                                                                {}

	virtual void EvtHardwareInfoHardDisk(TCHAR strDeviceID[_MAX_DRIVE],	TCHAR strVolumeName[_MAX_PATH], TCHAR strVolumeSerialNumber[_MAX_PATH], TCHAR strFreeSpace[_MAX_PATH], TCHAR strSize[_MAX_PATH], TCHAR strDriveType[_MAX_PATH])    {}
	virtual void EvtHardwareInfoMainBoard(TCHAR strManufacturer[_MAX_PATH], TCHAR strProduct[_MAX_PATH])                                                                                                         {}
	virtual void EvtHardwareInfoBIOS(TCHAR strCaption[_MAX_PATH], TCHAR strManufacturer[_MAX_PATH], TCHAR SerialNumber[_MAX_PATH])                                                                               {}	
	virtual void EvtHardwareInfoOSName(TCHAR str[_MAX_PATH])                                                                                                                                                     {}
	virtual void EvtHardwareInfoProcessor(TCHAR strProcessorId[_MAX_PATH], TCHAR strCaption[_MAX_PATH], TCHAR strName[_MAX_PATH], long lNumberOfCores, long lProcessorType, TCHAR strVersion[_MAX_PATH])         {}
	virtual void EvtHardwareInfoNetwork(TCHAR strMacAddr[_MAX_PATH], TCHAR strIP[_MAX_PATH], bool bEnabled)                                                                                                      {}
	virtual void EvtHardwareInfoSystem(TCHAR strSystemDomain[_MAX_PATH], TCHAR strSystemName[_MAX_PATH], TCHAR strSystemPrimaryOwnerName[_MAX_PATH], TCHAR strSystemUserName[_MAX_PATH])                         {}

	virtual void EvtHardwareInfoHardDisk(ISystemInfo::_stHardDisk& st) {}
	virtual void EvtHardwareInfoMainBoard(ISystemInfo::_stMainBoard& st) {}
	virtual void EvtHardwareInfoBIOS(ISystemInfo::_stBios& st) {}
	//virtual void EvtHardwareInfoOSName(TCHAR str[_MAX_PATH]) {}
	virtual void EvtHardwareInfoProcessor(ISystemInfo::_stProcessor& st) {}
	virtual void EvtHardwareInfoNetwork(ISystemInfo::_stNetwork& st) {}
	virtual void EvtHardwareInfoSystem(ISystemInfo::_stSystem& st) {}

	virtual void EvtHardwareInfoBegin(ISystemInfo::_eType eType)                                                                                                                                                 {}
	virtual void EvtHardwareInfoCompleted(ISystemInfo::_eType eType)                                                                                                                                             {}
};

