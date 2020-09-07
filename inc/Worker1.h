// Worker.h: interface for the CWorker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_)
#define AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_WORKER_WAIT_OBEJCTS					255
#define MSG_BASE								WM_USER+1

class IWorker
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual BOOL SetMSG(MSG msg) = 0;
	virtual BOOL SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL) = 0;
	virtual void StartWork(DWORD dwWaitTime = INFINITE) = 0;
	virtual void StopWork(DWORD dwWaitTime = INFINITE) = 0;
	virtual int AddWaitHandle(HANDLE hWaitObject) = 0;
	virtual void WakeJob() = 0;
	virtual void SetEndHandle(HANDLE hEnd) = 0;
	virtual long GetRefCnt() = 0;
};

class CWorker : public IWorker
{
public:
	CWorker();
protected:
	virtual ~CWorker();

public:
	virtual void AddRef();
	virtual void Release();
	virtual BOOL SetMSG(MSG msg);
	virtual BOOL SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL);
	virtual int AddWaitHandle(HANDLE hWaitObject);
	virtual void WakeJob();
	virtual void SetEndHandle(HANDLE hEnd);
	virtual long GetRefCnt();

protected:
	virtual void StartWork(DWORD dwWaitTime = INFINITE);
	virtual void StopWork(DWORD dwWaitTime = INFINITE);

protected:
	//friend void _TrdFunc(void* pParam);
	friend unsigned int WINAPI _TrdFunc(LPVOID pParam);

protected:
	unsigned long m_ulTrdID;
	HANDLE m_hTrd;
	HANDLE m_hJob;
	long m_lRefCnt;
	DWORD m_dwWaitTime;
	DWORD m_dwWaitCnt;
	HANDLE m_arhWaitObjects[MAX_WORKER_WAIT_OBEJCTS];
	BOOL m_bStart;

protected:
	virtual void DoJob() = 0;
	virtual void DoMsgProc(MSG msg) = 0;
	virtual void OnStartThread();
	virtual void OnStopThread();

protected:
	virtual void DoAdditionalJob(int iJob);

protected:
	int SetTimer(DWORD dwInterval);
	void KillTimer(int iTimer);

protected:
	HANDLE m_hEnd;
};

#endif // !defined(AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_)
