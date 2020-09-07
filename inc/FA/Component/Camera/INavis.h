
#pragma once

#include <IBase.h>

class IEvtNavisMCL_V1;
class IBufferPool;
class IMedia2;

class INavisMCL_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtNavisMCL_V1* pI) = 0;
	virtual void AddIMediaOut(IMedia2* pI) = 0;

public:
	virtual void SetIBufferPool(IBufferPool* pI) = 0;
	virtual void SetContextID(DWORD dwContextID) = 0;

public:
	virtual bool OpenLibrary(long lCam) = 0;
	virtual void CloseLibrary() = 0;

public:
	virtual void SWTrigger() = 0;
};

class IEvtNavisMCL_V1
{
};
