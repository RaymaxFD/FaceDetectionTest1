#pragma once


#include <IBase.h>

#include <deque>
#include <map>
using namespace std;

#define MAX_WORKER_WAIT_OBEJCTS					255
#define MSG_ADD_HANDLE                          (WM_USER)
#define MSG_REMOVE_HANDLE                       (WM_USER+1)
#define MSG_BASE								(WM_USER+2)
#define WAIT_BASE                               (WAIT_OBJECT_0 + 2)

#pragma warning(disable:4251)

#ifdef WORKER_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API CWorker
{
public:
	CWorker();
protected:
	virtual ~CWorker();

protected:
	struct DLL_API _stMsg
	{
		MSG msg;
		void *pParam;
	};
private:
	deque<_stMsg> m_deqMsg;
	CRITICAL_SECTION m_csMsg;

protected:
	virtual void AddRef();
	virtual void Release();
	virtual bool SetMSG(MSG msg, void* pParam = NULL);
	virtual bool SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL, void* pParam = NULL);
	virtual bool AddWaitHandle(DWORD dwID, HANDLE hWaitObject);
	virtual void RemoveWaitHandle(DWORD dwID);
	virtual void WakeJob();
	virtual void SetEndHandle(HANDLE hEnd);
	virtual long GetRefCnt();

private:
	IBase* m_pIBase = nullptr;
	TCHAR m_strName[MAX_PATH];
protected:
	virtual void StartWork(IBase* pIParent = NULL, DWORD dwWaitTime = INFINITE, TCHAR* pStrName = (TCHAR*)L"No Name");
	virtual void StopWork(DWORD dwWaitTime = INFINITE);

protected:
	friend unsigned int WINAPI _TrdFunc2(LPVOID pParam);

protected:
	unsigned long m_ulTrdID;
	HANDLE m_hTrd;
	HANDLE m_hJob;
	HANDLE m_hMsg;
	long m_lRefCnt;
	DWORD m_dwWaitTime;
	map<DWORD, HANDLE> m_mapWaitObjects;
	bool m_bRunning;

protected:
	void MsgProc();
protected:
	virtual void DoJob();
	virtual void DoMsgProc(MSG msg, void* pParam);
	virtual void DoMsgProc(UINT message, WPARAM wParam, LPARAM lParam, void* pParam);
	virtual void OnStartThread();
	virtual void OnStopThread();

protected:
	virtual void DoAdditionalJob(DWORD dwJob);

protected:
	bool TimerAdd(DWORD dwID, DWORD dwInterval);
	void TimerRemove(DWORD dwID);

protected:
	HANDLE m_hEnd;

protected:
	bool IsRunning();
	int GetMsgCnt();
	bool IsConti();
};