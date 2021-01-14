
#pragma once
#include <IBase.h>

class IDBChannelEvt;
class IDBChannel : public IBase
{
public:
	struct _stChannelData
	{
		LONG lCamModel;	// 카메라 모델 일련 번호
		TCHAR strChannelName[256];	// 채널 이름
		LONG lChannelNumber;	// 채널 번호. 이 번호는 중복되어서는 안된다.
		//LONG m_ID;
		TCHAR strIP[256];	// 카메라 IP 주소
		VARIANT_BOOL bMotionDetectionAlarm;	// Motion Detection시 알람 여부
		VARIANT_BOOL bMotionDetectionSave;	// Motion Detection시 저장 여부
		LONG lPort1;	// 서버 포트 1.
		LONG lPort2;	// 서버 포트 2.
		LONG lPort3;	// 서버 포트 3.
		LONG lPort4;	// 서버 포트 4.
		LONG lPTZSpeed;	// PTZ 속도
		VARIANT_BOOL bRTSP;	// RTSP 접속 여부
		VARIANT_BOOL bWideAngle;	// 광각 카메라 여부
		LONG lWideAngleInfoIndex;	// 광각일 경우 참조되는 광각 테이블에서의 ID
	};

public:
	virtual void AddChannel(_stChannelData& st) = 0;
	virtual void ModiChannel(_stChannelData& st) = 0;
	virtual void DelChannel(int iChannel) = 0;
	virtual void QueryAllChannel() = 0;
	virtual void GetChannel(int iChannel) = 0;

public:
	virtual void SetEvent(IDBChannelEvt* pI) = 0;
};

class IDBChannelEvt
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void EvtIDBChannelAddOk(int iChannel)	{}
	virtual void EvtIDBChannelAddFail(int iChannel)	{}

public:
	virtual void EvtIDBChannelModiOk(int iChannel)	{}
	virtual void EvtIDBChannelModiFail(int iChannel)	{}

public:
	virtual void EvtIDBChannelDelOk(int iChannel)	{}
	virtual void EvtIDBChannelDelFail(int iChannel)	{}

public:
	virtual void EvtIDBChannelQueryStart()	{}
	virtual void EvtIDBChannelQuery(IDBChannel::_stChannelData& st)	{}
	virtual void EvtIDBChannelQueryEnd()	{}

public:
	virtual void EvtIDBChannelGet(IDBChannel::_stChannelData& st)	{}
};
