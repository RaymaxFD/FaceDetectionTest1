#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IString;
class IBuffer;
class IBufferPool;

class IEvtFaceDetection_V1
{
public:
	virtual void IEvtFaceV1(IBuffer* pIFace, size_t nWidth, size_t nHeight, size_t nDepth) {}
};

class IEvtFaceDetection_V2
{
public:
	virtual void IEvtFaceBeginV2() {}
	virtual void IEvtFaceFoundV2(RECT& rtFace) {}
	virtual void IEvtFaceEndV2() {}
};

class IFaceDetection_V1 : public IWorker
{
public:
	virtual void IEvtAdd(IEvtFaceDetection_V1* pI) = 0;
	virtual void IEvtRemove(IEvtFaceDetection_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetMMODFile(IString* pIStr) = 0;
	virtual void SetShapePredictorFile(IString* pIStr) = 0;

public:
	virtual bool NewPic(IBuffer* pIImg, size_t nWidth, size_t nHeight, size_t nDepth) = 0;
};

class IFaceDetection_V2 : public IMedia, public IWorker
{
public:
	virtual void IEvtAdd(IEvtFaceDetection_V2* pI) = 0;
	virtual void IEvtRemove(IEvtFaceDetection_V2* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;

public:
	virtual void SetMMODFile(IString* pIStr) = 0;
	virtual void SetIBuffPool(IBufferPool* pI) = 0;
};