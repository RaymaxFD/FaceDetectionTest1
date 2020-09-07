

#pragma once
#include <ibase.h>

class IBuffer;
class IArithmetic : public IBase
{
public:
	virtual bool Sub(IBuffer* pSrc1, IBuffer* pSrc2, IBuffer* pDst, size_t dwWidth, size_t dwHeight, size_t dwDepth, RECT rtROI) = 0;
};
