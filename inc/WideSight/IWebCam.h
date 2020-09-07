
#pragma once

#include <IWorker.h>
#include <string>

class IBufferPool;
class IMedia;

class IEvtWebCam_V1;
class IWebCam_V1 : public IWorker
{
public:
	virtual bool CaptureStart() = 0;
	virtual void CaptureStop() = 0;

public:
	virtual void SetPool(IBufferPool* pI) = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void EnableSave(bool b, int iCnt = -1) = 0;
	virtual void SetName(tstring& strName) = 0;

public:
	virtual void IEvtAdd(IEvtWebCam_V1* pI) = 0;
	virtual void IEvtRemove(IEvtWebCam_V1* pI) = 0;
	virtual void IEvtReset() = 0;
};

class IEvtWebCam_V1
{
public:
	virtual void NewImage(tstring& file){}
	virtual void NewImageDone(){}
};