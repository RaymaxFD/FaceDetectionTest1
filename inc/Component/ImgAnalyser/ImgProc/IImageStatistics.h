
#pragma once
#include <ibase.h>

class IBuffer;
class IImageStatistics : public IBase
{
public:
	virtual bool Mean(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT rtROI, int iMaskSize = 3) = 0;

public:
	virtual int GetLabelCnt(IBuffer* pIImgInput, size_t width, size_t height) = 0;
	virtual bool GetLabel(int iPos, POINT& ptCenter, RECT& rtArea, int& iArea) = 0;
};
