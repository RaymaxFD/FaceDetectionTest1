#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IEvtWebCam_V1;
class IWebCam_V1 : public IWorker
{
public:
	virtual void IEvtAdd(IEvtWebCam_V1* pI) = 0;
	virtual void IEvtRemove(IEvtWebCam_V1* pI) = 0;
	virtual void IEvtReset(IEvtWebCam_V1* pI) = 0;

public:
	virtual void IMediaAdd(IMedia* p) = 0;
	virtual void IMediaRemove(IMedia* p) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual bool CamOpen(BYTE ucCam = 0, size_t nWidth = 320, size_t nHeight = 240, BYTE ucFPS = 30) = 0;
	virtual void CamClose() = 0;
};

class IEvtWebCam_V1
{
};
