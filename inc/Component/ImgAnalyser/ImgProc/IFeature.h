
#pragma once

#include <IBase.h>

class IBuffer;
class IFeature : public IBase
{
public:
	virtual bool CannyEdge(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, float fLow, float fHigh, RECT rtROI) = 0;
};
