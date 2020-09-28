
#pragma once

#include "ibase.h"

class IBuffer;
class IBufferPool : public IBase
{
public:
	virtual bool CreateBufferList(size_t dwBuffSize = 1, size_t dwListLen = 10, bool bMakeMore = false) = 0;
	virtual bool GetIBuffer(IBuffer** pp, int iMaxTryingCnt = 100, bool bWait4Refill = true) = 0;
	virtual void DestroyBufferList() = 0;
	virtual size_t GetBufferSize() = 0;
	virtual bool ChangeBufferSize(size_t dwNewSize) = 0;
	virtual size_t GetPossibleCount() = 0;
	virtual size_t GetListLen() = 0;
	virtual void CheckLenAndSize(size_t size, size_t dwListLen = 10) = 0;
};

class IBuffer
{
public:
	virtual BYTE* GetBuffer() = 0;
	virtual size_t GetBufferSize() = 0;
	virtual long GetRefCnt() = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual size_t GetBufferSizeUsed() = 0;
	virtual bool SetBuffSizeUsed(size_t dw) = 0;
	virtual bool SetData(BYTE* pData, size_t dwData) = 0;
	virtual bool SetData(IBuffer* pIBuff) = 0;
	virtual bool AppendData(BYTE* pData, size_t dwData) = 0;
	virtual void SetActive() = 0;
	virtual bool GetActive() = 0;
	virtual void SetZero() = 0;
	virtual bool CopyTo(IBuffer* pITo) = 0;
	virtual bool CopyFrom(IBuffer* pITo) = 0;
};
