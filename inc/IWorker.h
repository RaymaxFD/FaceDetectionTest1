

#pragma once

#include <IBase.h>

class IWorker : public IBase
{
public:
	virtual IWorker* GetIWorker()
	{
		return (IWorker*)this;
	}

	virtual void StartWork(IBase* pIParent = NULL, DWORD dwWaitTime = INFINITE)	{}
	virtual void StopWork(DWORD dwWaitTime = INFINITE)	{}
};
