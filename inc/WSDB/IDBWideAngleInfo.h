
#pragma once
#include <IBase.h>

class IDBWideAngleInfoEvt;
class IDBWideAngleInfo : public IBase
{
public:
	struct _stWideAngleData
	{
		LONG lCenterX;	// 어안 영상의 x 중심 좌표
		LONG lCenterY;	// 어안 영상의 y 중심 좌표
		LONG lFishSizeH;	// 어안 영상의 세로 길이
		LONG lFishSizeW;	// 어안 영상의 가로 길이
		float fFOVDeg;	// 화각. 170도일 경우 87.5도이어야 함.
		//LONG m_ID;
		LONG lLenzMaxRPixel;	// 어안 영상의 반지름 픽셀 갯수
		LONG lMountType;	// 0 : eCamMountNone, 1 : eCamCeiling, 2 : eCamWall, 3 : eCamDiagonal
		LONG lOutH;	// 출력 해상도의 세로 길이
		LONG lOutW;	// 출력 해상도의 가로 길이
		LONG lPan;	// 현재 Pan 위치
		LONG lSphereR;	// 가상의 3차원 공간 반지름
		LONG lTilt;	// 현재 Tilt 위치
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
