
#pragma once
#include <IBase.h>

class IDBWideAngleInfoEvt;
class IDBWideAngleInfo : public IBase
{
public:
	struct _stWideAngleData
	{
		LONG lCenterX;	// ��� ������ x �߽� ��ǥ
		LONG lCenterY;	// ��� ������ y �߽� ��ǥ
		LONG lFishSizeH;	// ��� ������ ���� ����
		LONG lFishSizeW;	// ��� ������ ���� ����
		float fFOVDeg;	// ȭ��. 170���� ��� 87.5���̾�� ��.
		//LONG m_ID;
		LONG lLenzMaxRPixel;	// ��� ������ ������ �ȼ� ����
		LONG lMountType;	// 0 : eCamMountNone, 1 : eCamCeiling, 2 : eCamWall, 3 : eCamDiagonal
		LONG lOutH;	// ��� �ػ��� ���� ����
		LONG lOutW;	// ��� �ػ��� ���� ����
		LONG lPan;	// ���� Pan ��ġ
		LONG lSphereR;	// ������ 3���� ���� ������
		LONG lTilt;	// ���� Tilt ��ġ
	};

public:
	virtual void AddWA(_stWideAngleData& st) = 0;
	virtual void ModiWA(long lID, _stWideAngleData& st) = 0;
	virtual void DelWA(long lID) = 0;
	virtual void SearchWA(long lID) = 0;

public:
	virtual void SetEvent(IDBWideAngleInfoEvt* pI) = 0;
};

class IDBWideAngleInfoEvt
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void EvtIDBWideAngleInfoSearch(IDBWideAngleInfo::_stWideAngleData& st)	{}
};
