#pragma once

#include <IBase.h>
#include <Media/IMedia.h>

class IDebug : public IBase
{
public:
	virtual void PrintDebugString(const TCHAR* pStr, ...) = 0;
	virtual void MsgBoxDebugString(const TCHAR* pStr, ...) = 0;
	virtual void FormatMessage(DWORD dwErr, TCHAR (&str)[MAX_PATH]) = 0;

public:
	virtual void CreateDisplay(SIZE szWin) = 0;
	virtual void NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t lWidth, size_t lHeight, IMedia::_eYUV eYUV) = 0;
	virtual void NewVideoRGB(DWORD dwContextID, IBuffer * pIBuf, size_t nWidth, size_t nHeight, size_t nDepth) = 0;

public:
	virtual DWORD ElaspedTime(bool bReset = false) = 0;
};
