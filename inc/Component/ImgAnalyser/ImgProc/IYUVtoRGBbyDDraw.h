#pragma once
#include <media/imedia.h>


class IBufferPool;
class IYUVtoRGBbyDDraw : public IBase, public IMedia
{
public:
	virtual void SetROI(DWORD dwContextID, RECT rtROI) = 0;
	virtual void SetPool(IBufferPool* pPool) = 0;
};
