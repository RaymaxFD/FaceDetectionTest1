#pragma once

#include <IWorker.h>
#include <Media\IMedia.h>
#include <iv_macro.h>

#include <Component/ImgAnalyser/IWideAngle360.h>

class IBufferPool;
class IBuffer;
class IString;

class IEvtFaceLandmarkDetection_V1;
class IFaceLandmarkDetection_V1 : public IWorker, public IMedia, public IEvtWideAngle360_V10
{
public:
	enum _eType
	{
		eNone,
		eTrain,
		eEval,
	};
	virtual void SetType(_eType eType) = 0;

public:
	virtual void SetIPool(IBufferPool* pI) = 0;
	virtual void SetIPool2(IBufferPool* pI) = 0;

public:
	virtual void IEvtAdd(IEvtFaceLandmarkDetection_V1* pI) = 0;
	virtual void IEvtRemove(IEvtFaceLandmarkDetection_V1* pI) = 0;
	virtual void IEvtAddReset() = 0;

public:
	virtual void SetFolderRoot(IString* strFolder) = 0;
	virtual void SetName(IString* strName) = 0;

public:
	virtual void FaceLandmark4Train() = 0;
	virtual void FaceLandmark4Evaluation(IBuffer* imgRGB24, size_t width, size_t height, size_t depth, std::vector<RECT>& vecRect, std::vector<IBuffer*>& vecFaces) {}
};


class IEvtFaceLandmarkDetection_V1
{
public:
	virtual void IEvtAddRef() {}
	virtual void IEvtRelease() {}
	virtual long IEvtGetRefCnt() { return 0; }

public:
	virtual void IEvtFLDTrainFailV1() {}
	virtual void IEvtFLDTrainOkV1() {}
	virtual void IEvtFLDEvalFailV1() {}
	virtual void IEvtFLDEvalBeginV1() {}
	virtual void IEvtFLDEvalRectV1(RECT rt) {}
	virtual void IEvtFLDEvalChipV1(IBuffer* pIBufff) {}
	virtual void IEvtFLDEvalEndV1() {}

public:
	virtual bool IEvtFLDEvalNewFaceBegin() { return true; }
	virtual void IEvtFLDEvalNewFace(DWORD dwContextID, IBuffer * pIBuf, size_t nWidth, size_t nHeight, size_t nDepth, RECT rtFace) {}
	virtual void IEvtFLDEvalNewFaceEnd() {}
	virtual void IEvtFLDEvalNewFaceNotFound() {}
	virtual void IEvtFLDFaceFound(int iChannel, bool bFound) {}
};



