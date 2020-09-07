// Worker3.h: interface for the CWorker3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_)
#define AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable : 4251)
#pragma warning(disable : 4786)

#include <IBase.h>

#include <deque>
#include <map>
using namespace std;

#define MAX_WORKER_WAIT_OBEJCTS					255
#define MSG_ADD_HANDLE                          (WM_USER)
#define MSG_REMOVE_HANDLE                       (WM_USER+1)
#define MSG_BASE								(WM_USER+2)
#define WAIT_BASE                               (WAIT_OBJECT_0 + 2)

class IWorker3
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual bool SetMSG(MSG msg, void* pMsg = NULL) = 0;
	virtual bool SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL, void* pMsg = NULL) = 0;
	virtual void StartWork(IBase* pIParent = NULL, DWORD dwWaitTime = INFINITE, TCHAR* pStrName = (TCHAR*)L"No Name") = 0;
	virtual void StopWork(DWORD dwWaitTime = INFINITE) = 0;
	virtual bool AddWaitHandle(DWORD dwID, HANDLE hWaitObject) = 0;
	virtual void RemoveWaitHandle(DWORD dwID) = 0;
	virtual void WakeJob() = 0;
	virtual void SetEndHandle(HANDLE hEnd) = 0;
	virtual long GetRefCnt() = 0;
};

#ifdef WORKER3_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API CWorker3 : public IWorker3
{
public:
	CWorker3();
protected:
	virtual ~CWorker3();

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
	virtual void AddRef() override;
	virtual void Release() override;
	virtual bool SetMSG(MSG msg, void* pParam = NULL) override;
	virtual bool SetMSG(UINT message, WPARAM wParam = NULL, LPARAM lParam = NULL, void* pParam = NULL) override;
	virtual bool AddWaitHandle(DWORD dwID, HANDLE hWaitObject) override;
	virtual void RemoveWaitHandle(DWORD dwID) override;
	virtual void WakeJob() override;
	virtual void SetEndHandle(HANDLE hEnd) override;
	virtual long GetRefCnt() override;

private:
	IBase* m_pIBase;
	TCHAR m_strName[MAX_PATH];
protected:
	virtual void StartWork(IBase* pIParent = NULL, DWORD dwWaitTime = INFINITE, TCHAR* pStrName = (TCHAR*)L"No Name") override;
	virtual void StopWork(DWORD dwWaitTime = INFINITE) override;

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
	virtual void DoJob() = 0;
	virtual void DoMsgProc(MSG msg, void* pParam) = 0;
	virtual void OnStartThread();
	virtual void OnStopThread();

protected:
	virtual void DoAdditionalJob(DWORD dwJob);

protected:
	int SetTimer(DWORD dwID, DWORD dwInterval);
	void KillTimer(DWORD dwID);

protected:
	HANDLE m_hEnd;

protected:
	bool IsRunning();
	int GetMsgCnt();
	bool IsConti();
};

#endif // !defined(AFX_WORKER_H__7EE72924_4717_47A6_AC23_4E22BEE1F5FC__INCLUDED_)