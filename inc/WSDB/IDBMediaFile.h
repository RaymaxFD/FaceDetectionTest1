
#pragma once
#include <IBase.h>

class IDBMediaFileEvt;
class IDBMediaFile : public IBase
{
public:
	struct _stMediaData
	{
		TCHAR strChannelName[256];	// 채널 이름
		LONG lChannelNumber;	// 채널 번호
		LONG lDrive;	// 0 : C, 1 : D, 2 : E.....
		//LONG m_ID;
		TCHAR strMaker[256];	// 카메라 메이커
		LONG lMediaType;	// 0 : AVI, 1 : BMP ....
		LONG lMountType;	// 0 : Standard, 1 : Ceiling, 2 : Wall, 3 : Diagonal
		LONG lRecordReason;	// 0 : User, 1 : schedule, 2 : motion detection
		DATE dtStartDateTime;	// 저장 시점
	};
	struct _stSearchData
	{
		DATE dtStart;
		DATE dtEnd;
		LONG lChannelNumber;	// 채널 번호
		LONG lRecordReason;	// 0 : User, 1 : schedule, 2 : motion detection
		LONG lMediaType;	// 0 : AVI, 1 : BMP ....
	};

public:
	virtual void MediaFileAdd(_stMediaData& st) = 0;
	virtual void Search(_stSearchData& st) = 0;
	virtual void GetMostOldOne() = 0;
	virtual void DeleteMedia(LONG lID) = 0;

public:
	virtual void SetEvent(IDBMediaFileEvt* evt) = 0;
};

class IDBMediaFileEvt
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void EvtIDBMediaFileSearch(IDBMediaFile::_stMediaData& st)	{}
	virtual void EvtIDBMediaFileSearchStart()	{}
	virtual void EvtIDBMediaFileSearchEnd()	{}

public:
	virtual void EvtIDBMediaFileGetMostOldOne(LONG lID, IDBMediaFile::_stMediaData& st)	{}
};
