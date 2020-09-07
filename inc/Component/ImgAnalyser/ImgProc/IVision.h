
#pragma once

#include <IBase.h>

class IBuffer;

class IFloodFill_V1 : public IBase
{
public:
	virtual bool FloodFill(IBuffer* pSrc, DWORD dwWidth, DWORD dwHeight, RECT rtROI, BYTE ucFillValue) = 0;
};
