
#pragma once

#include <IWorker.h>
#include <media/IMedia.h>

class IDB_V1;
class IDB_V2;
class IDB_V3;
class IString;

class IEvtRecording
{
public:
	virtual void EvtRecording_FileSizeZero_V3(DWORD dwIDMedia) {}
	virtual void EvtRecording_Started_V3(DWORD dwIDMedia) {}
	virtual void EvtRecording_Stop_V3(DWORD dwIDMedia) {}

public:
	virtual void EvtRecording_NoDrive(DWORD dwIDMedia) {}
};

//IRecording_Vx 시리즈는 디스크 마진을 체크하는 기능이 읎음.
//INVR_Vx 시리즈를 그래서 만듬.
class IRecording_V1 : public IWorker, public IMedia
{
public:
	virtual void SetDrive(TCHAR ucDrive) = 0;
	virtual void SetRoot(TCHAR (&strRoot)[MAX_PATH]) = 0;
	virtual void SetCamName(TCHAR (&strName)[MAX_PATH]) = 0;
	virtual void SetCamModel(DWORD dwIDCam) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;

public:
	virtual void PrepareMedia() = 0;
	virtual void Start(DWORD dwIDMedia) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetIDB(IDB_V1* pIDB) = 0;
};

class IRecording_V2 : public IWorker, public IMedia
{
public:
	virtual void SetDrive(TCHAR ucDrive) = 0;
	virtual void SetRoot(TCHAR (&strRoot)[MAX_PATH]) = 0;
	virtual void SetCamName(TCHAR (&strName)[MAX_PATH]) = 0;
	virtual void SetCamModel(DWORD dwIDCam) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;

public:
	virtual bool PrepareMedia() = 0;
	virtual bool Start(DWORD dwIDMedia) = 0;
	virtual void Stop() = 0;

public:
	virtual void DiskFull(bool b) = 0;

public:
	virtual void SetIDB(IDB_V2* pIDB) = 0;
};

class IRecording_V3 : public IWorker, public IMedia
{
public:
	virtual void IEventAdd(IEvtRecording* pI) = 0;
	virtual void IEventRemove(IEvtRecording* pI) = 0;
	virtual void IEventReset() = 0;
public:
	virtual void SetDrive(TCHAR ucDrive) = 0;
	virtual void SetRoot(TCHAR (&strRoot)[MAX_PATH]) = 0;
	virtual void SetChName(TCHAR (&strChName)[MAX_PATH]) = 0;
	virtual void SetCamName(TCHAR (&strName)[MAX_PATH]) = 0;
	virtual void SetCamModel(DWORD dwIDCam) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;

public:
	virtual void PrepareMedia(int nCh) = 0;
	virtual void Start(DWORD dwIDMedia) = 0;
	virtual void Stop() = 0;

public:
	virtual void DiskFull(bool b) = 0;

public:
	virtual void SetIDB(IDB_V3* pIDB) = 0;
};

class IRecording_V4 : public IWorker, public IMedia
{
public:
	virtual void IEvtAdd(IEvtRecording* pI) = 0;
	virtual void IEvtRemove(IEvtRecording* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void CreateNVR(DWORD dwMaxChannel) = 0;

public:
	virtual void DriveAdd(TCHAR ucDrive) = 0;
	virtual void DriveRemove(TCHAR ucDrive) = 0;
	virtual void DriveReset() = 0;
	virtual void SetDiskMargin(TCHAR ucDrive, DWORD dwMarginGB) = 0;
	virtual void SetRootFolder(IString* pIStr) = 0;

public:
	virtual void EnableRecording(bool bRecording) = 0;

public:
	virtual void SetIDB(IDB_V3* pIDB) = 0;
};

class IEvtCustomVideoFileRecording
{
public:
	enum _eErrorCode
	{
		eErrICVFRNone,
		eErrICVFRRecordingStartFail,
	};

public:
	virtual void EvtSavedPosVID(DWORD dwHigh, DWORD dwLow) { ASSERT(0); }
	virtual void EvtOnError(_eErrorCode eError) {}
};

//ICustomVideoFileRecording_Vx 시리즈는 파일에 단순 저장만
class ICustomVideoFileRecording_V1 : public IWorker, public IMedia
{
public:
	virtual void AddIEvent(IEvtCustomVideoFileRecording* pI) = 0;
	virtual void RemoveIEvent(IEvtCustomVideoFileRecording* pI) = 0;
	virtual void ResetIEvent(IEvtCustomVideoFileRecording* pI) = 0;

public:
	virtual bool CreateFileVID(TCHAR (strFile)[MAX_PATH]) = 0;
	virtual void CloseFileVID() = 0;

public:
	virtual void GetFilePointer(DWORD& dwHigh, DWORD& dwLow) = 0;
};

class ICustomVideoFileRecording_V2 : public IWorker, public IMedia
{
public:
	virtual void AddIEvent(IEvtCustomVideoFileRecording* pI) = 0;
	virtual void RemoveIEvent(IEvtCustomVideoFileRecording* pI) = 0;
	virtual void ResetIEvent(IEvtCustomVideoFileRecording* pI) = 0;

public:
	virtual void CreateFileVID(IString* pIStr) = 0;
	virtual void CloseFileVID() = 0;

public:
	virtual void GetFilePointer(LARGE_INTEGER& liNfs) = 0;
	virtual void SetFilePointer(LARGE_INTEGER& liNfs) = 0;

public:
	virtual void SetPosCnt(DWORD dwCnt) = 0;

public:
	virtual IString* GetFileName() = 0;

public:
	virtual bool IsRecording() = 0;
};
