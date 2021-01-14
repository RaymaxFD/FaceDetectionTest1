
#pragma once

#include <IBase.h>

class ISyncCritical : public IBase
{
public:
	virtual void EnterCritical() = 0;
	virtual void LeaveCritical() = 0;
};