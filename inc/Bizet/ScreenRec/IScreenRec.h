

#pragma once

#include <Media/IMedia.h>
#include <IBase.h>

class IEvtScreenRec_V1;

class IScreenRec_V1 : public IBase, public IMedia
{
public:
	virtual void AddIEvent(IEvtScreenRec_V1* pI) = 0;

public:
	virtual bool SetRepositorySize(LONGLONG nSize) = 0;
	virtual void SetScanInetrval(DWORD dw) = 0;
	virtual void SetBitRate(DWORD dw) = 0;
	virtual void SetAutoSweep(bool b) = 0;

public:
	virtual bool Create(TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual void Close() = 0;

public:
	virtual bool Record() = 0;
	virtual void Stop() = 0;
	virtual bool Export(TCHAR* pStrAVIFile) = 0;

public:
	virtual bool PlayStart(SYSTEMTIME dtStart) = 0;
	virtual void PlayPause() = 0;
	virtual void PlayStop() = 0;

public:
	virtual void QueryTimeInfo() = 0;
	virtual void QueryStart(SYSTEMTIME st) = 0;
	virtual void QueryEnd(SYSTEMTIME st) = 0;

public:
	virtual void GetOneShot(SYSTEMTIME st) = 0;
};

class IEvtScreenRec_V1
{
public:
	virtual void OnQueryTimeInfoCount(DWORD dwCnt){}
	virtual void OnQueryTimeInfo(TCHAR (&str)[MAX_PATH]){}
	virtual void OnDiskFull(){}
};
