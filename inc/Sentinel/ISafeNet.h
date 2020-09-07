#pragma once


#include <IBase.h>

class ISafeNet_V1 : public IBase
{
public:
	virtual bool SFLogin(TCHAR* pClassName) = 0;
	virtual void SFLogout() = 0;
	virtual CHAR* SFGetSession() = 0;
};