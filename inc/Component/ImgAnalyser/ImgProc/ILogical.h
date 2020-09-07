#pragma once

#include <IBase.h>

class IBuffer;

class ILogical : public IBase
{
public:
	virtual bool And(IBuffer* pIImg, IBuffer* pIMask, IBuffer* pIRst, size_t nWidth, size_t nHeight, size_t nDepth, RECT* pROI = NULL) = 0;
};
