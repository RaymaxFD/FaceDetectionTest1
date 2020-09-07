#pragma once

#include <Windows.h>
#include <tchar.h>
#include <assert.h>

#define DECLARE_WORKER1 \
		virtual void AddRef(); \
		virtual void Release(); \
		virtual long GetRefCnt(); \
		virtual void StartWork(DWORD dwWaitTime = INFINITE); \
		virtual void StopWork(DWORD dwWaitTime = INFINITE);
#define DECLARE_WORKER2 DECLARE_WORKER1

#define DECLARE_WORKER \
		virtual void AddRef(); \
		virtual void Release(); \
		virtual long GetRefCnt(); \
		virtual void StartWork(IBase* pIBase = NULL, DWORD dwWaitTime = INFINITE); \
		virtual void StopWork(DWORD dwWaitTime = INFINITE);
#define DECLARE_WORKER3	DECLARE_WORKER

#define IMPLEMENT_WORKER1(class_name) \
	void class_name::AddRef() \
	{ \
		CWorker::AddRef(); \
	} \
	void class_name::Release() \
	{ \
		CWorker::Release(); \
	} \
	long class_name::GetRefCnt() \
	{ \
		return CWorker::GetRefCnt(); \
	} \
	void class_name::StartWork(DWORD dwWaitTime) \
	{ \
		CWorker::StartWork(dwWaitTime); \
	} \
	void class_name::StopWork(DWORD dwWaitTime) \
	{ \
		CWorker::StopWork(dwWaitTime); \
	} 
#define IMPLEMENT_WORKER2(class_name) \
	void class_name::AddRef() \
	{ \
	CWorker2::AddRef(); \
	} \
	void class_name::Release() \
	{ \
	CWorker2::Release(); \
	} \
	long class_name::GetRefCnt() \
	{ \
	return CWorker2::GetRefCnt(); \
	} \
	void class_name::StartWork(DWORD dwWaitTime) \
	{ \
	CWorker2::StartWork(dwWaitTime); \
	} \
	void class_name::StopWork(DWORD dwWaitTime) \
	{ \
	CWorker2::StopWork(dwWaitTime); \
	}
#define IMPLEMENT_WORKER3(class_name) \
	void class_name::AddRef() \
	{ \
	CWorker3::AddRef(); \
	} \
	void class_name::Release() \
	{ \
	CWorker3::Release(); \
	} \
	long class_name::GetRefCnt() \
	{ \
	return CWorker3::GetRefCnt(); \
	} \
	void class_name::StartWork(IBase* pIBase, DWORD dwWaitTime) \
	{ \
	CWorker3::StartWork(pIBase, dwWaitTime); \
	} \
	void class_name::StopWork(DWORD dwWaitTime) \
	{ \
	CWorker3::StopWork(dwWaitTime); \
	}
#define IMPLEMENT_WORKER(class_name) \
	void class_name::AddRef() \
		{ \
	CWorker::AddRef(); \
		} \
	void class_name::Release() \
		{ \
	CWorker::Release(); \
		} \
	long class_name::GetRefCnt() \
		{ \
	return CWorker::GetRefCnt(); \
		} \
	void class_name::StartWork(IBase* pIBase, DWORD dwWaitTime) \
		{ \
	CWorker::StartWork(pIBase, dwWaitTime); \
		} \
	void class_name::StopWork(DWORD dwWaitTime) \
		{ \
	CWorker::StopWork(dwWaitTime); \
		}

#define DOMSGPROC \
	UINT message = msg.message; \
	WPARAM wParam = msg.wParam; \
	LPARAM lParam = msg.lParam;

// ex : GetSetImpl(bool, Test, m_bTest);
#define GetSetImpl(type, fname, var) \
	type Get##fname() \
	{ \
	return var; \
	} \
	void Set##fname(type tmp) \
	{ \
	var = tmp; \
	} \
	__declspec(property(get = Get##fname, put = Set##fname)) type fname;


#define DECLARE_RESIZE \
	private: \
		CRect m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3; \
	protected: \
		struct _stCtl \
		{ \
			UINT uiID; \
			float fLeft; \
			float fTop; \
			float fRight; \
			float fBottom; \
			HFONT font; \
		}; \
	private: \
		vector<_stCtl> m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0; \
	protected: \
		void AddControl(UINT uiCtl);

#define IMPLEMENT_RESIZE(class_name) \
	void class_name::AddControl(UINT uiCtl) \
	{ \
		_stCtl st; \
		CRect rt; \
 \
		GetDlgItem(uiCtl)->GetWindowRect(&rt); \
		ScreenToClient(&rt); \
		st.uiID = uiCtl; \
		st.fLeft = rt.left / float(m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.Width()); \
		st.fTop = rt.top / float(m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.Height()); \
		st.fRight = rt.right / float(m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.Width()); \
		st.fBottom = rt.bottom / float(m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.Height()); \
 \
		m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0.push_back(st); \
	}

#define PREPARE_RESIZE \
	m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.SetRectEmpty(); \
	m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0.clear();


#define BEGIN_RESIZE \
	if (m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3.IsRectEmpty()) \
		GetClientRect(&m_rt1FB87291_0948_4C3E_B343_1825D2E92FB3); \
	if (!m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0.size()) \
	{

#define ADD_CONTROL(id) \
	if (GetDlgItem(id)) \
		AddControl(id); \
		else \
		return;

#define END_RESIZE }

#define BEGIN_FONT_SIZE \
	CRect rtClient; \
	GetClientRect(&rtClient); \
	vector<_stCtl>::iterator iter; \
	for (iter = m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0.begin(); iter != m_rt435D44D2_9667_4CB5_9ED6_B55ECB6238B0.end(); iter++) \
	{ \
		int iLeft = int(iter->fLeft * float(rtClient.Width())); \
		int iTop = int(iter->fTop * float(rtClient.Height())); \
		int iRight = int(iter->fRight * float(rtClient.Width())); \
		int iBottom = int(iter->fBottom * float(rtClient.Height())); \
		int iFontHeight = 0; \
		switch (iter->uiID) \
		{
#define FONT_SIZE(id, height) \
	case id: \
		iFontHeight = height; \
		break;
#define FONT_NO_SIZE(id) \
	case id: \
		GetDlgItem(iter->uiID)->MoveWindow(iLeft, iTop, iRight - iLeft, iBottom - iTop); \
		continue; \
		break;
#define END_FONT_SIZE \
		default: \
			iFontHeight = iBottom - iTop; \
			break; \
		} \
		DeleteObject(iter->font); \
		iter->font = CreateFont(iFontHeight,0,0,0,700,FALSE,FALSE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS, \
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,_T("Arial")); \
		GetDlgItem(iter->uiID)->SetFont(CFont::FromHandle(iter->font)); \
		GetDlgItem(iter->uiID)->MoveWindow(iLeft, iTop, iRight - iLeft, iBottom - iTop); \
	}

#define CLIP(_min, _max, _val) (((_val) < _min) ? _min : (((_val) > _max) ? _max : (_val)))
#define RGBA(r,g,b,a)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16))|(((DWORD)(BYTE)(a))<<24))
#define GetColor3R(rgb)    ((BYTE)(rgb))
#define GetColor3G(rgb)    ((BYTE)(((WORD)(rgb)) >> 8))
#define GetColor3B(rgb)    ((BYTE)((rgb) >> 16))

#define PixelGray(pImg,x,y,width) (*(pImg + (y) * width + x))
#define PixelColor3(pImg,x,y,width) (*(pImg + (y) * width * 3 + (x) * 3))
#define PixelColor3R(pImg,x,y,width) (*(pImg + (y) * width * 3 + (x) * 3 + 2))
#define PixelColor3G(pImg,x,y,width) (*(pImg + (y) * width * 3 + (x) * 3 + 1))
#define PixelColor3B(pImg,x,y,width) (*(pImg + (y) * width * 3 + (x) * 3 + 0))

#define GetRectWidth(rt) (rt.right - rt.left)
#define GetRectHeight(rt) (rt.bottom - rt.top)
#define GetRectCenterX(rt) ((rt.right - rt.left) / 2 + rt.left)
#define GetRectCenterY(rt) ((rt.bottom - rt.top) / 2 + rt.top)

#define ToInt(x) \
	_tstoi(x)

#define ULONGLONG_TO_LOW_UINT(large)		((unsigned int) ((large) & 0x00000000FFFFFFFFULL))		
#define ULONGLONG_TO_HIGH_UINT(large)		((unsigned int) (((large) >> 32) & 0x00000000FFFFFFFFULL))
#define INT_TO_LONGLONG(high, low)            ((high) ? ((((long long) (high)) << 32) | (unsigned int)(low)) : (low))



#define IV_STOPWORK(x)				if (x) \
	{ \
											assert(x); \
											x->StopWork(); \
											x = NULL; \
											}

#define IV_RELEASE(x)				if (x) \
	{ \
											assert(x); \
											if (x->GetRefCnt() > 0) \
												x->Release(); \
											x = NULL; \
											}

#define IV_DELETE(x)				if (x) \
	{ \
											assert(x); \
											delete [] x; \
											x = NULL; \
											}



#include <map>
#include <vector>
#include <string>
using namespace std;

typedef basic_string<TCHAR>   tstring;

inline tstring format_arg_list(const TCHAR *fmt, va_list args)
{
	if (!fmt) return _T("");
	int   result = -1, length = 256;
	TCHAR *buffer = 0;
	while (result == -1)
	{
		if (buffer) delete[] buffer;
		buffer = new TCHAR[length + 1];
		//memset(buffer, 0, length + 1);
		buffer[0] = _T('\0');
		result = _vsntprintf_s(buffer, length, _TRUNCATE, fmt, args);
		length *= 2;
	}
	tstring s(buffer);
	delete[] buffer;
	return s;
}

inline tstring format(const TCHAR *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	tstring s = format_arg_list(fmt, args);
	va_end(args);
	return s;
}


#define WIDTHBYTESIV(bits) (((bits) + 31) / 32 * 4)
#define ALIGN32(x) (((x) + 31) & ~(31))


#define ARRAY_LEN(x) sizeof(x) / sizeof(x[0])

#ifdef _DEBUG
/*#define ASSERT(x)       {if(!(x)) _asm{int 0x03}}
#define VERIFY(x)       {if(!(x)) _asm{int 0x03}}*/
#ifndef ASSERT
#define ASSERT(x)       {assert(x);}
#endif
#ifndef VERIFY
#define VERIFY(x)       {assert(x);}
#endif
#else
#ifndef ASSERT
#define ASSERT(x)
#endif
#ifndef VERIFY
#define VERIFY(x)       x
#endif
#endif

// ������ ���� �ƴ�, ������ �ּҸ� �䱸�ϴ� �Լ���
template<typename T>
void SWAP(T* a, T* b) { // ������ ��ǥ��, ������ ������� ��
	T temp = *a; // a�� ����Ű�� ���� ��(300)�� temp�� ����
	*a = *b; // *a � ���� ��ǥ��, ������ ������ ����Ű�� ���� �ǹ���
	*b = temp;
}



#ifndef PI
#define PI 3.14159265358979323846
#endif
#define D2R(d)	(double(PI)/180.0*double(d))
#define R2D(r)	double((180.0/double(PI)*double(r)))


#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef ABS
#define ABS(x) ((x)<0 ? -(x) : (x))
#endif


#ifdef _WIN64
#define IMPLEMENT_IBASE         HINSTANCE hF883505A_E75D_4A09_A163_E5AD1636CD15 = LoadLibrary(_T("IBaseReg64.dll")); \
								_ASSERTE(hF883505A_E75D_4A09_A163_E5AD1636CD15); \
								typedef HINSTANCE (*pOpenIBaseDll)(TCHAR*); \
								typedef IBase* (*pGetIBaseInterface)(HINSTANCE, GUID); \
								typedef void (*pCloseIBaseDll)(HINSTANCE); \
								pOpenIBaseDll OpenIBaseDll; \
								pGetIBaseInterface GetIBaseInterface; \
								pCloseIBaseDll CloseIBaseDll; \
								OpenIBaseDll = (HINSTANCE (*)(TCHAR*))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "OpenIBaseDll"); \
								GetIBaseInterface = (IBase* (*)(HINSTANCE, GUID))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "GetIBaseInterface"); \
								CloseIBaseDll = (void (*)(HINSTANCE))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "CloseIBaseDll");
#else
#define IMPLEMENT_IBASE         HINSTANCE hF883505A_E75D_4A09_A163_E5AD1636CD15 = LoadLibrary(_T("IBaseReg.dll")); \
								_ASSERTE(hF883505A_E75D_4A09_A163_E5AD1636CD15); \
								typedef HINSTANCE (*pOpenIBaseDll)(TCHAR*); \
								typedef IBase* (*pGetIBaseInterface)(HINSTANCE, GUID); \
								typedef void (*pCloseIBaseDll)(HINSTANCE); \
								pOpenIBaseDll OpenIBaseDll; \
								pGetIBaseInterface GetIBaseInterface; \
								pCloseIBaseDll CloseIBaseDll; \
								OpenIBaseDll = (HINSTANCE (*)(TCHAR*))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "OpenIBaseDll"); \
								GetIBaseInterface = (IBase* (*)(HINSTANCE, GUID))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "GetIBaseInterface"); \
								CloseIBaseDll = (void (*)(HINSTANCE))GetProcAddress(hF883505A_E75D_4A09_A163_E5AD1636CD15, "CloseIBaseDll");
#endif


#define IV_GET_IF(hInst, ID_DLL, ID_IF, TYPE, result) \
                                { \
								    if (!hInst) \
										hInst = OpenIBaseDll((TCHAR*)ID_DLL); \
                                    result = (TYPE*)GetIBaseInterface(hInst, ID_IF); \
                                }

// Error Check Macro
#define ERROR_CHECK( ret )                                        \
    if( FAILED( ret ) ){                                          \
        std::stringstream ss;                                     \
        ss << "failed " #ret " " << std::hex << ret << std::endl; \
        throw std::runtime_error( ss.str().c_str() );             \
	    }

#define DECLARE_GETDOC_DOC(classname)                             \
	public:                                                       \
		static classname* GetDoc();

#define IMPLEMENT_GETDOC_DOC(projectname)                         \
	projectname##Doc* projectname##Doc::GetDoc()                  \
	{                                                             \
		projectname##App* pApp = (projectname##App*)AfxGetApp();  \
		return (projectname##Doc*)pApp->GetDoc();                 \
	}
		
#define DECLARE_GETDOC_APP                                        \
	private:													  \
		CDocument* m_pE709B14E_9779_4FB0_8FF2_61CDFF03E529;		  \
																  \
	public:														  \
		void SetDoc(CDocument* pDoc);							  \
		CDocument* GetDoc();                                      \
	

#define IMPLEMENT_GETDOC_APP(classname)                           \
	void classname::SetDoc(CDocument* pDoc)						  \
	{															  \
		m_pE709B14E_9779_4FB0_8FF2_61CDFF03E529 = pDoc;			  \
	}															  \
																  \
	CDocument* classname::GetDoc()								  \
	{															  \
		return m_pE709B14E_9779_4FB0_8FF2_61CDFF03E529;			  \
	}


template<typename T>
class CNumber
{
public:
	CNumber(T n = 0) : m_nVal(n){}
	CNumber(const CNumber& rhs) : m_nVal(rhs.m_nVal){}
	CNumber& operator=(const CNumber& rhs) {
		m_nVal = rhs.m_nVal;
		return *this;
	}
	CNumber operator+(const CNumber& rhs) {
		CNumber temp;
		temp.m_nVal = m_nVal + rhs.m_nVal;
		return temp;
	}
	CNumber operator-(const CNumber& rhs) {
		CNumber temp;
		temp.m_nVal = m_nVal - rhs.m_nVal;
		return temp;
	}
	CNumber operator*(const CNumber& rhs) {
		CNumber temp;
		temp.m_nVal = m_nVal * rhs.m_nVal;
		return temp;
	}
	CNumber operator/(const CNumber& rhs) {
		CNumber temp;
		temp.m_nVal = m_nVal / rhs.m_nVal;
		return temp;
	}
	CNumber& operator++()
	{
		m_nVal++;
		return *this;
	}
	CNumber operator++(int)
	{
		CNumber temp = *this;
		++*this;
		return temp;
	}
	CNumber& operator--()
	{
		m_nVal--;
		return *this;
	}
	CNumber operator--(int)
	{
		CNumber temp = *this;
		--*this;
		return temp;
	}
	bool operator<(const CNumber& rhs) const
	{
		return (m_nVal < rhs.m_nVal);
	}
	TCHAR* Format(const TCHAR* pStr)
	{
		_stprintf_s(m_strData, _MAX_PATH, pStr, m_nVal);

		return m_strData;
	}
	friend ostream& operator<<(ostream& osIn, const CNumber& rhs);

public:
	T m_nVal;
	TCHAR m_strData[_MAX_PATH];
};

//#pragma warning(disable: 4793)
//inline void OutputDebugStringIV(const TCHAR* pStr, ...)
//{
//	TCHAR strData[_MAX_PATH];
//	va_list marker;
//	va_start(marker, pStr);
//	_vstprintf_s(strData, _MAX_PATH, pStr, marker);
//	va_end(marker);
//	
//	OutputDebugString(strData);
//}

#pragma warning(disable: 4793)
inline void FABCA97D_77B3_405D_8254_7B746E18003B(TCHAR strData[], const TCHAR* pStr, ...)
{
	va_list marker;
	va_start(marker, pStr);
	_vstprintf_s(strData, _MAX_PATH, pStr, marker);
	va_end(marker);	
}

#ifdef _DEBUG
#define OutputDebugStringIV(fmt, ...) \
	{ \
		TCHAR strData[_MAX_PATH]; \
		FABCA97D_77B3_405D_8254_7B746E18003B(strData, fmt, __VA_ARGS__); \
		_RPTFW0(_CRT_WARN, strData); \
	}
#else
#define OutputDebugStringIV(fmt, ...) \
	{ \
		TCHAR strData[_MAX_PATH]; \
		FABCA97D_77B3_405D_8254_7B746E18003B(strData, fmt, __VA_ARGS__); \
		OutputDebugString(strData); \
	}
#endif
        
#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/core/noncopyable.hpp>

// Thread safe circular buffer 
template <typename T>
class CCircularQueue : private boost::noncopyable
{
public:
	typedef boost::mutex::scoped_lock lock;
	CCircularQueue() {}
	CCircularQueue(int n) { cb.set_capacity(n); }
	void EnQueue(T imdata) {
		lock lk(monitor);
		cb.push_back(imdata);
		buffer_not_empty.notify_one();
	}
	bool DeQueue(T& data) {
		lock lk(monitor);
		if (cb.empty())
			return false;
		/*while (cb.empty())
			buffer_not_empty.wait(lk);*/
		data = cb.front();
		cb.pop_front();
		return true;
	}
	void Clear() {
		lock lk(monitor);
		cb.clear();
	}
	int Length() {
		lock lk(monitor);
		return cb.size();
	}
	void Create(int capacity) {
		lock lk(monitor);
		cb.set_capacity(capacity);
	}
private:
	boost::condition buffer_not_empty;
	boost::mutex monitor;
	boost::circular_buffer<T> cb;
};




#if 0
#include <iostream>
using namespace std;
//new�� ���������� ����ϴ� operator new()�� ������ �ؼ� �޸� �Ҵ� ����� �ٲ� �� �ִ�.
inline void* operator new(size_t sz) { //1
	cout << "my operator new: " << sz << endl;
	return malloc(sz);
}
inline void* operator new(size_t sz, char* s, int n) { //2
	cout << "my operator new: " << sz << endl;
	return malloc(sz);
}

inline void operator delete(void* p) {
	cout << "my operator delete" << endl;
	free(p);
}

//#define new new(__FILE__, __LINE__)

//void *operator new[](size_t size, const char *filename, int line)
//{
//	return operator new(size, filename, line);
//}
//
//void operator delete[](void *p)
//{
//	operator delete(p);
//}
#endif


#define _GetActiveApp(CApp) ((CApp*)AfxGetApp())
#define _GetMainFrm()	((CMainFrame*)AfxGetMainWnd())
#define _GetActiveDoc(CDoc)	((CDoc*)_GetMainFrm()->GetActiveDocument())
#define _GetActiveView(CView)	((CView*)_GetMainFrm()->GetActiveView())

struct _st3DPos
{
	double dX;
	double dY;
	double dZ;
};


#define	CLICK_BTN(HWND, ID)			::SendMessage(HWND, WM_COMMAND, MAKEWPARAM(ID, BN_CLICKED), 0L)


//#ifndef GETTIMEOFADAY
//#define GETTIMEOFADAY
//const __int64 DELTA_EPOCH_IN_MICROSECS= 11644473600000000;
//
///* IN UNIX the use of the timezone struct is obsolete;
// I don't know why you use it. See http://linux.about.com/od/commands/l/blcmdl2_gettime.htm
// But if you want to use this structure to know about GMT(UTC) diffrence from your local time
// it will be next: tz_minuteswest is the real diffrence in minutes from GMT(UTC) and a tz_dsttime is a flag
// indicates whether daylight is now in use
//*/
//struct timezone
//{
//  __int32  tz_minuteswest; /* minutes W of Greenwich */
//  bool  tz_dsttime;     /* type of dst correction */
//};
//
////struct timeval {
////__int32    tv_sec;         /* seconds */
////__int32    tv_usec;        /* microseconds */
////};
//
//inline int gettimeofday(struct timeval *tv/*in*/, struct timezone *tz/*in*/)
//{
//  FILETIME ft;
//  __int64 tmpres = 0;
//  TIME_ZONE_INFORMATION tz_winapi;
//  int rez=0;
//
//   ZeroMemory(&ft,sizeof(ft));
//   ZeroMemory(&tz_winapi,sizeof(tz_winapi));
//
//    GetSystemTimeAsFileTime(&ft);
//
//    tmpres = ft.dwHighDateTime;
//    tmpres <<= 32;
//    tmpres |= ft.dwLowDateTime;
//
//    /*converting file time to unix epoch*/
//    tmpres /= 10;  /*convert into microseconds*/
//    tmpres -= DELTA_EPOCH_IN_MICROSECS; 
//    tv->tv_sec = (__int32)(tmpres*0.000001);
//    tv->tv_usec =(tmpres%1000000);
//
//	if (tz)
//	{
//		//_tzset(),don't work properly, so we use GetTimeZoneInformation
//		rez = GetTimeZoneInformation(&tz_winapi);
//		tz->tz_dsttime = (rez == 2) ? true : false;
//		tz->tz_minuteswest = tz_winapi.Bias + ((rez == 2) ? tz_winapi.DaylightBias : 0);
//	}
//
//  return 0;
//}
//#endif