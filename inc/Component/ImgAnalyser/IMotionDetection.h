
#pragma once
#include <media/imedia.h>
#include <IWorker.h>
#include <vector>

class IBuffer;


class IEvtMotionDetection
{
public:
	virtual void IEvtMotionDetectionAddRef() = 0;
	virtual void IEvtMotionDetectionRelease() = 0;
	virtual long IEvtMotionDetectionGetRefCnt() = 0;

public:
	virtual void IEvtNewVideoRGB(IBuffer* pI, size_t nWidth, size_t nHeight, size_t nDepth) {}
	virtual void IEvtNewVideoYUV(IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t nWidth, size_t nHeight, size_t nStrideY, size_t nStrideUV) {}
	virtual void IEvtMotionDetectedBegin(DWORD dwContextID) {}
	virtual void IEvtMotionDetected(DWORD dwContextID, IBuffer* pIBuff) {}
	virtual void IEvtMotionDetectedEnd(DWORD dwContextID) {}
};

// 차연산 기반
class IMotionDetection_V1 : public IWorker, public IMedia
{
public:
	virtual void IEventAdd(IEvtMotionDetection* pI) = 0;
	virtual void IEventRemove(IEvtMotionDetection* pI) = 0;
	virtual void IEventReset() = 0;

public:
	virtual void SetContextID(DWORD dwID) = 0;
	virtual void SetThreshold(BYTE ucTh) = 0;
	virtual void SetROI(RECT rt) = 0;
};

// Kmeans 기반
class IMotionDetection_V2 : public IMotionDetection_V1
{};