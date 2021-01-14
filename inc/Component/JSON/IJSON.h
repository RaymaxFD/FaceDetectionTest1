#pragma once

#include <IBase.h>

class IJSONParser_V1 : public IBase
{
public:
	virtual void Parsing(TCHAR* pStrFile) = 0;
};
