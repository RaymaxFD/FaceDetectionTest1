
#pragma once

#include <media/IMedia.h>

class IBufferPool;
class IEvtScreenCapture;
class IMedia;

class IScreenCapture_V1 : public IBase, public IMedia
{
public:
	enum _eOutType
	{
		eOutRGB32,
		eOutYUV420,
	};
public:
	virtual void SetOutType(_eOutType e) = 0;
	virtual void GetResolution(long& lWidth, long& lHeight) = 0;

public:
	virtual void AddIEvent(IEvtScreenCapture* pI) = 0;

public:
	virtual void SetContextID(DWORD dw) = 0;
	virtual void SetTargetHDC(HDC hDC) = 0;
	virtual void SetFPS(BYTE ucFPS) = 0;

public:
	virtual void SetIBuffer32(IBufferPool* pIPool) = 0;
	virtual void SetIBuffer24(IBufferPool* pIPool) = 0;
	virtual void SetIBufferY(IBufferPool* pIPool) = 0;
	virtual void SetIBufferU(IBufferPool* pIPool) = 0;
	virtual void SetIBufferV(IBufferPool* pIPool) = 0;

public:
	virtual bool Start() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;
};

class IEvtScreenCapture
{
};








class IScreenCapture_V2 : public IBase, public IMedia
{
public:
	enum _eOutType
	{
		eOutRGB32,
		eOutYUV420,
	};
public:
	virtual void SetOutType(_eOutType e) = 0;
	virtual void GetResolution(long& lWidth, long& lHeight) = 0;

public:
	virtual void AddIEvent(IEvtScreenCapture* pI) = 0;

public:
	virtual void SetContextID(DWORD dw) = 0;
	virtual bool Init(HWND hWnd) = 0;
	virtual void SetFPS(BYTE ucFPS) = 0;

public:
	virtual void SetIBuffer32(IBufferPool* pIPool) = 0;
	virtual void SetIBuffer24(IBufferPool* pIPool) = 0;
	virtual void SetIBufferY(IBufferPool* pIPool) = 0;
	virtual void SetIBufferU(IBufferPool* pIPool) = 0;
	virtual void SetIBufferV(IBufferPool* pIPool) = 0;

public:
	virtual bool Start() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;
};