

#pragma once
#include <media/imedia.h>

class IWideAngle180_V1 : public IMedia, public IBase
{
public:
	enum _eViewRatio
	{
		e4_3 = 0,
		e16_9,
		e80_19,
	};
public:
	virtual void Init() = 0;                                                      // 초기화 수행
	virtual void SetFishCenter(int iX, int iY) = 0;                               // 입력 어안 영상에서의 원점 설정
	virtual void SetPixelSize(double d) = 0;                                      // cmos 나 ccd 소자에서의 픽셀 크기 설정
	virtual void SetViewRatio(_eViewRatio e) = 0;                                 // 출력 영상의 가로/세로 화면 비율
	virtual void SetPanoW(int iW) = 0;                                            // 출력 영상의 가로 길이. 세로 길이는 화면 비율에 의하여 내부적으로 구해짐.
	virtual void SetDispArea(int iLeft, int iTop, int iW, int iH) = 0;            // 미구현
	virtual void SetUVOrder(bool b) = 0;                                          // 미사용
};

class IWideAngle180_V2 : public IMedia, public IBase
{
public:
	enum _eViewRatio
	{
		e4_3 = 0,
		e16_9,
		e80_19,
	};
public:
	// 광각 처리 여부
	// Enalbe(false)를 하면 입력된 어안 영상을 그대로 출력함.
	virtual void Enable(bool b) = 0;

	// 초기화
	// _eViewRatio eRatio : 출력 화면 비율
	// SIZE szFish : 입력 어안 영상의 크기
	// POINT ptFishCenter : 입력 어안 영상의 중심
	// int iFishR : 입력 어안 영상의 반지름
	// int iFishAngle : 입력 어안 영상의 화각
	virtual void Init(_eViewRatio eRatio, SIZE szFish, POINT ptFishCenter, int iFishR, int iFishAngle) = 0;

	// 처리되는 어안 영상의 중심을 상하로 이동할 경우
	virtual void SetCenterY(double dHRadian) = 0;
};

class IWideAngle180_V3 : public IMedia, public IBase
{
public:
	// 초기화
	// POINT ptFishCenter : 입력 어안 영상의 중심
	// SIZE szFish : 입력 어안 영상의 크기
	// double dFOVDeg : 입력 어안 영상의 화각
	// int iLenzMaxRPixel : 입력 어안 영상의 반지름
	virtual bool Init(POINT ptFishCenter, SIZE szFish, double dFOVDeg, int iLenzMaxRPixel) = 0;

	// 파노라마 생성을 시작할 가로 위치
	virtual bool SetPanoStartX(DWORD dwPanoStartXPercent) = 0;
};

class IWideAngle180_V4 : public IBase, public IMedia
{
public:
	enum _eViewRatio
	{
		e4_3 = 0,
		e16_9,
		e80_19,
	};
public:
	// 광각 처리 여부
	// Enalbe(false)를 하면 입력된 어안 영상을 그대로 출력함.
	virtual void Enable(bool b) = 0;

	// 초기화
	// _eViewRatio eRatio : 출력 화면 비율
	// SIZE szFish : 입력 어안 영상의 크기
	// POINT ptFishCenter : 입력 어안 영상의 중심
	// int iFishR : 입력 어안 영상의 반지름
	// int iFishAngle : 입력 어안 영상의 화각
	virtual void Init(_eViewRatio eRatio, SIZE szFish, int iFishAngle) = 0;
};

class IWideAngle180_V5 : public IBase, public IMedia
{
public:
	enum _eViewRatio
	{
		e4_3 = 0,
		e16_9,
		e80_19,
	};
public:
	// 광각 처리 여부
	// Enalbe(false)를 하면 입력된 어안 영상을 그대로 출력함.
	virtual void Enable(bool b) = 0;

	// 초기화
	// _eViewRatio eRatio : 출력 화면 비율
	// SIZE szFish : 입력 어안 영상의 크기
	// POINT ptFishCenter : 입력 어안 영상의 중심
	// int iFishR : 입력 어안 영상의 반지름
	// int iFishAngle : 입력 어안 영상의 화각
	virtual void Init(_eViewRatio eRatio, SIZE szFish, int iFishAngle, int iRMax, HWND hWnd) = 0;
	virtual void DeInit() = 0;
	virtual void SwapUV(bool bSwap) = 0;
	virtual void OnSize() = 0;
};