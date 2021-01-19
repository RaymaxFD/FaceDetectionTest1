// ClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "FaceDetectionTest1.h"
#include "ClientSocket.h"
#include "ListenSocket.h"

#define BUFF_LEN 1024 * 100
// CClientSocket

CClientSocket::CClientSocket()
{
	mBuffer = new char[BUFF_LEN];
}

CClientSocket::~CClientSocket()
{
	delete[] mBuffer;
}


// CClientSocket 멤버 함수


// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}
// CClientSocket 멤버 함수


void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}

void CClientSocket::OnReceive(int nErrorCode)
{
	nRecv += Receive(mBuffer + nRecv, BUFF_LEN - nRecv);
	if (nRecv < 9)
	{
		OutputDebugStringYM(L"%d < 8\r\n", nRecv);
		goto _RECV_END;
	}
	char* pStart = strstr(mBuffer, "STRT,");
	if (pStart)
	{
		char* pLen = pStart + strlen("STRT,");
		int nLen = *(int*)pLen;
		int nSizeLen = (int)(sizeof(int) + strlen(","));
		int nRectLen = (int)(sizeof(RECT) + strlen(",") * 4);
		int nPacketLen = (int)(strlen("STRT,") + nSizeLen + nLen * nRectLen);
		if (nRecv < nPacketLen)
		{
			//OutputDebugStringYM(L"%d < %d\r\n", nRecv, nPacketLen)
			goto _RECV_END;
		}

		mVecRect.clear();
		//OutputDebugStringYM(L"msgNewFaceNew\r\n");
		AfxGetMainWnd()->PostMessage(msgNewFaceNew);
		char* pRect = pLen + sizeof(int) + strlen(",");
		int i = 0;
		for (i = 0; i < nLen; i++)
		{
			RECT rect;
			rect.left = *(int*)pRect;
			pRect += sizeof(int) + strlen(",");
			rect.top = *(int*)pRect;
			pRect += sizeof(int) + strlen(",");
			rect.right = *(int*)pRect;
			pRect += sizeof(int) + strlen(",");
			rect.bottom = *(int*)pRect;
			pRect += sizeof(int) + strlen(",");

			mVecRect.push_back(rect);
			AfxGetMainWnd()->PostMessage(msgNewFaceLT, (WPARAM)rect.left, (LPARAM)rect.top);
			AfxGetMainWnd()->PostMessage(msgNewFaceRB, (WPARAM)rect.right, (LPARAM)rect.bottom);
			//OutputDebugStringIV(L"rect.left : %d, rect.top : %d, rect.right : %d, rect.bottom : %d\r\n", rect.left, rect.top, rect.right, rect.bottom);
		}
		
		//OutputDebugStringYM(L"%d - %d = %d", nRecv, nPacketLen, nRecv - nPacketLen);
		nRecv -= nPacketLen;
	}
	else
	{
		nRecv = 0;
	}
	//CString strTmp = _T(""), strIPAddress = _T("");
	//UINT uPortNumber = 0;
	//TCHAR strBuffer[1024];
	//::ZeroMemory(strBuffer, sizeof(strBuffer)); // :: 붙이고 안붙이고 차이 알아보기

	//GetPeerName(strIPAddress, uPortNumber);
	//if (Receive(strBuffer, sizeof(strBuffer)) > 0) { // 전달된 데이터(문자열)가 있을 경우
	//	CSocketServerDlg* pMain = (CSocketServerDlg*)AfxGetMainWnd();
	//	strTmp.Format(_T("[%s:%d]: %s"), strIPAddress, uPortNumber, strBuffer);
	//	pMain->m_List.AddString(strTmp);  // 메시지 리스트(메시지창?)에 입력받은 메시지 띄우기
	//	pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);

	//	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	//	pServerSocket->SendAllMessage(strBuffer); // 다른 클라이언트들에게 메시지 전달
	//}

_RECV_END:
	CSocket::OnReceive(nErrorCode);
}
