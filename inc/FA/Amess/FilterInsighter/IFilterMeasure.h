

#pragma once

#include <IBase.h>

class IEvtFilterMeasure_V1;
class IBuffer;

/*
BLOB + M_FERET_MIN_DIAMETER_ELONGATION
*/
class IFilterMeasure_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilterMeasure_V1* pI) = 0;

public:
	enum _eType
	{
		eCircle,
		eRectangle,
	};
public:
	virtual void SetType(_eType eType) = 0;

public:
	virtual void SetPixelWidth(double dW) = 0;
	virtual void SetTHValue(BYTE ucTH) = 0;
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void Measure(IBuffer* pI, long lX, long lY) = 0;

public:
	virtual void SetDispType(int iType) = 0;
};

class IEvtFilterMeasure_V1
{
public:
	virtual void Evt1FilterMeasureDone(double dW)                    {}
};




/*
단순 가장 짧은 거리 측정
*/
class IEvtFilterMeasure_V2;

class IFilterMeasure_V2 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilterMeasure_V2* pI) = 0;

public:
	enum _eType
	{
		eCircle,
		eRectangle,
	};
public:
	virtual void SetType(_eType eType) = 0;

public:
	virtual void SetPixelWidth(double dW) = 0;
	virtual void SetTHValue(BYTE ucTH) = 0;
	virtual void SetHWND(HWND hWnd) = 0;
	virtual void SetROI(RECT& rtW, RECT& rtH) = 0;

public:
	virtual void Measure(IBuffer* pI, long lX, long lY) = 0;

public:
	virtual void SetDispType(int iType) = 0;
};

class IEvtFilterMeasure_V2
{
public:
	virtual void Evt2FilterMeasureDone(double dW)                    {}
};


/*
약간 튀어나와 있는 부분을 포함하는 가장 짧은 거리 측정
*/
class IEvtFilterMeasure_V3;

class IFilterMeasure_V3 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilterMeasure_V3* pI) = 0;

public:
	enum _eType
	{
		eCircle,
		eRectangle,
	};
public:
	virtual void SetType(_eType eType) = 0;

public:
	virtual void SetPixelWidth(double dW) = 0;
	virtual void SetTHValue(BYTE ucTH) = 0;
	virtual void SetHWND(HWND hWnd) = 0;
	virtual void SetROI(RECT& rtW, RECT& rtH) = 0;

public:
	virtual void Measure(IBuffer* pI, long lX, long lY) = 0;

public:
	virtual void SetDispType(int iType) = 0;
};

class IEvtFilterMeasure_V3
{
public:
	virtual void Evt3FilterMeasureDone(double dW)                    {}
};


class IEvtFilterMeasure_V4;

class IFilterMeasure_V4 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilterMeasure_V4* pI) = 0;

public:
	enum _eType
	{
		eCircle,
		eRectangle,
	};
public:
	virtual void SetType(_eType eType) = 0;

public:
	virtual void SetPixelWidth(double dW) = 0;
	virtual void SetTHValue(BYTE ucTH) = 0;
	virtual void SetHWND(HWND hWnd) = 0;
	virtual void SetROIBox(SIZE sz) = 0;

public:
	virtual void Measure(IBuffer* pI, long lX, long lY, bool bDisplayOny = true) = 0;

public:
	virtual void SetDispType(int iType) = 0;
};

class IEvtFilterMeasure_V4
{
public:
	virtual void Evt4FilterMeasureDone(double dW)                    {}
};


class IEvtFilterMeasure_V5;

class IFilterMeasure_V5 : public IBase
{
public:
	virtual void AddIEvent(IEvtFilterMeasure_V5* pI) = 0;

public:
	virtual void SetPixelWidth(double dW) = 0;
	virtual void AddHWNDTeaching(HWND hWnd, SIZE szImage) = 0;
	virtual void AddHWNDMeasure(HWND hWnd, SIZE szImage) = 0;
	virtual void SetROIBox(SIZE sz) = 0;

public:
	virtual void Teaching(IBuffer* pI, long lX, long lY) = 0;
	virtual void Measure(IBuffer* pI, long lX, long lY) = 0;
};

class IEvtFilterMeasure_V5
{
public:
	virtual void Evt5FilterMeasureDone(double dW)                    {}
};