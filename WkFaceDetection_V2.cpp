#include "pch.h"
#include "WkFaceDetection_V2.h"

IMPLEMENT_WORKER(CWkFaceDetection_V2)
CWkFaceDetection_V2::CWkFaceDetection_V2()
{
	m_pICC = _GetICC();
	m_pIArith = _GetIArithmetic();
	m_pIGeo = _GetIGeo();
	m_pIThres = _GetIThres();
}

CWkFaceDetection_V2::~CWkFaceDetection_V2()
{}

void CWkFaceDetection_V2::DoJob()
{}

void CWkFaceDetection_V2::DoMsgProc(MSG msg, void* pParam)
{
	DOMSGPROC;

	switch (message)
	{
	case msgImageY:
	{
		IV_RELEASE(m_pIY);

		IBuffer* pI = reinterpret_cast<IBuffer*>(pParam);
		m_pIY = pI;
		pI->Release();

		m_pIY->AddRef();
	}
		break;

	case msgImageU:
	{
		IV_RELEASE(m_pIU);

		IBuffer* pI = reinterpret_cast<IBuffer*>(pParam);
		m_pIU = pI;
		pI->Release();

		m_pIU->AddRef();
	}
		break;

	case msgImageV:
	{
		IV_RELEASE(m_pIV);

		IBuffer* pI = reinterpret_cast<IBuffer*>(pParam);
		m_pIV = pI;
		pI->Release();

		m_pIV->AddRef();

		if (DoFaceDetection())
		{ }
	}
		break;

	default:
		break;
	}
}

void CWkFaceDetection_V2::DoMsgProc(UINT message, WPARAM wParam, LPARAM lParam, void* pParam)
{}

void CWkFaceDetection_V2::OnStartThread()
{}

void CWkFaceDetection_V2::OnStopThread()
{
	IV_RELEASE(m_pICC);
	IV_RELEASE(m_pIArith);
	IV_RELEASE(m_pIGeo);
	IV_RELEASE(m_pIThres);

	IV_RELEASE(m_pIY);
	IV_RELEASE(m_pIU);
	IV_RELEASE(m_pIV);

	IV_RELEASE(m_pIBuffBk);
	IV_RELEASE(m_pIPool);
}

void CWkFaceDetection_V2::NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV)
{
	m_strideY = strideY;
	m_strideUV = strideUV;
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pIPool->CheckLenAndSize(m_nWidth * m_nHeight * 4);

	pIY->AddRef();
	SetMSG(msgImageY, NULL, NULL, reinterpret_cast<void*>(pIY));

	// UV는 맨날 다 달라...............
	pIV->AddRef();
	SetMSG(msgImageU, NULL, NULL, reinterpret_cast<void*>(pIV));

	pIU->AddRef();
	SetMSG(msgImageV, NULL, NULL, reinterpret_cast<void*>(pIU));
}

void CWkFaceDetection_V2::SetIBuffPool(IBufferPool* pI)
{
	m_pIPool = pI;
	m_pIPool->AddRef();
}

bool CWkFaceDetection_V2::DoFaceDetection()
{
	bool bOk = true;

	bOk = DoMotionDetection();

	return bOk;
}

bool CWkFaceDetection_V2::DoMotionDetection()
{
	bool bOk = true;
	IBuffer* pIRGB = nullptr, *pIRGBDiff = nullptr, * pIRGBResize = nullptr, *pIRGBThres = nullptr;
	m_pIPool->GetIBuffer(&pIRGB);

	// YUV420 -> RGB32
	RECT rtROI = {0, };
	if (!m_pICC->ConvertYUV420ToRGB32(m_pIY, (int)m_strideY, m_pIU, (int)m_strideUV, 
		m_pIV, (int)m_strideUV, pIRGB, (long)m_nWidth, (long)m_nHeight, rtROI))
	{
		ASSERT(0);
		bOk = false;
		goto _DoFaceDetectionCleanup;
	}

	// 이미지 크기를 4배로 줄임
	size_t nWidthResize = m_nWidth / 4;
	size_t nHeightResize = m_nHeight / 4;
	m_pIPool->GetIBuffer(&pIRGBResize);
	if (!m_pIGeo->Resize(pIRGB, pIRGBResize, m_nWidth, m_nHeight, nWidthResize, nHeightResize, 4))
	{
		ASSERT(0);
		bOk = false;
		goto _DoFaceDetectionCleanup;
	}

	// 이전 이미지와 차연산
	if (m_pIBuffBk)
	{
		m_pIPool->GetIBuffer(&pIRGBDiff);
		if (!m_pIArith->Sub(pIRGBResize, m_pIBuffBk, pIRGBDiff, nWidthResize, nWidthResize, 4, rtROI))
		{
			ASSERT(0);
			bOk = false;
			goto _DoFaceDetectionCleanup;
		}
		m_pIBuffBk->SetData(pIRGBResize);
	}
	else
	{
		m_pIPool->GetIBuffer(&m_pIBuffBk);
		goto _DoFaceDetectionCleanup;
	}
	

	// threshold
	m_pIPool->GetIBuffer(&pIRGBThres);
	if (!m_pIThres->Threshold(pIRGBDiff, pIRGBThres, (DWORD)nWidthResize, (DWORD)nHeightResize, 100, 255, 4, IThreshold::eGreaterThen, rtROI))
	{
		ASSERT(0);
		bOk = false;
		goto _DoFaceDetectionCleanup;
	}
#if true
	{
		IString* pIStr = _GetIStr();
		static DWORD nCnt = 0;
		pIStr->Format(L"d:\\temp\\FaceDetection\\test_%04d.bmp", nCnt++);
		//SaveImgFile(pIStr->Get(), pIRGB, m_nWidth, m_nHeight, 4);
		//SaveImgFile(pIStr->Get(), pIRGBResize, nWidthResize, nHeightResize, 4);
		//SaveImgFile(pIStr->Get(), pIRGBDiff, nWidthResize, nHeightResize, 4);
		SaveImgFile(pIStr->Get(), pIRGBThres, nWidthResize, nHeightResize, 4);
		IV_RELEASE(pIStr);
	}
#endif

_DoFaceDetectionCleanup:
	IV_RELEASE(pIRGB);
	IV_RELEASE(pIRGBDiff);
	IV_RELEASE(pIRGBResize);
	IV_RELEASE(pIRGBThres);

	return bOk;
}