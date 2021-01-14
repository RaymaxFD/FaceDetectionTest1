

#pragma once

#include <IBase.h>

class IEvtIMI_V1;
class IBufferPool;
class IBuffer;
class IMedia;

class IIMI_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtIMI_V1* pI) = 0;
	virtual void AddMediaOut(IMedia* pI) = 0;
	virtual void RemoveMediaOut(IMedia* pI) = 0;
	virtual void RemoveIEvent(IEvtIMI_V1* pI) = 0;
	virtual void EnableEvent(bool b) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;
	virtual void StartCam(bool b) = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void SetFlipVertical(bool b) = 0;
	virtual void SetFlipHorizontal(bool b) = 0;

public:
	virtual bool Open(DWORD dwContextID = 0) = 0;
	virtual void Close() = 0;
};

class IEvtIMI_V1
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
	virtual void IEvtCameraError(DWORD dwContextID, eError error){}
	virtual void IEvtCameraNewImg(DWORD dwContextID, IBuffer* pI){}
};

class IEvtIMI_V2;

class IIMI_V2 : public IBase
{
public:
	virtual void AddIEvent(IEvtIMI_V2* pI) = 0;
	virtual void AddMediaOut(IMedia* pI) = 0;
	virtual void RemoveMediaOut(IMedia* pI) = 0;
	virtual void RemoveIEvent(IEvtIMI_V2* pI) = 0;
	virtual void EnableEvent(bool b) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;
	virtual void StartCam(bool b) = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void SetFlipVertical(bool b) = 0;
	virtual void SetFlipHorizontal(bool b) = 0;

public:
	virtual bool Open(DWORD dwContextID = 0) = 0;
	virtual void Close() = 0;

public:
	virtual bool GetGammaMinMax(int& iMin, int& iMax) = 0;
	virtual bool GetExposureMinMax(int& iMin, int& iMax) = 0;
public:
	virtual int GetGamma() = 0;
	virtual int GetExposure() = 0;
public:
	virtual bool SetGamma(int) = 0;
	virtual bool SetExposure(int) = 0;
};

class IEvtIMI_V2
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
	virtual void IEvtCameraError(DWORD dwContextID, eError error){}
	virtual void IEvtCameraNewImg(DWORD dwContextID, IBuffer* pI){}
};