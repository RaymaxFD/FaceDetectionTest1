

#pragma once
#include <ibase.h>

class IBuffer;
class IImageFilter : public IBase
{
public:
	virtual bool Gaussian(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT rtROI) = 0;
	virtual bool Median(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT rtROI) = 0;

public:
	virtual void AnisotropicDiffussion1(IBuffer* pIIn, IBuffer* pIOut, DWORD dwW, DWORD dwH, double dSmooth) = 0;
	virtual void AnisotropicDiffussion2(IBuffer* pIIn, IBuffer* pIOut, DWORD dwW, DWORD dwH, double dSmooth, int iIteration) = 0;
};
