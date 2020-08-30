﻿// DlgVideo.cpp: 구현 파일
//

#include "pch.h"
#include "FaceDetectionTest1.h"
#include "DlgVideo.h"
#include "afxdialogex.h"
#include "WkFaceDetection_V2.h"


// CDlgVideo 대화 상자

IMPLEMENT_DYNAMIC(CDlgVideo, CDialogEx)

CDlgVideo::CDlgVideo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIDEO, pParent)
	, m_pFD(new CWkFaceDetection_V2)
{
	IMPLEMENT_IBASE;

	m_pIPool4Cam = _GetIBufPool();
	m_pIPool4Dec0 = _GetIBufPool();
	m_pIPool4Dec1 = _GetIBufPool();
	m_pIPool4FD = _GetIBufPool();
	m_pIPool4Cam->CreateBufferList();
	m_pIPool4Dec0->CreateBufferList();
	m_pIPool4Dec1->CreateBufferList();
	m_pIPool4FD->CreateBufferList();

	m_pIDisp = _GetIDisplay2();
	m_pIDisp->StartWork();

	IV_GET_IF(m_hInstRTSP, ID_DLL_IPCAM_RTSP, ID_RTSP_CLIENT_V1, IRTSPClient_V1, m_pICamera);
	m_pICamera->StartWork();
	m_pICamera->SetBufferPool(m_pIPool4Cam);

	IV_GET_IF(m_hInstDec, ID_DLL_DEC_VIDEO, ID_DEC_VIDEO_V1, IDecVideo_V1, m_pIDec);
	m_pIDec->StartWork();
	m_pIDec->SetBuffer(m_pIPool4Dec0, m_pIPool4Dec1);
	m_pIDec->StreamOpen();
	//m_pIDec->SwapUV(true);

	m_pFD->StartWork();
	m_pFD->SetIBuffPool(m_pIPool4FD);

	m_pICamera->IMediaAdd(m_pIDec);
	m_pIDec->IMediaAdd(m_pIDisp);
	m_pIDec->IMediaAdd(m_pFD);
}

CDlgVideo::~CDlgVideo()
{
}

void CDlgVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgVideo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgVideo::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgVideo::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgVideo 메시지 처리기


void CDlgVideo::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}


void CDlgVideo::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnCancel();
}


void CDlgVideo::OnDestroy()
{
	__super::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	IV_STOPWORK(m_pICamera);
	m_pIDec->StreamClose();
	IV_STOPWORK(m_pIDec);
	IV_STOPWORK(m_pFD);

	IV_STOPWORK(m_pIDisp);

	IV_RELEASE(m_pIPool4Cam);
	IV_RELEASE(m_pIPool4Dec0);
	IV_RELEASE(m_pIPool4Dec1);
	IV_RELEASE(m_pIPool4FD);
}


int CDlgVideo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.	

	m_pIDisp->Init(0, m_hWnd);
	m_pIDisp->Update();

	m_pICamera->OpenURL("rtsp://192.168.0.101:554/h264");

	return 0;
}


void CDlgVideo::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_pIDisp->OnSize();
}