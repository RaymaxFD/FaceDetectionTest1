
#pragma once
#include <IWorker.h>
#include <media/IMedia.h>
class IBufferPool;

class IEncVideo_V1 : public IMedia, public IWorker
{
public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;

public:
	virtual bool SetCodec(_eCodecVideo eCodec) = 0;
	virtual bool SetupContext(int iBitRate = 400000, int iWidth = 352, int iHeight = 288, int iFPSStart = 1, int iFPS = 25, int iGOPSize = 10, int MaxBFrame = 1) = 0;
	virtual void CleanUp() = 0;
	virtual bool Start(/*TCHAR* pStrFile*/) = 0;
	virtual void Stop() = 0;
	virtual void SwapUV(bool bSwap) = 0;
};


class IEncVideo_V2 : public IWorker, public IMedia
{
public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual void SetBuffer(IBufferPool* pI) = 0;

public:
	virtual bool SetupContext(_eCodecVideo eCodec, int iBitRate = 400000, int iWidth = 352, int iHeight = 288, int iFPSStart = 1, int iFPS = 25, int iGOPSize = 10, int MaxBFrame = 1) = 0;
	virtual void CleanUp() = 0;
	virtual bool Start() = 0;
	virtual void Stop() = 0;
};