#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IEvtVRFish_V1;
class IVRFish_V1 : public IWorker, public IMedia
{
public:
	struct _stTexture
	{
		POINT ptImg;
		float fX;
		float fY;
		float fZ;
	};

public:
	virtual void Enable3D(bool b) = 0;

public:
	virtual void IEvtAdd(IEvtVRFish_V1* pEvt) = 0;
	virtual void IEvtRemove(IEvtVRFish_V1* pEvt) = 0;
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
	virtual void TextureAdd(_stTexture& st) = 0;
	virtual void TextureReset() = 0;

public:
	virtual void EnableReticle(bool b) = 0;

public:
	virtual void SetEye(float fX, float fY, float fZ) = 0;
	virtual void SetCenter(float fX, float fY, float fZ) = 0;
	virtual void SetUp(float fX, float fY, float fZ) = 0;
	virtual void GetEye(float& fX, float& fY, float& fZ) = 0;
	virtual void GetCenter(float& fX, float& fY, float& fZ) = 0;
	virtual void GetUp(float& fX, float& fY, float& fZ) = 0;

public:
	virtual void Save2ImgFile(TCHAR* pStrFileName) = 0;

public:
	virtual void GetPos(float& fX, float& fY, float& fZ) = 0;
	virtual void SetPos(float fX, float fY, float fZ) = 0;
	virtual void GetPanTilt(float& fPan, float& fTilt) = 0;
	virtual void SetPanTilt(float fPan, float fTilt) = 0;

public:
	virtual void MoveIncremental(float fX, float fY, float fZ) = 0;
};
