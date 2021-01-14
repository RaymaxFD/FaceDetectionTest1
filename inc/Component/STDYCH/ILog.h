
#pragma once

#include <IBase.h>

class ILog : public IBase
{
public:
	virtual BOOL Open(TCHAR* strPath) = 0;
	virtual void Close() = 0;
	virtual BOOL WriteLog(TCHAR* pStr, ...) = 0;
};