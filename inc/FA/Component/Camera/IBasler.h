
#pragma once

#include <IBase.h>
#include <Media/IMedia.h>

class IBufferPool;
class IEvtBasler_V1;

class IBasler_V1 : public IBase
{
public:
	virtual void SetContextID(DWORD) = 0;
	virtual void AddIEvent(IEvtBasler_V1* pI) = 0;
	virtual void AddMediaOut(IMedia* pI) = 0;
	virtual void RemoveMediaOut(IMedia* pI) = 0;
	virtual void RemoveIEvent(IEvtBasler_V1* pI) = 0;
	virtual void EnableEvent(bool b) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;
	virtual void StartCam(bool b) = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void SetFlipVertical(bool b) = 0;
	virtual void SetFlipHorizontal(bool b) = 0;
};

class IEvtBasler_V1
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
