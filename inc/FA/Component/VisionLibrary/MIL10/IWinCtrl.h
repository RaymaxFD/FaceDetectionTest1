
#pragma once

#include <IBase.h>

// MIL include
#include "mil.h"

class ISystem_V2;
class IEvtWinCtrl_V2;
class IWinCtrl_V2 : public IBase
{
public:
	static const BYTE DEF_BMP_IMAGE = 0;
	static const BYTE DEF_JPG_IMAGE = 1;
	static const BYTE DEF_PNG_IMAGE = 2;
	static const BYTE DEF_TIFF_IMAGE = 3;
	static const BYTE DEF_DRAW_FILL =  0;
	static const BYTE DEF_DRAW_MARGIN	= 1;
	static const BYTE DEF_XLD_CROSS = 0;
	static const BYTE DEF_SOLID	= 0;
	static const BYTE DEF_DOT	= 1;

public:
	virtual void AddIEvent(IEvtWinCtrl_V2* pI) = 0;

public:
	virtual void SetIndex(int iIndex) = 0;

public:
	virtual void OverlayPrepare() = 0;
	virtual MIL_ID OverlayGet() = 0;
	virtual void OverlayApply() = 0;

public:
	virtual void GetImgSize(DWORD& dwWidth, DWORD& dwHeight) = 0;

public:
	virtual bool IsAutoFit() = 0;
	virtual bool Initialize(int iImgWidth, int iImgHeight, HWND hWnd, ISystem_V2* pI) = 0;
	virtual void Uninitialize() = 0;
	virtual void SetImgSize(int iImgWidth, int iImgHeight) = 0;
	virtual void Zoom_In() = 0;
	virtual void Zoom_Out() = 0;
	virtual void Zoom_WidthFit() = 0;
	virtual void Zoom_HeightFit() = 0;
	virtual void Zoom_AutoFit() = 0;
	virtual void Zoom_Reset() = 0;
	virtual void SetZoomLevel(double dZoom) = 0;
	virtual void Set_PosX(int iXStart) = 0;
	virtual void Set_PosY(int iYStart) = 0;
	virtual void Image_Save(const MIL_ID& Image, TCHAR* pStrFile, int iType) = 0;
	virtual bool Image_Load(MIL_ID* pImage, TCHAR* pStrFile, bool bBuffer = true) = 0;
	virtual bool Image_Load(BYTE* pBuf, TCHAR* pStrFile, int iSize) = 0;

	virtual void Display_Rectangle(RECT rect, COLORREF clr, int iPen = DEF_SOLID, bool bOverlay = true, int iPenWidth = 9) = 0;
	virtual void BackDisplay() = 0;
	virtual void Display_Image(MIL_ID Image, HDC hDC, HDC memDC) = 0;
	virtual void Display_Image(MIL_ID Image, bool ReDraw = true) = 0;	
	virtual void Display_String(TCHAR* pStr, POINT Pos, COLORREF refcolor = RGB(255, 0, 0)) = 0;
	virtual void Display_Region(HRGN rgn, int iMode, COLORREF refcolor = RGB(255, 0, 0), int iPen = DEF_SOLID) = 0; ///// 5
	virtual bool Display_Cross(long lCenterCol, long lCenterRow, double dSizeY, double dSizeX, COLORREF refcolor, bool bOverlay = true, int iPenWidth = 9) = 0; ///// 6

public:
	enum _eLineType
	{
		eLIneModule,
		eLIneLED,
		eLIneEmptyLED,
		eLIneMissLED,
	};
	virtual void Display_XLD(_eLineType eType, HRGN hRgn, COLORREF refcolor = RGB(255, 0, 0), bool bOverlay = true, int iPenWidth = 9) = 0; ///// 4

public:
	virtual bool InspectErrorImageSave(TCHAR* strPath) = 0;

public:
	virtual void GetImageStartPoint(POINT& pt) = 0;
	virtual void GetZoomLevel(double& dZoom) = 0;

public:
	virtual MIL_ID GetGraphicalList() = 0;
};

class IEvtWinCtrl_V2
{
public:
	enum _eErrorCode
	{
		eErrReleaseAutoFit,                            // Auto Fit mode일 때에는 다른 zoom 기능들이 동작하지 아니함.
		eErrSystemEmpty,                               // Initialie()에서 System Parameter가 비어 있음.
		eErrSysemNoInit,                               // MIL Sysem을 초기화하지 아니함.
	};
public:
	virtual void EvtWinCtrlError(_eErrorCode eErr){}
	virtual void EvtWinCtrlImgSizeChanged(int iIndex, long lWidth, long lHeight){}
	virtual void EvtWinCtrlZoomChanged(long lWidth, long lHeight, int iIndex, float fW, float fH){}
	virtual void EvtWinCtrlAutoFit(int iIndex, bool bAutoFit){}
};