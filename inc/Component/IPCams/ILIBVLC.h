
#pragma once

#include <IWorker.h>
#include <Media\IMedia.h>

class IString;
class IBufferPool;

class IEvtLIBVLC
{
public:
	virtual void IEvtVLCStarted(DWORD dwContextID){}
	virtual void IEvtVLCDisconnected(DWORD dwContextID){}
	virtual void IEvtVLCReconnection(DWORD dwContextID){}
};

class ILIBVLC : public IWorker
{
public:
	virtual void SetContextID(DWORD dwContextID) = 0;
public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void IEvtAdd(IEvtLIBVLC* pI) = 0;
	virtual void IEvtRemove(IEvtLIBVLC* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetMediaSource(TCHAR* pIStr) = 0;
	virtual void Playing(bool bPlay) = 0;
	virtual bool IsPlaying() = 0;
	virtual void SetIBufferPool(IBufferPool* pIPool) = 0;
	virtual void SetPlayingPos(int64_t nPos) = 0;
	virtual uint64_t GetPlayingLength() = 0;
};
