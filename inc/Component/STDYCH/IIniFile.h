#pragma once

#include <IBase.h>

class IString;

class IIniFile : public IBase
{
public:
	virtual void SetIniFileName(TCHAR* pStrFile) = 0;
	virtual IString* INIStringRead(TCHAR* strSection, TCHAR* strKey) = 0;
	virtual bool INIStringWrite(TCHAR* strSection, TCHAR* strKey, TCHAR* str) = 0;
};
