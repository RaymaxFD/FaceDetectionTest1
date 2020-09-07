#ifndef DAF8BAB0_B44F_4520_B0D4_84D9BEB7065E
#define DAF8BAB0_B44F_4520_B0D4_84D9BEB7065E

#include <IWorker.h>
#include "ICamModel.h"

class ICameraEvt_V1;
class IMedia;
class IEvent_V1;
class IRelay_V1;
class IContext_V1;
class IDecVideo_V1;
class IRecorder_V1;
class IBufferPool;
class ICamera_V1 : public IWorker, public ICamModel
{
	// connection
public:
	virtual void SetIP(TCHAR* pIP) = 0;
	virtual void SetPortBase(DWORD dwPort) = 0;
	virtual void SetPortVideo(DWORD dwPort) = 0;
	virtual void SetPortSound(DWORD dwPrort) = 0;
	virtual void SetPortMic(DWORD dwPort) = 0;
	virtual bool ConnectVideo() = 0;
	virtual void DisconnectVideo() = 0;
	virtual bool ConnectSound() = 0;
	virtual void DisconnectSound() = 0;
	virtual bool ConnectMic() = 0;
	virtual void DisconnectMic() = 0;
	virtual void SetUserID(TCHAR* pID) = 0;
	virtual void SetPass(TCHAR* pPass) = 0;
	virtual bool ConnectBase() = 0;
	virtual void DisconnectBase() = 0;
	virtual void DisconnectAll() = 0;
	virtual void SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual bool IsConnected() = 0;

	//ptz
public:

	// resolution
public:

public:
	virtual void SetIEvent(ICameraEvt_V1* p) = 0;

public:
	virtual void SetContextID(DWORD dw) = 0;

public:
	virtual void IMediaAdd(IMedia* p) {}
	virtual void IMediaRemove(IMedia* p)	{}
	virtual void IMediaReset(){}

protected:
	enum eState
	{
		eStateDisconnected,
		eStateConnecting,
		eStateConnected,
		eStateTryingToReconnect,
		eStateDisconnecting,
	};
};

class ICameraEvt_V1
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void OnCameraConnected(DWORD dwContextID) = 0;
	virtual void OnCameraDisconnected(DWORD dwContextID) = 0;
	virtual void OnCameraReconnecting(DWORD dwContextID) = 0;
};

#endif