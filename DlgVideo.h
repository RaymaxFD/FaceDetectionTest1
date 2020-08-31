#pragma once


// CDlgVideo 대화 상자

#include <Component/RTSP/IRTSPClient.h>
#include <Component/DeEncoder/IDecVideo.h>
#include <StdIV.h>

class CWkFaceDetection_V2;
class CDlgVideo4Debug;

class CDlgVideo : public CDialogEx, public CStdIV
{
private:
	CDlgVideo4Debug* m_pDlg4Debug = nullptr;

private:
	HINSTANCE m_hInstRTSP = NULL;
	IRTSPClient_V1* m_pICamera = nullptr;
	IBufferPool* m_pIPool4Cam = nullptr;

private:
	HINSTANCE m_hInstDec = NULL;
	IDecVideo_V1* m_pIDec = nullptr;
	IBufferPool* m_pIPool4Dec0 = nullptr, *m_pIPool4Dec1 = nullptr;

private:
	IDisplay2* m_pIDisp = nullptr;

private:
	IBufferPool* m_pIPool4FD = nullptr;
	CWkFaceDetection_V2* m_pFD = nullptr;

private:
	DECLARE_DYNAMIC(CDlgVideo)

public:
	CDlgVideo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgVideo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIDEO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
