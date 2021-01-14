
#pragma once
#include <IBase.h>

class ISyncMutex : public IBase
{
public:
	virtual bool CreateMutex(TCHAR* strName, DWORD& dwErr) = 0;
	virtual bool EnterMutex(DWORD dwTimeOut = INFINITE) = 0;
	virtual void LeaveMutex() = 0;
};