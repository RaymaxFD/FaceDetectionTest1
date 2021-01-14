
#pragma once

#include <IBase.h>

class IBufferPool;
class IBuffer;

class IPacketEnc_V1 : public IBase
{
public:
	virtual void SetIPool(IBufferPool* pI) = 0;

public:
	virtual IBuffer* GenPacket(DWORD dwCmd, DWORD dwParam, BYTE* pParam) = 0;
};