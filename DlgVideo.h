#pragma once


// CDlgVideo 대화 상자

#include <Component/RTSP/IRTSPClient.h> // RTSP 접속을 수행하기 위한 인터페이스 정의
#include <Component/DeEncoder/IDecVideo.h> // FFMPEG으로 비디오 디코딩을 위한 인터페이스 정의
#include <StdIV.h> // STDIV.dll 안에 있는 인터페이스들을 편하게 갖다 쓰기 위해 만든 helper class 정의

class CDlgVideo4Debug;

// IEvtFaceDetection_V2 -> 안면 식별 결과가 통보됨
// IEvtLicense -> 라이센스 확인 결과가 통보됨.
class CDlgVideo : public CDialogEx, public CStdIV, public IMedia
{
#ifdef DEBUG_VIDEO
private:
	CDlgVideo4Debug* m_pDlg4Debug = nullptr;
#endif

	// RTSP를 통하여 카메라 접속을 위해
private:
	HINSTANCE m_hInstRTSP = NULL;
	IRTSPClient_V1* m_pICamera = nullptr;
	IBufferPool* m_pIPool4Cam = nullptr;

	// FFMPEG을 이용한 비디오 디코딩을 위해
private:
	HINSTANCE m_hInstDec = NULL;
	IDecVideo_V1* m_pIDec = nullptr;
	IBufferPool* m_pIPool4Dec0 = nullptr, *m_pIPool4Dec1 = nullptr;

	// 화면에 출력하기 위해
private:
	IDisplay2* m_pIDisp = nullptr;

private:
	ISyncMutex* m_pISync = nullptr;
	HANDLE m_hSharedFoundFace = NULL;
	HANDLE m_hSharedStrideY = NULL;
	HANDLE m_hSharedStrideUV = NULL;
	HANDLE m_hSharedWidth = NULL;
	HANDLE m_hSharedHeight = NULL;
	HANDLE m_hSharedVideoY = NULL;
	HANDLE m_hSharedVideoU = NULL;
	HANDLE m_hSharedVideoV = NULL;
	HANDLE m_hShareImageReady = NULL;
private:
	IBuffer* m_pIY = nullptr;
	IBuffer* m_pIU = nullptr;
	IBuffer* m_pIV = nullptr;
	size_t m_strideY = 0;
	size_t m_strideUV = 0;
	size_t m_nWidth = 0;
	size_t m_nHeight = 0;
protected:
	virtual void NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV = eYUV420) override;

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
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
