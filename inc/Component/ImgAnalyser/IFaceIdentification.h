#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>
#include <Component/STDYCH/IString.h>

class IBuffer;
class IEvtFaceIdentification_V1;
class IEvtFaceIdentification_V2;
class IEvtFaceIdentification_V3;

class IFaceIdentification_V1 : public IWorker, public IMedia
{
public:
	virtual void IEvtAdd(IEvtFaceIdentification_V1* pI) = 0;
	virtual void IEvtRemove(IEvtFaceIdentification_V1* pI) = 0;
	virtual void IEvtResest() = 0;

public:
	virtual bool TeachNew(IBuffer* pIImg, size_t nWidth, size_t nHeight, size_t nDepth, tstring strname) = 0; // 예를 들어, 한 사람만 촬영이 되어야 함.
	virtual void Match(DWORD dwContextID, IBuffer* pIImg, size_t nWidth, size_t nHeight, size_t nDepth) = 0;

public:
	virtual void SetFaceDetectorFile(const TCHAR* pStr) = 0; // mmod_human_face_detector
	virtual void SetLandmarkDetectorFile(const TCHAR* pStr) = 0; // shape_predictor_5_face_landmarks
	virtual void SetFaceRecognitionFile(const TCHAR* pStr) = 0; // dlib_face_recognition_resnet_model_v1
};

class IEvtFaceIdentification_V1
{
public:
	virtual void IEvtFaceMatch(DWORD dwContextID, RECT rtArea) { ASSERT(0); }
	virtual void IEvtNoFace() { ASSERT(0); }
};








#include <Component/ImgAnalyser/IWideAngle360.h>


class IFaceIdentification_V2 : public IWorker, public IMedia, public IEvtWideAngle360_V10
{
public:
	struct _stTeachNew
	{
		IString* pIOrgFile;
		IString* pIName;
		IString* pICropFile;
	};

public:
	virtual void IEvtAdd(IEvtFaceIdentification_V2* pI) = 0;
	virtual void IEvtRemove(IEvtFaceIdentification_V2* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void TeachNew(IFaceIdentification_V2::_stTeachNew stTeachNew) = 0; // 예를 들어, 한 사람만 촬영이 되어야 함.
	virtual void TeachNewClear() = 0;
	virtual void CropFace(IBuffer* pIIn, size_t nW, size_t nH, size_t nD, IBuffer* pIOut) = 0;
	virtual void EnableMotionDetection(bool bEnable) = 0;

public:
	virtual void SetFaceDetectorFile(const TCHAR* pStr) = 0; // mmod_human_face_detector
	virtual void SetLandmarkDetectorFile(const TCHAR* pStr) = 0; // shape_predictor_5_face_landmarks
	virtual void SetFaceRecognitionFile(const TCHAR* pStr) = 0; // dlib_face_recognition_resnet_model_v1

public:
	virtual void SetFaceThres(double dThres) = 0;
	virtual void SetIBufferPool4RGB(IBufferPool* pI) = 0;
};

class IEvtFaceIdentification_V2
{
public:
	virtual void IEvtAddRef() { ASSERT(0); }
	virtual void IEvtRelease() { ASSERT(0); }
	virtual long IEvtGetRef() { ASSERT(0); return 0; }

public:
	virtual void IEvtFaceMatchBegin(DWORD dwContextID, int iFaceCnt) {}
	virtual void IEvtFaceMatch(DWORD dwContextID, int iPerson, RECT rtArea) { ASSERT(0); }
	virtual void IEvtFaceMatchEnd(DWORD dwContextID) {}
	virtual void IEvtFaceNoMatch(DWORD dwContextID) { ASSERT(0); }
	virtual void IEvtNoFace() { ASSERT(0); }
};



class IFaceIdentification_V3 : public IWorker, public IMedia
{
public:
	struct _stTeachNew
	{
		IString* pIOrgFile;
		IString* pIName;
		IString* pICropFile;

		void AddRef()
		{
			pIOrgFile->AddRef();
			pIName->AddRef();
			pICropFile->AddRef();
		}

		void Release()
		{
			pIOrgFile->Release();
			pIName->Release();
			pICropFile->Release();
		}
	};

public:
	virtual void IEvtAdd(IEvtFaceIdentification_V3* pI) = 0;
	virtual void IEvtRemove(IEvtFaceIdentification_V3* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void TeachNew(IString* pIOrgFile, IString* pIName, IString* pICropFile) = 0; // 예를 들어, 한 사람만 촬영이 되어야 함.
	virtual void TeachNewClear() = 0;
	virtual void CropFace(IBuffer* pIIn, size_t nW, size_t nH, size_t nD, IBuffer* pIOut) = 0;
	virtual void EnableMotionDetection(bool bEnable) = 0;

public:
	virtual void SetFaceDetectorFile(const TCHAR* pStr) = 0; // mmod_human_face_detector
	virtual void SetLandmarkDetectorFile(const TCHAR* pStr) = 0; // shape_predictor_5_face_landmarks
	virtual void SetFaceRecognitionFile(const TCHAR* pStr) = 0; // dlib_face_recognition_resnet_model_v1

public:
	virtual void SetCustomContextID(DWORD dwID) = 0;
	virtual void SetFaceThres(double dThres) = 0;
	virtual void SetIBufferPool4RGB(IBufferPool* pI) = 0;

public:
	virtual void ROIAdd(RECT rt) = 0;
	virtual void ROIAddOk() = 0;
	virtual void ROIReset() = 0;
};

class IEvtFaceIdentification_V3
{
public:
	virtual void IEvtAddRef() { /*ASSERT(0);*/ }
	virtual void IEvtRelease() { /*ASSERT(0);*/ }
	virtual long IEvtGetRef() { /*ASSERT(0);*/ return 0; }

public:
	virtual void IEvtFaceMatchBegin(DWORD dwContextID, int iFaceCnt) {}
	virtual void IEvtFaceMatch(DWORD dwContextID, int iPerson, RECT rtArea) { ASSERT(0); }
	virtual void IEvtFaceMatchEnd(DWORD dwContextID) {}
	virtual void IEvtFaceNoMatch(DWORD dwContextID) { ASSERT(0); }
	virtual void IEvtNoFace() { ASSERT(0); }
};
