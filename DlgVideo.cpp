// DlgVideo.cpp: 구현 파일
//

#include "pch.h"
#include "FaceDetectionTest1.h"
#include "DlgVideo.h"
#include "afxdialogex.h"
#include "DlgVideo4Debug.h"


// CDlgVideo 대화 상자

IMPLEMENT_DYNAMIC(CDlgVideo, CDialogEx)

CDlgVideo::CDlgVideo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIDEO, pParent)
#ifdef DEBUG_VIDEO
	, m_pDlg4Debug(new CDlgVideo4Debug)
#endif
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

	IV_GET_IF(m_hInstFD, ID_DLL_FACEDETECTION, ID_FACEDETECTION_V2, IFaceDetection_V2, m_pIFD);
	m_pIFD->StartWork();
	m_pIFD->IEvtAdd(this);

	m_pIFD->SetIBuffPool(m_pIPool4FD);
	//m_pIFD->SetIMedia4Debug(m_pDlg4Debug->GetIMedia());
	{
		IDirectory* pIDir = _GetIDir();
		IString* pIStrMMOD = pIDir->GetRunPath();
		pIStrMMOD->Add1(L"\\mmod_human_face_detector.dat");
		m_pIFD->SetMMODFile(pIStrMMOD);
		IV_RELEASE(pIStrMMOD);
		IV_RELEASE(pIDir);
	}

	m_pICamera->IMediaAdd(m_pIDec);
	m_pIDec->IMediaAdd(m_pIDisp);
	m_pIDec->IMediaAdd(m_pIFD);

	m_pILic = _GetILicense();
	m_pILic->StartWork();
	m_pILic->IEventAdd(this);
	{
		IDirectory* pIDir = _GetIDir();
		IString* pIFileLicense = pIDir->GetRunPath();
		pIFileLicense->Add1(L"\\License.dat");
		m_pILic->CheckLicense(pIFileLicense->Get(), (BYTE*)"9FCC933B-EFAD-4FBF-8932-A321F7948523");
		pIFileLicense->Release();
		pIDir->Release();
	}
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
	IV_STOPWORK(m_pIFD);

	IV_STOPWORK(m_pIDisp);

	IV_RELEASE(m_pIPool4Cam);
	IV_RELEASE(m_pIPool4Dec0);
	IV_RELEASE(m_pIPool4Dec1);
	IV_RELEASE(m_pIPool4FD);

#ifdef DEBUG_VIDEO
	m_pDlg4Debug->DestroyWindow();
	delete m_pDlg4Debug;
#endif
}


int CDlgVideo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.	

#ifdef DEBUG_VIDEO
	m_pDlg4Debug->Create(IDD_VIDEO4DEBUG, this);
	m_pDlg4Debug->ShowWindow(SW_SHOW);
#endif

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

void CDlgVideo::IEvtFaceBeginV2()
{
	PostMessage(msgFaceBegin);
}

void CDlgVideo::IEvtFaceFoundV2(RECT& rtFace)
{
	RECT* pRect = new RECT;
	*pRect = rtFace;
	PostMessage(msgFaceFound, reinterpret_cast<WPARAM>(pRect));
}

LRESULT CDlgVideo::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	switch (message)
	{
	case msgFaceBegin:
		m_pIDisp->RectReset();
		break;

	case msgFaceFound:
	{
		RECT* pRect = reinterpret_cast<RECT*>(wParam);
		COLORREF color = RGB(255, 0, 0);
		m_pIDisp->RectAdd(*pRect, 5, color);
		delete pRect;
	}
		break;

	case msgLicenseFail:
	{
		AfxMessageBox(L"라이센스 확인에 실패하였습니다. 안면 인식이 되지 않겠습니다.");
	}
		break;

	default:
		break;
	}

	return __super::WindowProc(message, wParam, lParam);
}

void CDlgVideo::ILicenseCheckOk() 
{
	Sleep(0);
}

void CDlgVideo::ILicenseCheckFail() 
{
	PostMessage(msgLicenseFail);
}