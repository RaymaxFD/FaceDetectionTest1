

#pragma once

#include <stdint.h>

class IBase
{
public:
	virtual IBase* GetIBase()
	{
		return (IBase*)this;
	}

	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

	virtual TCHAR* GetDecription()	{	return	NULL;	}
};
