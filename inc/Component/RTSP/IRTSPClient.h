#pragma once

#include <IWorker.h>

class IMedia;
class IBufferPool;
class IEvtRTSPClient_V1;
class IEvtIDecProbe;
class IRTSPClient_V1 : public IWorker
{
public:
	virtual void SetContextID(DWORD dw) = 0;

public:
	virtual void OpenURL(char const* pURL, bool bTCPFirst = true) = 0;
	virtual void Close() = 0;
	virtual bool IsOpen() = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void AddIEvent(IEvtRTSPClient_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtRTSPClient_V1* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual void IEvtIDecProbeAdd(IEvtIDecProbe* pI) = 0;
	virtual void IEvtIDecProbeRemove(IEvtIDecProbe* pI) = 0;
	virtual void IEvtIDecProbeReset() = 0;

public:
	virtual void SetBufferPool(IBufferPool* pI) = 0;

public:
	virtual void Play(const char* strStart = NULL, const char* strEnd = NULL) = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual double GetTimeOffset() = 0;
};


class IEvtRTSPClient_V1
{
public:
	virtual void EvtConnected(DWORD dwContextID) {}
	virtual void EvtConnectionFail(DWORD dwContextID) {}
	virtual void EvtDisconnected(DWORD dwContextID) {}
	virtual void EvtReconnectRequest(DWORD dwContextID) {}

public:
	virtual void EvtPresentationTime(DWORD dwContextID, long lSec) {}
	virtual void EvtRTSPVideoSize(DWORD dwContextID, size_t nWidth, size_t nHeight) {}
	virtual void EvtFPS(DWORD dwContextID, BYTE ucFPS) {}
};





class IRTSPClient_V2 : public IWorker
{
public:
	virtual void SetContextID(DWORD dw) = 0;

public:
	virtual void OpenURL(char const* pURL) = 0;
	virtual void Close() = 0;
	virtual bool IsOpen() = 0;

public:
	virtual void AddMediaOutput(IMedia* pI) = 0;
	virtual void RemoveMediaOutput(IMedia* pI) = 0;
	virtual void ResetMediaOut() = 0;

public:
	virtual void AddIEvent(IEvtRTSPClient_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtRTSPClient_V1* pI) = 0;
	virtual void ResetIEvent() = 0;

public:
	virtual void SetBufferPool(IBufferPool* pI) = 0;

public:
	virtual void Play(const char* strStart = NULL, const char* strEnd = NULL) = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetFPS(BYTE ucFPS) = 0;
	virtual BYTE GetFPS() = 0;
};

class IEvtRTSPClient_V2 : public IEvtRTSPClient_V1
{
};
