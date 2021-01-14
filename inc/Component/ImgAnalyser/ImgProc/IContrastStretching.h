

#pragma once

#include <IBase.h>

class IBuffer;

class IContrastStretching : public IBase
{
public:
	virtual bool CSGray(IBuffer* pBufIn, long lW, long lH, IBuffer* pBufOut) = 0;
};