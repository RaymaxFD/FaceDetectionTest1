// DlgVideo4Debug.cpp: 구현 파일
//

#include "pch.h"
#include "FaceDetectionTest1.h"
#include "DlgVideo4Debug.h"
#include "afxdialogex.h"


// CDlgVideo4Debug 대화 상자

IMPLEMENT_DYNAMIC(CDlgVideo4Debug, CDialogEx)

CDlgVideo4Debug::CDlgVideo4Debug(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIDEO4DEBUG, pParent)
{
	m_pIDisp = _GetIDisplay2();
	m_pIDisp->StartWork();
}

CDlgVideo4Debug::~CDlgVideo4Debug()
{
}

void CDlgVideo4Debug::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgVideo4Debug, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgVideo4Debug::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgVideo4Debug::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgVideo4Debug 메시지 처리기


void CDlgVideo4Debug::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CDlgVideo4Debug::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CDlgVideo4Debug::OnDestroy()
{
	__super::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	IV_STOPWORK(m_pIDisp);
}


int CDlgVideo4Debug::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_pIDisp->Init(0, m_hWnd);
	m_pIDisp->Update();

	return 0;
}


void CDlgVideo4Debug::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_pIDisp->OnSize();
}

IMedia* CDlgVideo4Debug::GetIMedia()
{
	return m_pIDisp->GetIMedia();
}