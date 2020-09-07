#pragma once

#include <IWorker.h>
#include <Media\IMedia.h>
#include <Component\ImgAnalyser\IFaceLandmarkDetection.h>

class IString;
class IBuffer;

class IEvtEvaluation_V1;
class IEvaluation_V1 : public IWorker, public IMedia, public IEvtFaceLandmarkDetection_V1
{
public:
	virtual void IEvtAdd(IEvtEvaluation_V1* pI) = 0;
	virtual void IEvtRemove(IEvtEvaluation_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetDNNFile(IString* strDNNFile) = 0;
	virtual void SetRectFace(RECT rt) = 0;
	virtual void Evaluation(IBuffer* pIBuffInput, DWORD dwWidth = 128, DWORD dwHeight = 128, DWORD dwDepth = 3) = 0;
};

class IEvtEvaluation_V1
{
public:
	virtual void IEvtEvaluationFaceDetectedBegin() {}
	virtual void IEvtEvaluationFaceDetected(DWORD dwContextID, int iID, double dScore, RECT rtFace) {}
	virtual void IEvtEvaluationFaceDetectedEnd() {}
	virtual void IEvtEvaluationFaceNotFound() {}
};
