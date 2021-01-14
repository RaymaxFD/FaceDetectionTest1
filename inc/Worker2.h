// Worker2.h: interface for the CWorker2 class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//using namespace std;
#include <deque>

#define MAX_WORKER_WAIT_OBEJCTS					255
#define MSG_BASE								WM_USER+1

class IWorker2
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual bool SetMSG(MSG msg, void* pMsg = NULL) = 0;
	virtual bool SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL, void* pMsg = NULL) = 0;
	virtual void StartWork(DWORD dwWaitTime = INFINITE) = 0;
	virtual void StopWork(DWORD dwWaitTime = INFINITE) = 0;
	virtual int AddWaitHandle(HANDLE hWaitObject) = 0;
	virtual void WakeJob() = 0;
	virtual void SetEndHandle(HANDLE hEnd) = 0;
	virtual long GetRefCnt() = 0;
};

class CWorker2 : public IWorker2
{
public:
	CWorker2();
protected:
	virtual ~CWorker2();

protected:
	struct _stMsg
	{
		MSG msg;
		void *pParam;
	};
private:
	std::deque<_stMsg> m_deqMsg;
	CRITICAL_SECTION m_csMsg;

protected:
	virtual void AddRef();
	virtual void Release();
	virtual bool SetMSG(MSG msg, void* pParam = NULL);
	virtual bool SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL, void* pParam = NULL);
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
	HANDLE m_hMsg;
	long m_lRefCnt;
	DWORD m_dwWaitTime;
	DWORD m_dwWaitCnt;
	HANDLE m_arhWaitObjects[MAX_WORKER_WAIT_OBEJCTS];
	bool m_bStart;

protected:
	void MsgProc();
protected:
	virtual void DoJob() = 0;
	virtual void DoMsgProc(MSG msg, void* pParam) = 0;
	virtual void OnStartThread();
	virtual void OnStopThread();

protected:
	virtual void DoAdditionalJob(DWORD dwJob);

protected:
	int SetTimer(DWORD dwInterval);
	void KillTimer(int iTimer);

protected:
	HANDLE m_hEnd;
};

