

#pragma once

#include <IBase.h>

class IBuffer;

class IEvtDB_V1;

class IDB_V1 : public IBase
{
public:
	struct _stPosition
	{
		SYSTEMTIME dt;
		ULONGLONG ullFilePos;
	};

public:
	virtual void AddIEvent(IEvtDB_V1* pI) = 0;

public:
	virtual bool OpenDB(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void CloseDB() = 0;

public:
	virtual bool AddPos(_stPosition& st) = 0;

public:
	virtual bool QueryTimeInfo() = 0;
	virtual bool QueryStart(SYSTEMTIME dtFrom) = 0;
	virtual bool QueryEnd(SYSTEMTIME dtTo) = 0;
	virtual bool QueryOneShot(SYSTEMTIME st) = 0;

public:
	virtual void SetStartingTime(double dt) = 0;
};


class IEvtDB_V1
{
public:
	virtual void OnQueryTimeInfoCount(DWORD dwCnt){}
	virtual void OnFilePos(ULONGLONG ullPos){}
	virtual void OnFilePosStart(ULONGLONG ullPos){}
	virtual void OnFilePosEnd(ULONGLONG ullPos){}
	virtual void OnQueryTimeInfo(TCHAR (&str)[MAX_PATH]){}
};
