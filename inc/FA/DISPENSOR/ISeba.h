

#pragma once

#include <IBase.h>
#include <tchar.h>

class ISeba : public IBase
{
public:
	virtual bool CommOpen(LPCTSTR strComPort = _T("COM1")) = 0;
	virtual void CommClose() = 0;
public:
	virtual bool Start(DWORD dwTime = 0) = 0;
	virtual bool Stop() = 0;
};
