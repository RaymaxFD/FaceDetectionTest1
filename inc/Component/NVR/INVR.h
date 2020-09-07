#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IBufferPool;
class IString;
class IDB_V3;

class IEvtNVRImpl
{
public:
	virtual void IEvtRec_NewFile(DWORD dwChannel, IString* pIStr) {}
	virtual void IEvtRec_StartStop(bool bStart) {}
	virtual void IEvtRec_DiskChanged(TCHAR ucDisk) {}
	virtual void IEvtRec_Deleted(IString* pIStr) {}
	virtual void IEvtRec_DiskFull() {}
};

class IEvtNVR
{
public:
	virtual void IEvtAdd(IEvtNVRImpl* pI) = 0;
	virtual void IEvtRemove(IEvtNVRImpl* pI) = 0;
	virtual void IEvtReset() = 0;
};

// SW NVR의 구현
// PC에 일반 동영상으로 저장하고 읽어옴.
// 전용 파일 포맷으로 저장하지 아니함.
class INVR_V1 : public IWorker, public IMedia, public IEvtNVR
{
public:
	virtual void CreateNVR(DWORD dwMaxChannel) = 0;
public:
	struct _stDriveMargin
	{
		TCHAR ucDrive;
		ULONGLONG ullMargin;
	};

public:
	virtual void SetBufferPool(IBufferPool* pIBuff) = 0;

public:
	virtual bool IsEnableRecording(DWORD dwChannel) = 0;
	virtual void SetRoot(IString* pIStr) = 0;
	virtual void SetCustomFileName(IString* pIStr) = 0;

public:
	virtual void DriveAdd(TCHAR ucDrive, DWORD dwMarginGB) = 0;
	virtual void DriveClear() = 0;
	virtual void Sweeping(bool bEnable) = 0;

public:
	virtual void RecordingStart(DWORD dwChannel, SIZE szVideo, BYTE ucFPS, BYTE ucGOP, IMedia::_eCodecVideo eCodec) = 0;
	virtual void RecordingStop(DWORD dwChannel) = 0;

public:
	virtual IMedia* GetIPlayer(int iCam) = 0;
public:
	virtual void PlayBackStart(DWORD dwChannel, double dtBegin) = 0;
	virtual void PlayBackStop() = 0;
};


// SW NVR의 구현
// 전용 파일 포맷으로 저장하고 읽어 옴.
class INVR_V2 : public IWorker, public IMedia, public IEvtNVR
{
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