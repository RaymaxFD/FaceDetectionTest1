
#pragma once

#include <IBase.h>

class IEvtCamera_V1;
class IBufferPool;
class IBuffer;
class IMedia;

class ICamera_V1 : public IBase
{
public:
	static const DWORD ROI_LEFT = 320 - 50;
	//static const DWORD ROI_TOP = 240 - 100;
	static const DWORD ROI_TOP = 200;
	static const DWORD ROI_WIDTH = 100;
	//static const DWORD ROI_HEIGHT = 200;
	static const DWORD ROI_HEIGHT = 480-ROI_TOP - 1;
public:
	enum _eCamIndex
	{
		eCamFrontLeft = 1,
		eCamFrontRight = 2,
		eCamRearLeft = 0,
		eCamRearRight = 3,
		eCamMax,
	};

public:
	virtual void AddIEvent(IEvtCamera_V1* pI) = 0;
	virtual void AddMediaOut(IMedia* pI) = 0;
	virtual void RemoveMediaOut(IMedia* pI) = 0;
	virtual void RemoveIEvent(IEvtCamera_V1* pI) = 0;
	virtual void EnableEvent(bool b) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;
	virtual bool StartCam(bool b) = 0;

public:
	virtual bool Open(BYTE ucCamIndex = 0) = 0;
	virtual void Close() = 0;

public:
	virtual DWORD GetWidth() = 0;
	virtual DWORD GetHeight() = 0;
	virtual DWORD GetDepth() = 0;

public:
	virtual IBuffer* GetImage() = 0;

public:
	virtual bool TriggerSWEnable(bool b) = 0;
	virtual void TriggerSW() = 0;
};

class IEvtCamera_V1
{
public:
	enum eError
	{
		errorFailToSetupVideoSetting,
		errorFailToSetupFrameRate,
		errorFailToSetupCallback,
		errorFailToOpen,
		errorFailToStart,
		errorFailToStop,
		errorFailToClose,
	};

public:
	virtual void IEvtCameraError(BYTE ucCamIndex, eError error){}
	virtual void IEvtCameraNewImg(BYTE ucCamIndex, IBuffer* pI){}
};

class IEvtCamera_V2;

class ICamera_V2 : public IBase
{
public:
	static const DWORD ROI_LEFT = 320 - 50;
	//static const DWORD ROI_TOP = 240 - 100;
	static const DWORD ROI_TOP = 200;
	static const DWORD ROI_WIDTH = 100;
	//static const DWORD ROI_HEIGHT = 200;
	static const DWORD ROI_HEIGHT = 480-ROI_TOP - 1;
public:
	enum _eCamIndex
	{
		eCamFrontLeft = 1,
		eCamFrontRight = 2,
		eCamRearLeft = 0,
		eCamRearRight = 3,
		eCamMax,
	};

public:
	virtual void AddIEvent(IEvtCamera_V2* pI) = 0;
	virtual void AddMediaOut(IMedia* pI) = 0;
	virtual void RemoveMediaOut(IMedia* pI) = 0;
	virtual void RemoveIEvent(IEvtCamera_V2* pI) = 0;
	virtual void EnableEvent(bool b) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;
	virtual void StartCam(bool b) = 0;

public:
	virtual bool Open(BYTE ucCamIndex = 0) = 0;
	virtual void Close() = 0;

public:
	virtual DWORD GetWidth() = 0;
	virtual DWORD GetHeight() = 0;
	virtual DWORD GetDepth() = 0;

public:
	virtual IBuffer* GetImage() = 0;

public:
	virtual void TriggerSWEnable(bool b) = 0;
	virtual void TriggerSW() = 0;
};

class IEvtCamera_V2
{
public:
	enum eError
	{
		errorFailToSetupVideoSetting,
		errorFailToSetupFrameRate,
		errorFailToSetupCallback,
		errorFailToOpen,
		errorFailToStart,
		errorFailToStop,
		errorFailToClose,
	};

public:
	virtual void IEvtCameraError(BYTE ucCamIndex, eError error){}
	virtual void IEvtCameraNewImg(BYTE ucCamIndex, IBuffer* pI){}
};