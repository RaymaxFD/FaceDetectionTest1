

#pragma once
#include <media/imedia.h>
#include <IWorker.h>

class IDecVideoEVT;
class IBufferPool;
class IDecVideo_V1 : public IMedia, public IWorker
{
public:
	static const DWORD BUFF_LEN = 30;

public:
	virtual void EnableDecode(bool b) = 0;

public:
	virtual DWORD GetWidth() = 0;
	virtual DWORD GetHeight() = 0;
	virtual DWORD GetDepth() = 0;

public:
	virtual void StreamOpen() = 0;
	virtual void StreamClose() = 0;

public:
	virtual void SetOutputType(bool bRGB) = 0;

public:
	virtual void SetBuffer(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;

public:
	virtual void SwapUV(bool b) = 0;

public:
	virtual void AddIEvent(IDecVideoEVT* pEvt) = 0;
	virtual void RemoveIEvent(IDecVideoEVT* pEvt) = 0;
	virtual void ResetIEvent() = 0;
};

class IDecVideo_V2 : public IDecVideo_V1
{};

class IDecVideoEVT
{
public:
	virtual void EvtIDecVideoDecoded()	{}

public:
	virtual void EvtIDecVideoResolution(size_t nWidth, size_t nHeight) {}
};
