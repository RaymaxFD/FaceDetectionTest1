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

	m_pIIU = _GetIImgUtil();
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
	CloseHandle(m_hShareImageReady);

#ifdef DEBUG_VIDEO
	m_pDlg4Debug->DestroyWindow();
	delete m_pDlg4Debug;
#endif

	IV_RELEASE(m_pIIU);
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

//#define DEBUG_PRINT
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
		break;
	}
		break;

	case msgVideoU:
	{
		IV_RELEASE(m_pIU);
		m_pIU = reinterpret_cast<IBuffer*>(wParam);
		break;
	}
	break;

	case msgVideoV:
	{
		IV_RELEASE(m_pIV);
		m_pIV = reinterpret_cast<IBuffer*>(wParam);

#ifdef DEBUG_PRINT
		OutputDebugString(L"msgVideoV 0\r\n");
#endif

		//Sleep(33);

		if (!m_pISync->EnterMutex(1))
		{
			IV_RELEASE(m_pIY);
			IV_RELEASE(m_pIU);
			IV_RELEASE(m_pIV);
			break;
		}
#ifdef DEBUG_PRINT
		OutputDebugString(L"msgVideoV 1\r\n");
#endif

#ifdef DEBUG_PRINT
		OutputDebugString(L"msgVideoV 2\r\n");
#endif
		if (!m_hSharedFoundFace)
		{
			m_hSharedFoundFace = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedFoundFace");
			if (!m_hSharedFoundFace)
				m_hSharedFoundFace = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(sizeof(int) + sizeof(RECT) * 100), L"SharedFoundFace");
		}

		if (!m_hShareImageReady)
		{
			m_hShareImageReady = OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedReady");
			if (!m_hShareImageReady)
				m_hShareImageReady = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 1, L"SharedReady");
		}

		if (!m_hSharedStrideY)
		{
			m_hSharedStrideY = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedStrideY");
			if (!m_hSharedStrideY)
				m_hSharedStrideY = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedStrideY");
		}

		if (!m_hSharedStrideUV)
		{
			m_hSharedStrideUV = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedStrideUV");
			if (!m_hSharedStrideUV)
				m_hSharedStrideUV = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedStrideUV");
		}

		if (!m_hSharedWidth)
		{
			m_hSharedWidth = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedWidth");
			if (!m_hSharedWidth)
				m_hSharedWidth = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedWidth");
		}

		if (!m_hSharedHeight)
		{
			m_hSharedHeight = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedHeight");
			if (!m_hSharedHeight)
				m_hSharedHeight = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)sizeof(size_t), L"SharedHeight");
		}

		if (!m_hSharedVideoY)
		{
			m_hSharedVideoY = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoY");
			if (!m_hSharedVideoY)
				m_hSharedVideoY = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideY * m_nHeight), L"SharedVideoY");
		}

		if (!m_hSharedVideoU)
		{
			m_hSharedVideoU = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoU");
			if (!m_hSharedVideoU)
				m_hSharedVideoU = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideUV * m_nHeight), L"SharedVideoU");
		}

		if (!m_hSharedVideoV)
		{
			m_hSharedVideoV = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"SharedVideoV");
			if (!m_hSharedVideoV)
				m_hSharedVideoV = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)(m_strideUV * m_nHeight), L"SharedVideoV");
		}
#ifdef DEBUG_PRINT
		OutputDebugString(L"msgVideoV 3\r\n");
#endif
		//OutputDebugString(L"msgVideoV 1\r\n");
		{
			// 안면 인식 결과를 가져옴.
			{				
				BYTE* pFoundFace = (BYTE*)::MapViewOfFile(m_hSharedFoundFace, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(sizeof(int) + sizeof(RECT) * 100));
				BYTE* pTemp = pFoundFace;
				int iFaceCnt = *pTemp;
				pTemp += sizeof(int);

				{
					if (iFaceCnt > 0)
					{
						static DWORD dwCnt = 0;
						CString strTemp;
						strTemp.Format(L"FaceDetection 2 iFaceCnt : %d, dwCnt : %d\r\n", iFaceCnt, dwCnt++);
						OutputDebugString(strTemp.GetBuffer(0));
					}
				}

				//OutputDebugString(L"msgVideoV 2\r\n");
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

						OutputDebugStringIV(L"%d %d %d %d\r\n", rtFace.left, rtFace.top, rtFace.right, rtFace.bottom);
					}
					//OutputDebugString(L"msgVideoV 3\r\n");
				}
				else
				{
					static int iCnt = 0;
					if (iCnt++ > 5)
					{
						iCnt = 0;
						m_pIDisp->RectReset();
					}
				}
				*(int*)pFoundFace = 0;
				UnmapViewOfFile(pFoundFace);
				//OutputDebugString(L"msgVideoV 4\r\n");
			}			

			//OutputDebugString(L"msgVideoV 5\r\n");
			//if (!bReady)
			{
				//////////////////////////////////////////////////////////
				// YUV420에 필요한 이미지 데이터들을 공유메모리에 써 넣음.
				//////////////////////////////////////////////////////////

				size_t* pStrideY = (size_t*)::MapViewOfFile(m_hSharedStrideY, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
				if (!pStrideY)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				*pStrideY = m_strideY;
				UnmapViewOfFile(pStrideY);
				//OutputDebugString(L"msgVideoV 6\r\n");				
				size_t* pStrideUV = (size_t*)::MapViewOfFile(m_hSharedStrideUV, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
				if (!pStrideUV)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				*pStrideUV = m_strideUV;
				UnmapViewOfFile(pStrideUV);
				//OutputDebugString(L"msgVideoV 7\r\n");				
				size_t* pWidth = (size_t*)::MapViewOfFile(m_hSharedWidth, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
				if (!pWidth)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				*pWidth = m_nWidth;
				UnmapViewOfFile(pWidth);
				//OutputDebugString(L"msgVideoV 8\r\n");				
				size_t* pHeight = (size_t*)::MapViewOfFile(m_hSharedHeight, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)sizeof(size_t));
				if (!pHeight)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				*pHeight = m_nHeight;
				UnmapViewOfFile(pHeight);
				//OutputDebugString(L"msgVideoV 9\r\n");				
				BYTE* pY = (BYTE*)::MapViewOfFile(m_hSharedVideoY, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideY * m_nHeight));
				if (!pY)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				//CopyMemory(pY, m_pIY->GetBuffer(), m_pIY->GetBufferSizeUsed());
				m_pIIU->CopyImage(pY, m_strideY, m_pIY->GetBuffer(), m_strideY, m_nWidth, m_nHeight, 1);
				UnmapViewOfFile(pY);
				//OutputDebugString(L"msgVideoV 10\r\n");				
				BYTE* pU = (BYTE*)::MapViewOfFile(m_hSharedVideoU, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideUV * m_nHeight));
				if (!pU)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				CopyMemory(pU, m_pIU->GetBuffer(), m_pIU->GetBufferSizeUsed());
				UnmapViewOfFile(pU);
				//OutputDebugString(L"msgVideoV 11\r\n");				
				BYTE* pV = (BYTE*)::MapViewOfFile(m_hSharedVideoV, FILE_MAP_ALL_ACCESS, 0, 0, (DWORD)(m_strideUV * m_nHeight));
				if (!pV)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				CopyMemory(pV, m_pIV->GetBuffer(), m_pIV->GetBufferSizeUsed());
				UnmapViewOfFile(pV);
				//OutputDebugString(L"msgVideoV 12\r\n");				
				BYTE* pReady = (BYTE*)::MapViewOfFile(m_hShareImageReady, FILE_MAP_ALL_ACCESS, 0, 0, 1);
				if (!pReady)
				{
					//m_pISync->LeaveMutex();
					//break;
					goto CLEANUP;
				}
				*pReady = 1;
				UnmapViewOfFile(pReady);
				//OutputDebugString(L"msgVideoV 13\r\n");
			}
			/*else
				Sleep(100);*/
		}
		//m_pISync->LeaveMutex();

#ifdef DEBUG_PRINT
		OutputDebugString(L"msgVideoV 4\r\n");
#endif

	CLEANUP:
		IV_RELEASE(m_pIY);
		IV_RELEASE(m_pIU);
		IV_RELEASE(m_pIV);
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