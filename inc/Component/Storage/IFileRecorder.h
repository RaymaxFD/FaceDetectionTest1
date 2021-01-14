
#pragma once

#include <IWorker.h>
#include <IBaseGUID.h>
#include "media/imedia.h"
//#include <ibase.h>
#include <stddef.h>
#include <vfw.h>

class IString;
class IFileRecorderEVT_V1;
class IMedia;
class IWorker;
class IEvent_V1;
class IBufferPool;

class IFileRecorder_V1 : public IMedia, public IWorker
{
public:
	enum _eVideoCodec
	{
		eVideoMPG4 = 0,
		eVideoMSVC,
		eVideoDIB,
		eVideoIV50,
		eVideoH264,
		eVideoMJPG,
	};
	enum _eAudioCodec
	{
		eAudio = 0,
	};
	enum _eMountType
	{
		eMountStd,		// 비광각
		eMountCeiling,	// 카메라가 천정에 달림. 광각과 비광각에서 다르게 처리되어야 함.
		eMountWall,		// 카메라가 벽면이나 책상에 장착됨.
		eMountDiagonal,	// 카메라가 비스듬히 내려보고 있음.
	};

public:
	struct _stChannel
	{
		bool bRecord;
		TCHAR strChannel[MAX_PATH];
		TCHAR strCamMaker[MAX_PATH];
		int iWidth;
		int iHeight;
		int iBPP;
		_eVideoCodec eVideoCodec;
		_eAudioCodec eAudioCodec;
		_eMountType eMountType;
		DWORD dwFrameRate;
		DATE dtStartTime;
	};

public:
	virtual void SetIEvent(IFileRecorderEVT_V1* p) = 0;

public:
	virtual void SetMediaMode(bool bAVI = true) = 0;
	virtual bool SetChannel(DWORD dwChannel, _stChannel st) = 0;
	virtual bool GetChannel(DWORD dwChannel, _stChannel& st) = 0;
	virtual bool AddChannel(DWORD dwChannel) = 0;
	virtual bool EnableRecord(DWORD dwChannel, bool b) = 0;
	virtual void GetFileName(DWORD dwChannel, TCHAR* str, size_t len) = 0;
	/*virtual bool Open(TCHAR* strChannel, TCHAR* strMaker, 
		DWORD dwYear, DWORD dwMonth, DWORD dwDay, 
		DWORD dwHour, DWORD dwMin, DWORD dwSec, 
		int iWidth, int iHeight, int iBPP, 
		bool bAVI, _eVideoCodec eVideoCodec, _eAudioCodec eAudioCodec, _eMountType eMountType = eMountWall, 
		DWORD dwContextID = 0, DWORD dwFrameRate = 30) = 0;*/
	virtual bool ChangeDrive(TCHAR drv) = 0;
	virtual TCHAR GetDrive() = 0;
	//virtual void Close(DWORD dwChannel) = 0;
	virtual bool IsRecording(DWORD dwChannel) = 0;
};

class IFileRecorderEVT_V1
{
public:
	enum _eEventCode
	{
		eDiskFull = 1,
	};

public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void EvtRecorderError(_eEventCode e)	{}
	virtual void EvtRecorderFileChanged(DWORD dwChannel, TCHAR* pStrFile)	{}
	virtual void EvtRecorderStarted(DWORD dwChannel)	{}
	virtual void EvtRecorderStop(DWORD dwChannel)	{}
};


class IFileRecorder_V2 : public IMedia, public IWorker
{
public:
	virtual bool Open(TCHAR (&strFile)[MAX_PATH], DWORD dwFrameRate, int iWidth, int iHeight, TCHAR (&strContextName)[MAX_PATH], bool bAudio, IMedia::_eCodecVideo eCodec) = 0;
	virtual void Close() = 0;
	virtual void EnableRecording(bool bEnable = true) = 0;
};

#include <iv_macro.h>

#define STARTREC_VIDEO	(0x01)
#define STARTREC_AUDIO	(0x02)
#define LEN_AVISTREAMINFONAME	(63)

class IEvtFileRecorder_V3;
class IFileRecorder_V3 : public IMedia, public IWorker
{
public:
	struct _stAviWriteConfig
	{
		bool	_bEnableAudio;
		IMedia::_eCodecVideo		_eVideoCompression;
		int		_nMaxFrameRate;
		//	int		_nResolution;
		//	int		_nCamOutputType;
		int		_nVideoWidth;
		int		_nVideoHeight;
		TCHAR	_szCamName[LEN_AVISTREAMINFONAME + 1];
		TCHAR	_szRecordFolder[MAX_PATH];
		bool	_bAutoChkSpace;
		double	_dMinRecSpace;
	};

public:
	virtual void AddIEvent(IEvtFileRecorder_V3* pI) = 0;
	virtual void RemoveIEvent(IEvtFileRecorder_V3* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual bool StartRecording(_stAviWriteConfig& st) = 0;
	virtual void StopRecording() = 0;

public:
	virtual void SetCameraName(TCHAR (&strCam)[MAX_PATH]) = 0;
	virtual void SetDateTime(DATE dt) = 0;
	virtual void SetRootFolder(TCHAR (&strFolder)[MAX_PATH]) = 0;
	virtual void SetChannel(int iCh) = 0;
};

class IEvtFileRecorder_V3
{
public:
	virtual void IEvtRecordingStartedV3(){}
	virtual void IEvtRecordingStoped(IString* pIStr){}
	virtual void IEvtErrorOccuredV3(int iErr){}
};


class IEvtFileRecorder_V4;
class IFileRecorder_V4 : public IWorker, public IMedia
{
public:
	virtual void Open(TCHAR* str, long lW = 320, long lH = 240, BYTE FPS = 30) = 0;
	virtual void Close() = 0;
};

class IEvtFileRecorder_V4
{};

// 카메라에 접속하여 영상을 가져와 저장함.
// 가져온 영상을 IMedia 인터페이스로 흘려줌.
class IEvtFileRecorder_V5;
class IFileRecorder_V5 : public IWorker
{
public:
	struct _stDriveMargin
	{
		TCHAR ucDrive;
		ULONGLONG ullMargin;
	};

public:
	virtual void IEvtAdd(IEvtFileRecorder_V5* pI) = 0;
	virtual void IEvtRemove(IEvtFileRecorder_V5* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual void SetBufferPool(IBufferPool* pIBuff) = 0;

public:
	virtual void SetRTSPServerAddr(IString* pIStr) = 0;
	virtual void Connection(bool bConn) = 0;

public:
	virtual void EnableRecording(bool bEnable) = 0;
	virtual bool IsEnableRecording() = 0;
	virtual void SetRoot(IString* pIStr) = 0;
	virtual void SetCustomFileName(IString* pIStr) = 0;

public:
	virtual void DriveAdd(TCHAR ucDrive, DWORD dwMarginGB) = 0;
	virtual void DriveClear() = 0;
	virtual void Sweeping(bool bEnable) = 0;
};

class IEvtFileRecorder_V5
{
public:
	enum _eErrorCode
	{
		eErrConnectionFail,
		eErrFailToFindStream,
		eErrFailToFindVideoStream,
	};
public:
	virtual void IEvtRec_Connected(DWORD dwContextID) {}
	virtual void IEvtRec_ConnectionFail(DWORD dwContextID) {}
	virtual void IEvtRec_Disconnected(DWORD dwContextID) {}
	virtual void IEvtRec_PresentationTime(long lSec, DWORD dwContextID) {}
	virtual void IEvtRec_RTSPVideoSize(size_t nWidth, size_t nHeight) {}
	virtual void IEvtRec_NewFile(IString* pIStr) {}
	virtual void IEvtRec_StartStop(bool bStart) {}
	virtual void IEvtRec_DiskChanged(TCHAR ucDisk) {}
	virtual void IEvtRec_Deleted(IString* pIStr) {}
	virtual void IEvtRec_DiskFull() {}
};

// 파일명 변경
// 디스크 용량 관련 기능들이 들어 있음.
class IEvtFileRecorder_V6;
class IFileRecorder_V6 : public IWorker, public IMedia
{
public:
	virtual void SetContextID(DWORD dw) = 0;
public:
	struct _stDriveMargin
	{
		TCHAR ucDrive;
		ULONGLONG ullMargin;
	};

public:
	virtual void IEvtAdd(IEvtFileRecorder_V6* pI) = 0;
	virtual void IEvtRemove(IEvtFileRecorder_V6* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void SetBufferPool(IBufferPool* pIBuff) = 0;

public:
	virtual bool IsEnableRecording() = 0;
	virtual void SetRoot(IString* pIStr) = 0;
	virtual void SetCustomFileName(IString* pIStr) = 0;

public:
	virtual void DriveAdd(TCHAR ucDrive, DWORD dwMarginGB) = 0;
	virtual void DriveClear() = 0;
	virtual void Sweeping(bool bEnable) = 0;

public:
	virtual void RecordingStart(SIZE szVideo, BYTE ucFPS, BYTE ucGOP, IMedia::_eCodecVideo eCodec) = 0;
	virtual void RecordingStop() = 0;
};

class IEvtFileRecorder_V6
{
public:
	enum _eErrorCode
	{
		eErrConnectionFail,
		eErrFailToFindStream,
		eErrFailToFindVideoStream,
	};
public:
	virtual void IEvtRec_NewFile(IString* pIStr) {}
	virtual void IEvtRec_StartStop(bool bStart) {}
	virtual void IEvtRec_DiskChanged(TCHAR ucDisk) {}
	virtual void IEvtRec_Deleted(IString* pIStr) {}
	virtual void IEvtRec_DiskFull() {}
};


// 단순 저장만
// INVR_V1과 연동함.
class IEvtFileRecorder_V7;
class IFileRecorder_V7 : public IWorker, public IMedia
{
public:
	virtual void IEvtAdd(IEvtFileRecorder_V7* pI) = 0;
	virtual void IEvtRemove(IEvtFileRecorder_V7* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetContextID(int iID) = 0;
	virtual void MediaOpen(IString* pIStr) = 0;
	virtual void MediaClose() = 0;
	virtual bool IsMediaOpen() = 0;
	virtual IString* GetFileName() = 0;

public:
	virtual bool IsRecording() = 0;
	virtual void RecordingStart(SIZE szVideo, BYTE ucFPS, BYTE ucGOP, IMedia::_eCodecVideo eCodec) = 0;
	virtual void RecordingStop() = 0;
};

class IEvtFileRecorder_V7
{};