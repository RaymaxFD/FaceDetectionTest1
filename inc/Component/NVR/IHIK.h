#pragma once


#include <atltime.h>

#include <IWorker.h>
#include <Component/NVR/HCNetSDK.h>
#include <Component/NVR/GeneralDef.h>

class IString;

class IEvtHIK_V1;
class IHIK_V1 : public IWorker
{
public:
	enum _ePlayBackState
	{
		eStatePlay,
		eStateStop
	};

public:
	enum _ePlayEvent
	{
		eNoneEvent,
		ePlayEvent,
		eStopEvent,
		ePauseEvent,
		eFastEvent,
		eSlowEvent,
		eStepEvent
	};

public:
	virtual void AddIEvent(IEvtHIK_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtHIK_V1* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual void SetPlayBackState(_ePlayBackState eState) = 0;
	virtual BOOL IsPlayBackState() = 0;

public:
	virtual void SetPlayEvent(_ePlayEvent eEvt) = 0;
	virtual _ePlayEvent GetPlayEvent() = 0;

public:
	virtual BOOL IsPlayHandle() = 0;
	virtual BOOL IsPlayBackHandle() = 0;

public:
	virtual void SetNVRIP(CHAR* pNVRIP) = 0;
	virtual void SetNVRUser(CHAR* pNVRUser) = 0;
	virtual void SetNVRPass(CHAR* pNVRPass) = 0;
	virtual void SetNVRPort(WORD wNVRPort) = 0;

public:
	virtual CHAR* GetNVRIP() = 0;
	virtual CHAR* GetNVRUser() = 0;
	virtual CHAR* GetNVRPass() = 0;
	virtual WORD GetNVRPort() = 0;

public:
	virtual bool NVRConnect() = 0;
	virtual void NVRDisconnect() = 0;
	virtual BOOL NVRIsConnected() = 0;

public:
	virtual void NVRGetDVRConfig() = 0;
	virtual void NVRPlayChan(int nChan) = 0;
	virtual void NVRRefreshPlay() = 0;
	virtual void NVRGetSerial(BYTE (&serial)[48]) = 0;

public:	
	virtual void NVRRemoteFileList(LPNET_DVR_FindRemoteFile pFindRF) = 0;
	virtual void NVRRemoteFilePlayByName(HWND hWnd, CHAR* pFileName) = 0;
	virtual void NVRRemoteFilePlayByTime(HWND hWnd, CTime ctStart, CTime ctEnd) = 0;
	virtual BOOL NVRRemoteFileIsPlay() = 0;
	virtual void NVRRemoteFileStop() = 0;
	virtual BOOL NVRRemoteFilePlayControlV1(DWORD dwCode) = 0;
	virtual BOOL NVRRemoteFilePlayControlV2(DWORD dwCode, DWORD dwIn) = 0;
	virtual BOOL NVRRemoteFilePlayControlV3(DWORD dwCode, DWORD& dwOut) = 0;

public:
	virtual void GetSerialNumber(BYTE (&str)[48]) = 0;
};


class IEvtHIK_V1
{
public:
	virtual void EvtRemoteDeviceList(PCHANNEL_INFO pChannelInfo) {}
	virtual void EvtRemoteFileList(int nID, NET_DVR_RemoteFile& stRemoteFile) {}
	virtual void EvtRemoteFilePlayInfo(char* pBuf, int nSize, FRAME_INFO* pFrameInfo) {}
	virtual void EvtRemoteFileData(BYTE* pBuffer, DWORD dwBufSize) {}
	virtual void EvtRemoteFileListCompleted() {}
};






#include <media\IMedia.h>

class IEvtHIK_V2;
class IBufferPool;

class IHIK_V2 : public IWorker, public IMedia
{
public:
	enum _ePlayBackState
	{
		eStatePlay,
		eStateStop
	};

public:
	enum _ePlayEvent
	{
		eNoneEvent,
		ePlayEvent,
		eStopEvent,
		ePauseEvent,
		eFastEvent,
		eSlowEvent,
		eStepEvent
	};

public:
	virtual void AddIEvent(IEvtHIK_V2* pI) = 0;
	virtual void RemoveIEvent(IEvtHIK_V2* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual void SetContextID(DWORD dwContextID) = 0;

public:
	virtual void SetPlayBackState(_ePlayBackState eState) = 0;
	virtual BOOL IsPlayBackState() = 0;

public:
	virtual void SetPlayEvent(_ePlayEvent eEvt) = 0;
	virtual _ePlayEvent GetPlayEvent() = 0;

public:
	virtual BOOL IsPlayHandle() = 0;
	virtual BOOL IsPlayBackHandle() = 0;

public:
	virtual void SetNVRIP(CHAR* pNVRIP) = 0;
	virtual void SetNVRUser(CHAR* pNVRUser) = 0;
	virtual void SetNVRPass(CHAR* pNVRPass) = 0;
	virtual void SetNVRPort(WORD wNVRPort) = 0;

public:
	virtual CHAR* GetNVRIP() = 0;
	virtual CHAR* GetNVRUser() = 0;
	virtual CHAR* GetNVRPass() = 0;
	virtual WORD GetNVRPort() = 0;

public:
	virtual bool NVRConnect() = 0;
	virtual void NVRDisconnect() = 0;
	virtual BOOL NVRIsConnected() = 0;

public:
	virtual void NVRGetDVRConfig() = 0;
	virtual void NVRPlayChan(int nChan) = 0;
	virtual void NVRRefreshPlay() = 0;
	virtual void NVRGetSerial(BYTE(&serial)[48]) = 0;

public:
	virtual void NVRRemoteFileList(LPNET_DVR_FindRemoteFile pFindRF) = 0;
	virtual void NVRRemoteFilePlayByName(HWND hWnd, CHAR* pFileName) = 0;
	virtual void NVRRemoteFilePlayByTime(HWND hWnd, CTime ctStart, CTime ctEnd) = 0;
	virtual BOOL NVRRemoteFileIsPlay() = 0;
	virtual void NVRRemoteFileStop() = 0;
	virtual void NVRRemoteFilePause(bool bPause) = 0;
	virtual BOOL NVRRemoteFilePlayControlV1(DWORD dwCode) = 0;
	virtual BOOL NVRRemoteFilePlayControlV2(DWORD dwCode, DWORD dwIn) = 0;
	virtual BOOL NVRRemoteFilePlayControlV3(DWORD dwCode, DWORD& dwOut) = 0;

public:
	virtual void SetPlayingPos(BYTE ucPercent) = 0;
	virtual BYTE GetPlayingPos() = 0;
	virtual bool GetPlayingTime(SYSTEMTIME& st) = 0;
	virtual void Fast() = 0;
	virtual void Slow() = 0;
	virtual void PlayNormal() = 0;
	virtual double GetSpeedRate() = 0;
	virtual void ResetSpeedRate() = 0;
	
public:
	virtual void GetSerialNumber(BYTE(&str)[48]) = 0;

public:
	virtual void GetYUV420(bool bEnable) = 0;

public:
	virtual void SetIBufferPool(IBufferPool* pIBuff) = 0;
};


class IEvtHIK_V2
{
public:
	virtual void EvtRemoteDeviceList(PCHANNEL_INFO pChannelInfo) {}
	virtual void EvtRemoteFileList(int nID, NET_DVR_RemoteFile& stRemoteFile) {}
	virtual void EvtRemoteFilePlayInfo(char* pBuf, int nSize, FRAME_INFO* pFrameInfo) {}
	virtual void EvtRemoteFileData(BYTE* pBuffer, DWORD dwBufSize) {}
	virtual void EvtRemoteFileListCompleted() {}

public:
	virtual void EvtConnected() {}
	virtual void EvtDisconnected() {}
	virtual void EvtReconnectRequest() {}

public:
	virtual void EvtPresentationTime(long lSec, DWORD dwContextID) {}
};
