
#pragma once

#include <IBase.h>

class IBufferPool;
class IBuffer;

class IEvtPacketDec_V1;
class IPacketDec_V1 : public IBase
{
public:
	virtual void IEvtAdd(IEvtPacketDec_V1* pI) = 0;
	virtual void IEvtRemove(IEvtPacketDec_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetIndex(UINT_PTR s) = 0;

public:
	virtual void SetIPool(IBufferPool* pI) = 0;

public:
	virtual bool NewPacket(IBuffer* pIBuff) = 0;
};

class IEvtPacketDec_V1
{
public:
	struct _stParam
	{
		UINT_PTR uiIndex;
		DWORD dwCmd;
		DWORD dwParam;
		IBuffer* pParam;
	};
public:
	virtual void IEvtNewPacket(_stParam& stParam){}
};