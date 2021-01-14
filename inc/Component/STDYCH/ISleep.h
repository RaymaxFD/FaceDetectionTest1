
#pragma once

#include <IWorker.h>

class ISleep : public IWorker
{
public:
	virtual void Sleep(DWORD dwWaitTime) = 0;
};
