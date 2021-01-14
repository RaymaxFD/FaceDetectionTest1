

#pragma once

#include <IBase.h>

class IGUIDGen : public IBase
{
public:
	virtual void GUIDGen(TCHAR (&strGUID)[MAX_PATH]) = 0;
};
