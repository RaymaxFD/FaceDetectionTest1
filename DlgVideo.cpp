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

	DWORD dwErr = 0;
	m_pISync = _GetIMutex();
	m_pISync->CreateMutex(L"SYNC_FACE_DETECTION", dwErr);

	// 사용되는 메모리들을 미리 할당하기 위하여 필요한 IBufferPool 인터페이스들
	m_pIPool4Cam = _GetIBufPool();
	m_pIPool4Dec0 = _GetIBufPool();
	m_pIPool4Dec1 = _GetIBufPool();
	m_pIPool4Cam->CreateBufferList();
	m_pIPool4Dec0->CreateBufferList();
	m_pIPool4Dec1->CreateBufferList();

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
	

	// IMedia인터페이스 연결
	m_pICamera->IMediaAdd(m_pIDec); // 카메라 -> 비디오 디코더로 
	m_pIDec->IMediaAdd(m_pIDisp); // 디코더 -> 화면 출력으로
	m_pIDec->IMediaAdd(this); // 디코더 -> 안면 인식으로
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

	IV_STOPWORK(m_pIDisp);

	IV_RELEASE(m_pIPool4Cam);
	IV_RELEASE(m_pIPool4Dec0);
	IV_RELEASE(m_pIPool4Dec1);

	IV_RELEASE(m_pISync);
	CloseHandle(m_hSharedFoundFace);
	CloseHandle(m_hSharedStrideY);
	CloseHandle(m_hSharedStrideUV);
	CloseHandle(m_hSharedWidth);
	CloseHandle(m_hSharedHeight);
	CloseHandle(m_hSharedVideoY);
	CloseHandle(m_hSharedVideoU);
	CloseHandle(m_hSharedVideoV);

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

	IRegistry* pIReg = _GetIRegistry();
	TCHAR strTemp[MAX_PATH];
	DWORD dwErr = 0;
	if (!pIReg->ReadString(L"Raymax", L"FaceDetectionTest1", L"Camera", L"RTSP_URL", strTemp, MAX_PATH, dwErr))
	{
		_stprintf_s(strTemp, L"rtsp://192.168.0.101:554/h264");
		pIReg->WriteString(L"Raymax", L"FaceDetectionTest1", L"Camera", L"RTSP_URL", strTemp, dwErr);
	}

	USES_CONVERSION;
	m_pICamera->OpenURL(W2A(strTemp));

	return 0;
}


void CDlgVideo::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_pIDisp->OnSize();
}

LRESULT CDlgVideo::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	switch (message)
	{
	/*case msgFaceBegin:
		m_pIDisp->RectReset();
		break;

	case msgFaceFound:
	{
		RECT rtFace;
		while (m_QueueRect.DeQueue(rtFace))
		{
			COLORREF color = RGB(255, 0, 0);
			m_pIDisp->RectAdd(rtFace, 5, color);
		}
	}
		break;*/

	case msgLicenseFail:
	{
		AfxMessageBox(L"라이센스 확인에 실패하였습니다. 안면 인식이 되지 않겠습니다.");
	}
		break;

	case msgVideoY:
	{
		IV_RELEASE(m_pIY);
		m_pIY = reinterpret_cast<IBuffer*>(wParam);
	}
		break;

	case msgVideoU:
	{
		IV_RELEASE(m_pIU);
		m_pIU = reinterpret_cast<IBuffer*>(wParam);
	}
	break;

	case msgVideoV:
	{
		IV_RELEASE(m_pIV);
		m_pIV = reinterpret_cast<IBuffer*>(wParam);

		m_pISync->EnterMutex();
		{

			{
				m_hSharedFoundFace = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedFoundFace");
				if (!m_hSharedFoundFace)
					m_hSharedFoundFace = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(sizeof(int) + sizeof(RECT) * 100), L"SharedFoundFace");
				BYTE* pFoundFace = (BYTE*)::MapViewOfFile(m_hSharedFoundFace, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(sizeof(int) + sizeof(RECT) * 100));
				BYTE* pTemp = pFoundFace;
				int iFaceCnt = *pTemp;
				pTemp += sizeof(int);
				if (iFaceCnt > 0)
				{
					m_pIDisp->RectReset();

					RECT rtFace = {};
					for (auto i = 0; i < iFaceCnt; i++)
					{
						rtFace = *(RECT*)pTemp;
						pTemp += sizeof(RECT);

						COLORREF color = RGB(255, 0, 0);
						m_pIDisp->RectAdd(rtFace, 5, color);

						//OutputDebugStringIV(L"%d %d %d %d\r\n", rtFace.left, rtFace.top, rtFace.right, rtFace.bottom);
					}
				}
				*(int*)pFoundFace = 0;
				UnmapViewOfFile(pFoundFace);
			}

			m_hSharedStrideY = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedStrideY");
			if (!m_hSharedStrideY)
				m_hSharedStrideY = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedStrideY");
			size_t* pStrideY = (size_t*)::MapViewOfFile(m_hSharedStrideY, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
			*pStrideY = m_strideY;
			UnmapViewOfFile(pStrideY);

			m_hSharedStrideUV = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedStrideUV");
			if (!m_hSharedStrideUV)
				m_hSharedStrideUV = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedStrideUV");
			size_t* pStrideUV = (size_t*)::MapViewOfFile(m_hSharedStrideUV, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
			*pStrideUV = m_strideUV;
			UnmapViewOfFile(pStrideUV);

			m_hSharedWidth = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedWidth");
			if (!m_hSharedWidth)
				m_hSharedWidth = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedWidth");
			size_t* pWidth = (size_t*)::MapViewOfFile(m_hSharedWidth, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
			*pWidth = m_nWidth;
			UnmapViewOfFile(pWidth);

			m_hSharedHeight = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedHeight");
			if (!m_hSharedHeight)
				m_hSharedHeight = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedHeight");
			size_t* pHeight = (size_t*)::MapViewOfFile(m_hSharedHeight, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
			*pHeight = m_nHeight;
			UnmapViewOfFile(pHeight);

			m_hSharedVideoY = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoY");
			if (!m_hSharedVideoY)
				m_hSharedVideoY = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideY * m_nHeight), L"SharedVideoY");
			BYTE* pY = (BYTE*)::MapViewOfFile(m_hSharedVideoY, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideY * m_nHeight));
			CopyMemory(pY, m_pIY->GetBuffer(), m_pIY->GetBufferSizeUsed());
			UnmapViewOfFile(pY);

			m_hSharedVideoU = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoU");
			if (!m_hSharedVideoU)
				m_hSharedVideoU = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideUV * m_nHeight), L"SharedVideoU");
			BYTE* pU = (BYTE*)::MapViewOfFile(m_hSharedVideoU, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideUV * m_nHeight));
			CopyMemory(pU, m_pIU->GetBuffer(), m_pIU->GetBufferSizeUsed());
			UnmapViewOfFile(pU);

			m_hSharedVideoV = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoV");
			if (!m_hSharedVideoV)
				m_hSharedVideoV = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideUV * m_nHeight), L"SharedVideoV");
			BYTE* pV = (BYTE*)::MapViewOfFile(m_hSharedVideoV, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideUV * m_nHeight));
			CopyMemory(pV, m_pIV->GetBuffer(), m_pIV->GetBufferSizeUsed());
			UnmapViewOfFile(pV);
		}
		m_pISync->LeaveMutex();
	}
	break;

	default:
		break;
	}

	return __super::WindowProc(message, wParam, lParam);
}

void CDlgVideo::NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV)
{
	m_strideY = strideY;
	m_strideUV = strideUV;
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	pIY->AddRef();
	PostMessage(msgVideoY, reinterpret_cast<WPARAM>(pIY));

	pIU->AddRef();
	PostMessage(msgVideoU, reinterpret_cast<WPARAM>(pIU));

	pIV->AddRef();
	PostMessage(msgVideoV, reinterpret_cast<WPARAM>(pIV));
}