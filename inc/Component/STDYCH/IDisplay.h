
#pragma once

#include <IWorker.h>
#include "media/imedia.h"

class IDisplayEvt;
class IDisplay : public IMedia, public IWorker
{
public:
	// uiID 는 이벤트를 통지할 때 어떤 객체로부터인지를 명시하기 위해 사용된다. 서로 다른 IDisplay 객체가 evt 함수들을 공유할 수 있다. 
	virtual bool Init(UINT uiID, HWND hWnd) = 0;
	virtual bool IsInit() = 0;
	virtual void Destroy() = 0;
	virtual bool ShowPlane(DWORD dwContextID, bool bShow) = 0;

public:
	virtual bool AddPlane(DWORD dwContextID, DWORD dwWidth, DWORD dwHeight, 
		float fTargetLeft, float fTargetTop, float fTargetRight, float fTargetBottom) = 0;	//	dwContextID는 NewVideoRGB나 NewVideoYUV등으로 넘어오는 채널과 대응된다.
	virtual bool ChangePlaneRect(DWORD dwContextID, DWORD dwWidth, DWORD dwHeight, 
		float fLeft, float fTop, float fRight, float fBottom) = 0;
	virtual bool GetDC(DWORD dwContextID, HDC& hDC) = 0;
	virtual bool ReleaseDC(DWORD dwContextID, HDC hDC) = 0;
	virtual bool GetBaseDC(HDC& hDC) = 0;
	virtual bool ReleaseBaseDC(HDC hDC) = 0;
	virtual void Update() = 0;
	virtual void OnSize() = 0;
	virtual bool GetBaseSize(int& iWidth, int& iHeight) = 0;
	virtual bool RequestPrimaryHDC() = 0;
	virtual bool RequestBaseHDC() = 0;
	virtual bool RequestBaseOverlayHDC() = 0;
	virtual bool RequestPlaneHDC(DWORD dwContextID = 0) = 0;
	virtual bool RequestPlaneOverlayHDC(DWORD dwContextID = 0) = 0;
	virtual void ClearBase() = 0;
	virtual void ClearPlane(DWORD dwContextID = 0) = 0;
	virtual void ClearOverlay(DWORD dwContextID = 0) = 0;
	virtual void SwapUV(bool bSwap) = 0;

public:
	virtual void AddIEvent(IDisplayEvt* pEvt) = 0;
};

class IDisplayEvt
{
public:
	virtual void AddRef() {}
	virtual void Release() {}
	virtual long GetRefCnt() {	return 0;	}

public:
	virtual void EvtIDisplayUpdate(UINT uiID)	{}
	virtual void EvtIDisplayPreBaseUpdate(UINT uiID, HDC hDC, int iWidth, int iHeight)	{}
	virtual void EvtIDisplayPreBaseOverlayUpdate(UINT uiID, HDC hDC, int iWidth, int iHeight)	{}
	virtual void EvtIDisplayPrePlaneUpdate(UINT uiID, DWORD dwContextID, HDC hDC, int iWidth, int iHeight)	{}
	virtual void EvtIDisplayPrePlaneOverlayUpdate(UINT uiID, DWORD dwContextID, HDC hDC, int iWidth, int iHeight)	{}
	virtual void EvtIDisplayPlaneUpdate(UINT uiID, DWORD dwContextID)	{}

public:
	virtual void EvtIDispalyFPS(UINT uiID, DWORD dwFPS)	{}
};


class IEvtDisplay2;
class IDisplay2 : public IMedia, public IWorker
{
public:
	virtual void IEvtAdd(IDisplayEvt* pEvt) = 0;
	virtual void IEvtRemove(IDisplayEvt* pEvt) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void Init(UINT uiID, HWND hWnd) = 0;
	virtual bool IsInit() = 0;
	virtual void Destroy() = 0;
	virtual void OnSize() = 0;
	virtual void Update() = 0;

public:
	virtual void RectAdd(RECT& rt, int nLineWidth, COLORREF& color) = 0;
	virtual void RectReset() = 0;

public:
	virtual void CircleAdd(RECT& circle, int nLineWidth, COLORREF color) = 0;
	virtual void CircleReset() = 0;

public:
	virtual void TextAdd(COLORREF& color, POINT ptPos, TCHAR* pMsg, int nFontSize) = 0;
	virtual void TextReset() = 0;

public:
	virtual void EnableReticle(bool b) = 0;

public:
	virtual void Save2ImgFile(TCHAR* pStrFileName) = 0;

public:
	virtual void FlipV(bool bEnable) = 0;
	virtual void FlipH(bool bEnable) = 0;
};

class IEvtDisplay2
{};