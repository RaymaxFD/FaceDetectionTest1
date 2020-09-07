

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
	virtual void Init() = 0;                                                      // �ʱ�ȭ ����
	virtual void SetFishCenter(int iX, int iY) = 0;                               // �Է� ��� ���󿡼��� ���� ����
	virtual void SetPixelSize(double d) = 0;                                      // cmos �� ccd ���ڿ����� �ȼ� ũ�� ����
	virtual void SetViewRatio(_eViewRatio e) = 0;                                 // ��� ������ ����/���� ȭ�� ����
	virtual void SetPanoW(int iW) = 0;                                            // ��� ������ ���� ����. ���� ���̴� ȭ�� ������ ���Ͽ� ���������� ������.
	virtual void SetDispArea(int iLeft, int iTop, int iW, int iH) = 0;            // �̱���
	virtual void SetUVOrder(bool b) = 0;                                          // �̻��
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
	// ���� ó�� ����
	// Enalbe(false)�� �ϸ� �Էµ� ��� ������ �״�� �����.
	virtual void Enable(bool b) = 0;

	// �ʱ�ȭ
	// _eViewRatio eRatio : ��� ȭ�� ����
	// SIZE szFish : �Է� ��� ������ ũ��
	// POINT ptFishCenter : �Է� ��� ������ �߽�
	// int iFishR : �Է� ��� ������ ������
	// int iFishAngle : �Է� ��� ������ ȭ��
	virtual void Init(_eViewRatio eRatio, SIZE szFish, POINT ptFishCenter, int iFishR, int iFishAngle) = 0;

	// ó���Ǵ� ��� ������ �߽��� ���Ϸ� �̵��� ���
	virtual void SetCenterY(double dHRadian) = 0;
};

class IWideAngle180_V3 : public IMedia, public IBase
{
public:
	// �ʱ�ȭ
	// POINT ptFishCenter : �Է� ��� ������ �߽�
	// SIZE szFish : �Է� ��� ������ ũ��
	// double dFOVDeg : �Է� ��� ������ ȭ��
	// int iLenzMaxRPixel : �Է� ��� ������ ������
	virtual bool Init(POINT ptFishCenter, SIZE szFish, double dFOVDeg, int iLenzMaxRPixel) = 0;

	// �ĳ�� ������ ������ ���� ��ġ
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
	// ���� ó�� ����
	// Enalbe(false)�� �ϸ� �Էµ� ��� ������ �״�� �����.
	virtual void Enable(bool b) = 0;

	// �ʱ�ȭ
	// _eViewRatio eRatio : ��� ȭ�� ����
	// SIZE szFish : �Է� ��� ������ ũ��
	// POINT ptFishCenter : �Է� ��� ������ �߽�
	// int iFishR : �Է� ��� ������ ������
	// int iFishAngle : �Է� ��� ������ ȭ��
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
	// ���� ó�� ����
	// Enalbe(false)�� �ϸ� �Էµ� ��� ������ �״�� �����.
	virtual void Enable(bool b) = 0;

	// �ʱ�ȭ
	// _eViewRatio eRatio : ��� ȭ�� ����
	// SIZE szFish : �Է� ��� ������ ũ��
	// POINT ptFishCenter : �Է� ��� ������ �߽�
	// int iFishR : �Է� ��� ������ ������
	// int iFishAngle : �Է� ��� ������ ȭ��
	virtual void Init(_eViewRatio eRatio, SIZE szFish, int iFishAngle, int iRMax, HWND hWnd) = 0;
	virtual void DeInit() = 0;
	virtual void SwapUV(bool bSwap) = 0;
	virtual void OnSize() = 0;
};