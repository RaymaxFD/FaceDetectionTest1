

#pragma once
#include <ibase.h>

class IBuffer;
class IThreshold : public IBase
{
public:
	enum eCompare
	{
		eGreaterThen,
		eLessThen,
	};

public:
	virtual bool Threshold(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, BYTE ucThres, BYTE ucVal, BYTE nDepth, eCompare eHow, RECT rtROI) = 0;
	virtual bool Threshold8(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, BYTE ucThres, BYTE ucVal, eCompare eHow, RECT rtROI) = 0;
	virtual bool Threshold24(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, BYTE ucThres, BYTE ucVal, eCompare eHow, RECT rtROI) = 0;
	virtual bool Threshold32(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, BYTE ucThres, BYTE ucVal, eCompare eHow, RECT rtROI) = 0;
};
