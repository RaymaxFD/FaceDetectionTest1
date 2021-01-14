
#pragma once

#include "ibase.h"

class IRestart : public IBase
{
public:
	virtual bool CheckProcessWasRestarted() = 0;
	virtual bool CheckForRestartProcessStart() = 0;
	virtual bool WaitForPreviousProcessFinish() = 0;
	virtual bool DoRestartProcessFinish() = 0;
	virtual bool ActivateRestartProcess() = 0;
};