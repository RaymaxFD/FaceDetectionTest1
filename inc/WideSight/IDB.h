
#pragma once

#include <IWorker.h>
#include <debug.h>

#include <map>
using namespace std;

class IEvtDB_V1;
class IEvtDB_V2;
class IEvtDB_V3;

class IString;

class IDB_V1 : public IWorker
{
public:
	struct _stCamInfo
	{
		DWORD dwID;
		TCHAR strName[MAX_PATH];
		BYTE ucIP[4];
		double dViewAngle;
		SIZE szOut;
		DWORD dwMount;
		DWORD dwIDCamModel;
		POINT ptCenter;
		DWORD dwRadius;
		TCHAR strID[MAX_PATH];
		TCHAR strPass[MAX_PATH];
	};
	struct _stCamModel
	{
		DWORD dwID;
		SIZE szFish;
		double dPixellen;
		TCHAR strName[MAX_PATH];
	};
public:
	struct _stPosition
	{
		DWORD dwIDMedia;
		SYSTEMTIME stTime;
		ULONGLONG ullFilePos;
	};
public:
	struct _stMedia
	{
		DWORD dwID;
		SYSTEMTIME stBeginTime;
		DWORD dwIDCamModel;
		DWORD dwIDCamInfo;
		TCHAR strVideoFile[MAX_PATH];
		TCHAR strAudioFile[MAX_PATH];
	};
public:
	struct _stVideoPos
	{
		DWORD dwID;
		DWORD dwIDMedia;
		SYSTEMTIME stCaptureTime;
		ULONGLONG ullFilePos;
	};

public:
	virtual void AddIEvent(IEvtDB_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtDB_V1* pI) = 0;
	virtual void ResetIEvent(IEvtDB_V1* pI) = 0;

public:
	virtual bool OpenDB(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void CloseDB() = 0;

public:
	virtual void MediaAdd(_stMedia& st) = 0;
	virtual void MediaDel(_stMedia& st) = 0;
public:
	virtual void CamInfoAdd(_stCamInfo& st) = 0;
	virtual void CamInfoEdit(_stCamInfo& st) = 0;
	virtual void CamInfoDel(_stCamInfo& st) = 0;
public:
	virtual void AddPosVideo(_stPosition& st) = 0;
	virtual void AddPosAudio(_stPosition& st) = 0;

public:
	virtual void QueryPositionVID(DWORD dwIDMedia) = 0;
	virtual void QueryPositionCntVID(DWORD dwIDMedia) = 0;
public:
	virtual void QueryMedia4Recording(TCHAR (strVID)[MAX_PATH], TCHAR (strAUD)[MAX_PATH]) = 0;
	virtual void QueryMedia4Playing(DWORD dwIDMedia) = 0;
public:
	virtual void QueryCamInfoCnt() = 0;
	virtual void QueryCamInfo() = 0;
public:
	virtual void QueryCamModelCnt() = 0;
	virtual void QueryCamModel() = 0;
public:
	virtual void QueryMediaCnt(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMedia(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
};

class IDB_V2 : public IWorker
{
public:
	struct _stPresetPos
	{
		int nSCh;
		int nPos;
		int nPosX;
		int nPosY;
	};

public:
	struct _stCamInfo
	{
		DWORD dwID;
		TCHAR strName[MAX_PATH];
		//BYTE ucIP[4];
		TCHAR strURL[MAX_PATH];
		double dViewAngle;
		SIZE szOut;
		DWORD dwMount;
		DWORD dwIDCamModel;
		POINT ptCenter;
		DWORD dwRadius;
		TCHAR strID[MAX_PATH];
		TCHAR strPass[MAX_PATH];
	};
	struct _stCamModel
	{
		DWORD dwID;
		SIZE szFish;
		double dPixellen;
		TCHAR strName[MAX_PATH];
	};
public:
	struct _stPosition
	{
		DWORD dwIDMedia;
		SYSTEMTIME stTime;
		ULONGLONG ullFilePos;
	};
public:
	struct _stMedia
	{
		DWORD dwID;
		SYSTEMTIME stBeginTime;
		DWORD dwIDCamModel;
		DWORD dwIDCamInfo;
		TCHAR strVideoFile[MAX_PATH];
		TCHAR strAudioFile[MAX_PATH];
	};
public:
	struct _stVideoPos
	{
		SYSTEMTIME stCaptureTime;
		ULONGLONG ullFilePos;
	};

public:
	virtual void AddIEvent(IEvtDB_V2* pI) = 0;
	virtual void RemoveIEvent(IEvtDB_V2* pI) = 0;
	virtual void ResetIEvent(IEvtDB_V2* pI) = 0;

public:
	virtual bool OpenDB(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void CloseDB() = 0;

public:
	virtual void MediaAdd(_stMedia& st) = 0;
	virtual void MediaDel(_stMedia& st) = 0;
	virtual void MediaDel(DWORD dwID) = 0;
public:
	virtual void CamInfoAdd(_stCamInfo& st) = 0;
	virtual void CamInfoEdit(_stCamInfo& st) = 0;
	virtual void CamInfoDel(_stCamInfo& st) = 0;

public:
	virtual void QueryMedia4Recording(TCHAR (strVID)[MAX_PATH], TCHAR (strAUD)[MAX_PATH]) = 0;
	virtual void QueryMedia4Playing(DWORD dwIDMedia) = 0;

public:
	virtual void QueryCamInfoCnt() = 0;
	virtual void QueryCamInfo() = 0;

public:
	virtual void QueryCamModelCnt() = 0;
	virtual void QueryCamModel() = 0;

public:
	virtual void QueryMediaCnt(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMedia(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
};


class IDB_V3 :  public IWorker
{
public:
#if 1
	struct _stPresetPos
	{
		int nSCh;
		int nPos;
		int nPosX;
		int nPosY;
	};
#else
	struct _stPresetPos
	{
		int nCh;
		int nSCh;
		int nPos;
		int nPosX;
		int nPosY;
	};
#endif

public:
	struct _stCamInfo
	{
		DWORD dwID;
		DWORD dwIDCamModel;
		TCHAR strName[MAX_PATH];
		int nLinkType;
		TCHAR strIP[MAX_PATH];
		int nPort;
		int nChannel;
		TCHAR strID[MAX_PATH];
		TCHAR strPass[MAX_PATH];
		SIZE szOut;
		double dViewAngle;
		DWORD dwMountType;
		POINT ptCenter;
		DWORD dwRadius;
	};

	struct _stCamModel
	{
		DWORD dwID;
		SIZE szFish;
		double dPixellen;
		TCHAR strName[MAX_PATH];
	};

public:
	struct _stPosition
	{
		DWORD dwIDMedia;
		SYSTEMTIME stTime;
		ULONGLONG ullFilePos;
	};

public:
	struct _stMedia
	{
		int nCh;
		DWORD dwID;
		SYSTEMTIME stBeginTime;
		SYSTEMTIME stEndTime;
		DWORD dwIDCamModel;
		DWORD dwIDCamInfo;
		TCHAR strVideoFile[MAX_PATH];
		TCHAR strAudioFile[MAX_PATH];
	};

public:
	struct _stVideoPos
	{
		SYSTEMTIME stCaptureTime;
		ULONGLONG ullFilePos;
	};

public:
	virtual void AddIEvent(IEvtDB_V3* pI) = 0;
	virtual void RemoveIEvent(IEvtDB_V3* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual bool OpenDB(TCHAR* str) = 0;
	virtual void CloseDB() = 0;

public:
	virtual void MediaAdd(_stMedia& st) = 0;
	virtual void MediaDel(_stMedia& st) = 0;
	virtual void MediaDel(DWORD dwID) = 0;

public:
	virtual void CamInfoAdd(_stCamInfo& st) = 0;
	virtual void CamInfoEdit(_stCamInfo& st) = 0;
	virtual void CamInfoDel(_stCamInfo& st) = 0;

public:
	virtual void QueryMedia4Recording(TCHAR (strVID)[MAX_PATH], TCHAR (strAUD)[MAX_PATH]) = 0;
	virtual void QueryMedia4Playing(DWORD dwIDMedia) = 0;

public:
	virtual void QueryCamInfoCnt() = 0;
	virtual void QueryCamInfo() = 0;

public:
	virtual void QueryCamModelCnt() = 0;
	virtual void QueryCamModel() = 0;

public:
	virtual void QueryMediaCnt(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMediaCnt(int iIDCam, int iCh, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMedia(int iIDCam, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMedia(int iIDCam, int iCh, SYSTEMTIME stFrom, SYSTEMTIME stTo) = 0;
	virtual void QueryMedia() = 0;

public:	
	virtual void DeleteMediaFileNotExist() = 0;
};




class IEvtDB_V1
{
public:
	virtual void OnQueryTimeInfoCount(DWORD dwCnt){}
	virtual void OnQueryPosition(IDB_V1::_stPosition& stPos){}
	virtual void OnQueryCamInfo(IDB_V1::_stCamInfo& stCamInfo){}
	virtual void OnQueryCamInfoCnt(DWORD dwCnt){}
	virtual void OnQueryCamModel(IDB_V1::_stCamModel& stCamInfo){}
	virtual void OnQueryCamModelCnt(DWORD dwCnt){}
	virtual void OnQueryMedia4Rec(IDB_V1::_stMedia& stMedia){}
	virtual void OnQueryMedia4Play(IDB_V1::_stMedia& stMedia){}
	virtual void OnQueryMedia(IDB_V1::_stMedia& stMedia){}
	virtual void OnQueryMediaCnt(DWORD dwCnt){}
	virtual void OnQueryVideoPos(IDB_V1::_stVideoPos& stVideoPos){}
	virtual void OnQueryVideoPosCnt(DWORD dwCnt){}
};

class IEvtDB_V2
{
public:
	virtual void OnQueryTimeInfoCount(DWORD dwCnt){}
	virtual void OnQueryPosition(IDB_V2::_stPosition& stPos){}
	virtual void OnQueryCamInfo(IDB_V2::_stCamInfo& stCamInfo){}
	virtual void OnQueryCamInfoCnt(DWORD dwCnt){}
	virtual void OnQueryCamModel(IDB_V2::_stCamModel& stCamInfo){}
	virtual void OnQueryCamModelCnt(DWORD dwCnt){}
	virtual void OnQueryMedia4Rec(IDB_V2::_stMedia& stMedia){}
	virtual void OnQueryMedia4Play(IDB_V2::_stMedia& stMedia){}
	virtual void OnQueryMedia(IDB_V2::_stMedia& stMedia){}
	virtual void OnQueryMediaCnt(DWORD dwCnt){}
	virtual void OnQueryVideoPos(IDB_V2::_stVideoPos& stVideoPos){}
	virtual void OnQueryVideoPosCnt(DWORD dwCnt){}
};

class IEvtDB_V3
{
public:
	virtual void OnQueryTimeInfoCount(DWORD dwCnt){}
	virtual void OnQueryPosition(IDB_V3::_stPosition& stPos){}
	virtual void OnQueryCamInfo(IDB_V3::_stCamInfo& stCamInfo){}
	virtual void OnQueryCamInfoCnt(DWORD dwCnt){}
	virtual void OnQueryCamModel(IDB_V3::_stCamModel& stCamInfo){}
	virtual void OnQueryCamModelCnt(DWORD dwCnt){}
	virtual void OnQueryMedia4Rec(IDB_V3::_stMedia& stMedia){}
	virtual void OnQueryMedia4Play(IDB_V3::_stMedia& stMedia){}
	virtual void OnQueryMedia(IDB_V3::_stMedia& stMedia){}
	virtual void OnQueryMediaCnt(DWORD dwCnt){}
	virtual void OnQueryVideoPos(IDB_V3::_stVideoPos& stVideoPos){}
	virtual void OnQueryVideoPosCnt(DWORD dwCnt){}
};