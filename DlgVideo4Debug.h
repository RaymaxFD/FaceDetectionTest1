#pragma once

#include <StdIV.h>

// CDlgVideo4Debug 대화 상자

class CDlgVideo4Debug : public CDialogEx, public CStdIV
{
public:
	IMedia* GetIMedia();
private:
	IDisplay2* m_pIDisp = nullptr;

private:
	DECLARE_DYNAMIC(CDlgVideo4Debug)

public:
	CDlgVideo4Debug(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgVideo4Debug();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIDEO4DEBUG };
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
