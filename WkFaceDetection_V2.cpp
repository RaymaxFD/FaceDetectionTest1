#include "pch.h"
#include "WkFaceDetection_V2.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <ImgProc.h>

using namespace cv;
using namespace std;

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

		if (DoMotionDetection())
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
{
}

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
	IV_RELEASE(m_pIGrayThres);
	IV_RELEASE(m_pIPool);
}

void CWkFaceDetection_V2::NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV)
{
	m_strideY = strideY;
	m_strideUV = strideUV;
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pIPool->CheckLenAndSize(m_nWidth * m_nHeight * 4, 100);

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
	IBuffer* pIRGB = nullptr, * pIRGBDiff = nullptr, * pIRGBResize = nullptr, * pIRGBThres = nullptr;
	m_pIPool->GetIBuffer(&pIRGB);

	// YUV420 -> RGB32
	RECT rtROI = { 0, };
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
#if false
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

bool CWkFaceDetection_V2::DoMotionDetection()
{
	bool bOk = true;
	IBuffer* pIGray = nullptr, *pIGrayDiff = nullptr, * pIGrayResize = nullptr;
	RECT rtROI = { 0, };
	CRect rtMoving = {(int)m_nWidth, (int)m_nHeight, 0, 0};

	// Y 채널 복사
	m_pIPool->GetIBuffer(&pIGray);
	pIGray->SetData(m_pIY);

	// 이미지 크기를 4배로 줄임
	size_t nWidthResize = m_nWidth / 4;
	size_t nHeightResize = m_nHeight / 4;
	m_pIPool->GetIBuffer(&pIGrayResize);
	if (!m_pIGeo->Resize(pIGray, pIGrayResize, m_nWidth, m_nHeight, nWidthResize, nHeightResize, 1))
	{
		ASSERT(0);
		bOk = false;
		goto _DoMotionDetectionCleanup;
	}

	// 이전 이미지와 차연산
	if (m_pIBuffBk)
	{
		m_pIPool->GetIBuffer(&pIGrayDiff);
		if (!m_pIArith->Sub(pIGrayResize, m_pIBuffBk, pIGrayDiff, nWidthResize, nWidthResize, 1, rtROI))
		{
			ASSERT(0);
			bOk = false;
			goto _DoMotionDetectionCleanup;
		}
		m_pIBuffBk->SetData(pIGrayResize);
	}
	else
	{
		m_pIPool->GetIBuffer(&m_pIBuffBk);
		goto _DoMotionDetectionCleanup;
	}
	

	// threshold
	IV_RELEASE(m_pIGrayThres);
	m_pIPool->GetIBuffer(&m_pIGrayThres);
	if (!m_pIThres->Threshold(pIGrayDiff, m_pIGrayThres, (DWORD)nWidthResize, (DWORD)nHeightResize, 230, 255, 1, IThreshold::eGreaterThen, rtROI))
	{
		ASSERT(0);
		bOk = false;
		goto _DoMotionDetectionCleanup;
	}

	// labeling
#if false
	{
		//Mat image = imread("D:\\Temp\\Diagrams.png");
		/*Mat image = Mat((int)nHeightResize, (int)nWidthResize, CV_8UC1);
		image.data = m_pIGrayThres->GetBuffer();*/
		Mat image_bi = Mat((int)nHeightResize, (int)nWidthResize, CV_8UC1);
		image_bi.data = m_pIGrayThres->GetBuffer();

		// 라벨 레이어 변수
		Mat img_label;
		Mat stats;
		Mat centroids;
		int label;


		//이미지 축소/확대
		//resize(image, image, Size(500, 500));

		// 복사
		//label_box = image_gray.clone();

		//그레이스케일
		//cvtColor(image, image_gray, COLOR_RGB2GRAY);

		//이진화
		//threshold(image_gray, image_bi, 230, 255, THRESH_BINARY);
		//image_bi = ~image_bi;

		label = connectedComponentsWithStats(image_bi, img_label, stats, centroids, 8, CV_32S);
		//OutputDebugStringIV(L"label : %d\r\n", label);
		for (int j = 1; j < label; j++)
		{
			int area = stats.at<int>(j, CC_STAT_AREA);
			int left = stats.at<int>(j, CC_STAT_LEFT);
			int top = stats.at<int>(j, CC_STAT_TOP);
			int width = stats.at<int>(j, CC_STAT_WIDTH);
			int height = stats.at<int>(j, CC_STAT_HEIGHT);

			// 라벨링 박스
			//rectangle(label_box, Point(left, top), Point(left + width, top + height), Scalar(0, 0, 255), 3);

			//OutputDebugStringIV(L"area : %d, left : %d, top : %d, width : %d, height : %d\r\n", area, left, top, width, height);

		}

		//imshow("binary", image_bi);
		//imshow("label box", label_box);
	}
#endif
#if false
	{
		IString* pIStr = _GetIStr();
		static DWORD nCnt = 0;
		pIStr->Format(L"C:\\temp\\FaceDetection\\test_%04d.bmp", nCnt++);
		SaveImgFile(pIStr->Get(), pIGray, m_nWidth, m_nHeight, 1);
		//SaveImgFile(pIStr->Get(), pIGrayResize, nWidthResize, nHeightResize, 1);
		//SaveImgFile(pIStr->Get(), pIGrayDiff, nWidthResize, nHeightResize, 1);
		//SaveImgFile(pIStr->Get(), pIGrayThres, nWidthResize, nHeightResize, 1);		
		IV_RELEASE(pIStr);
	}
#endif

	// 움직임이 있는 영역의 최외곽 좌표 구하기
	{
		BYTE* pImg = m_pIGrayThres->GetBuffer();
		for (auto j = 0; j < nHeightResize; j++)
		{
			for (auto i = 0; i < nWidthResize; i++)
			{
				BYTE ucPixel = PixelGray(pImg, i, j, nWidthResize);

				if (ucPixel == 255)
				{
					if (i < rtMoving.left)
						rtMoving.left = i;
					if (i > rtMoving.right)
						rtMoving.right = i;
					if (j < rtMoving.top)
						rtMoving.top = j;
					if (j > rtMoving.bottom)
						rtMoving.bottom = j;
				}
			}
		}
		OutputDebugStringIV(L"L :%d, T : %d, R : %d, B : %d\r\n", rtMoving.left, rtMoving.top, rtMoving.right, rtMoving.bottom);
	}

	//ShowDebugVideo(m_pIY, m_nWidth, m_nHeight, 1);
	//ShowDebugVideo(pIGray, m_nWidth, m_nHeight, 1);
	//ShowDebugVideo(pIGrayDiff, nWidthResize, nHeightResize, 1);
	ShowDebugVideo(m_pIGrayThres, nWidthResize, nHeightResize, 1);

_DoMotionDetectionCleanup:
	IV_RELEASE(pIGray);
	IV_RELEASE(pIGrayDiff);
	IV_RELEASE(pIGrayResize);

	return bOk;
}

void CWkFaceDetection_V2::ShowDebugVideo(IBuffer* pIBuff, size_t nWidth, size_t nHeight, size_t nDepth)
{
	IBuffer* pIGray3 = nullptr;
	m_pIPool->GetIBuffer(&pIGray3);
	BYTE* ucGray3 = pIGray3->GetBuffer();
	BYTE* ucGray = pIBuff->GetBuffer();
	unsigned int uiAll = nWidth * nHeight;
	while (uiAll-- > 0)
	{
		*ucGray3++ = *ucGray;
		*ucGray3++ = *ucGray;
		*ucGray3++ = *ucGray++;
	}

	m_pIDebug->NewVideoRGB(0, pIGray3, nWidth, nHeight, 3);
	pIGray3->Release();

	//m_pIDebug->NewVideoYUV(0, m_pIY, m_pIU, m_pIV, m_strideY, m_strideUV, m_nWidth, m_nHeight, eYUV420);
}