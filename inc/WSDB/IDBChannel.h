
#pragma once
#include <IBase.h>

class IDBChannelEvt;
class IDBChannel : public IBase
{
public:
	struct _stChannelData
	{
		LONG lCamModel;	// ī�޶� �� �Ϸ� ��ȣ
		TCHAR strChannelName[256];	// ä�� �̸�
		LONG lChannelNumber;	// ä�� ��ȣ. �� ��ȣ�� �ߺ��Ǿ�� �ȵȴ�.
		//LONG m_ID;
		TCHAR strIP[256];	// ī�޶� IP �ּ�
		VARIANT_BOOL bMotionDetectionAlarm;	// Motion Detection�� �˶� ����
		VARIANT_BOOL bMotionDetectionSave;	// Motion Detection�� ���� ����
		LONG lPort1;	// ���� ��Ʈ 1.
		LONG lPort2;	// ���� ��Ʈ 2.
		LONG lPort3;	// ���� ��Ʈ 3.
		LONG lPort4;	// ���� ��Ʈ 4.
		LONG lPTZSpeed;	// PTZ �ӵ�
		VARIANT_BOOL bRTSP;	// RTSP ���� ����
		VARIANT_BOOL bWideAngle;	// ���� ī�޶� ����
		LONG lWideAngleInfoIndex;	// ������ ��� �����Ǵ� ���� ���̺����� ID
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
