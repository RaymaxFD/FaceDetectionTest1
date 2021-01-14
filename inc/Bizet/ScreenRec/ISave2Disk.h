

#pragma once

#include <IBase.h>

class IBuffer;
class IBufferPool;
class IEvtSave2Disk_V1;
class IDB_V1;

class ISave2Disk_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtSave2Disk_V1* pI) = 0;

public:
	virtual void SetIBuffer(IBufferPool* pI) = 0;

public:
	virtual bool SetRepositorySize(LONGLONG nSize) = 0;
	virtual void SetIDB(IDB_V1* pIDB) = 0;
	virtual void SetSleep(DWORD dwSleep) = 0;
	virtual void SetAutoSweep(bool b) = 0;

public:
	virtual bool Create(TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void Close() = 0;

public:
	virtual bool Save(IBuffer* pIBuff, DWORD dwSize, DWORD& dwHigh, DWORD& dwLow, DWORD& dwPos, bool bIFrame) = 0;

public:
	virtual void Read(DWORD dwFromHigh, DWORD dwFromLow, DWORD dwToHigh, DWORD dwToLow) = 0;
	virtual void Read(DWORD dwFromHigh, DWORD dwFromLow) = 0;
	virtual void ReadOneShot(DWORD dwFromHigh, DWORD dwFromLow) = 0;

public:
	virtual void Stop() = 0;
};

class IEvtSave2Disk_V1
{
public:
	virtual void IEvtSave2DiskDataRead(IBuffer* pI, DWORD dwSize, bool bIFrame){}
	virtual void IEvtSave2DiskReadDone(){}
	virtual void IEvtSave2DiskDiskFull(){}
};
