

#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IBufferPool;

class IVideoPostProc : public IWorker, public IMedia
{
public:
	virtual void SwapUV(bool bEn) = 0;
	virtual void SwapGB(bool bEn) = 0;
	
public:
	virtual void FlipUpDown(bool bEn) = 0;

public:
	virtual void SetIBufferPool4YUV(IBufferPool* pI) = 0;
};