
#pragma once

#include <IWorker.h>
#include <media/IMedia.h>

class IString;

class IEvtIDecProbe;
class IDecProbe : public IWorker
{
public:
	virtual void IEvtAdd(IEvtIDecProbe* pI) = 0;
	virtual void IEvtRemove(IEvtIDecProbe* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void ProbeThis(IString* pStr) = 0;
};

class IEvtIDecProbe
{
public:
	virtual void IEvtIDecProbeVideoSize(size_t nWidth, size_t nHeight) {}
	virtual void IEvtIDecProbeVideoCodec(IMedia::_eCodecVideo){}
	virtual void IEvtIDecProbeGOP(int iGOP) {}
	virtual void IEvtIDecProbeOk() {}
	virtual void IEvtIDecProbeFail() {}
};