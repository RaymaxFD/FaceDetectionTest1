#pragma once

#include <Component/StdYch/IDirectory.h>
#include <Component/StdYch/IString.h>
#include <Component/StdYch/IBufferPool.h>
#include <Component/StdYch/IDebug.h>
#include <Component/StdYch/ITimer.h>
#include <Component/StdYch/IStopWatch.h>
#include <Component/StdYch/ISleep.h>
#include <Component/StdYch/IDisplay.h>
#include <Component/StdYch/IFile.h>
#include <Component/StdYch/IFileNameDialog.h>
#include <Component/StdYch/IRegistry.h>
#include <Component/stdych/ISerial.h>
#include <Component/stdych/IUtil.h>
#include <Component/STDYCH/ILicense.h>
#include <Component/STDYCH/IRelayMessage.h>
#include <Component/STDYCH/IIniFile.h>
#include <Component/STDYCH/ISyncMutex.h>
#include <Component/STDYCH/ILog.h>
#include <Component/STDYCH/ISystemInfo.h>
#include <Component/STDYCH/IDateTime.h>

class CStdIV
{
public:
	CStdIV()
		: m_hInstStdIV(NULL)
	{
	}
	~CStdIV()
	{
	}

private:
	HINSTANCE m_hInstStdIV;

protected:
	IDirectory* _GetIDir()
	{
		IMPLEMENT_IBASE;

		IDirectory* pIDir;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_DIRECTORY, IDirectory, pIDir);

		return pIDir;
	}
	IString* _GetIStr()
	{
		IMPLEMENT_IBASE;

		IString* pIStr = NULL;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_STRING, IString, pIStr);

		return pIStr;
	}
	IBufferPool* _GetIBufPool()
	{
		IMPLEMENT_IBASE;

		IBufferPool* pIPool;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_BUFFERPOOL, IBufferPool, pIPool);

		return pIPool;
	}
	IDebug* _GetIDebug()
	{
		IMPLEMENT_IBASE;

		IDebug* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_DEBUG, IDebug, pI);

		return pI;
	}
	ITimer* _GetITimer()
	{
		IMPLEMENT_IBASE;

		ITimer* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_TIMER, ITimer, pI);

		return pI;
	}
	IStopWatch* _GetISW()
	{
		IMPLEMENT_IBASE;

		IStopWatch* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_STOPWATCH, IStopWatch, pI);

		return pI;
	}
	ISleep* _GetISleep()
	{
		IMPLEMENT_IBASE;

		ISleep* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_SLEEP, ISleep, pI);

		return pI;
	}
	IDisplay* _GetIDisplay()
	{
		IMPLEMENT_IBASE;

		IDisplay* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_DISPLAY, IDisplay, pI);

		return pI;
	}
	IDisplay2* _GetIDisplay2()
	{
		IMPLEMENT_IBASE;

		IDisplay2* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_DISPLAY2, IDisplay2, pI);

		return pI;
	}
	IFile* _GetIFile()
	{
		IMPLEMENT_IBASE;

		IFile* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_FILE, IFile, pI);

		return pI;
	}
	IFileNameDialog* _GetIFND()
	{
		IMPLEMENT_IBASE;

		IFileNameDialog* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_FILENAMEDIALOG, IFileNameDialog, pI);

		return pI;
	}
	IRegistry* _GetIRegistry()
	{
		IMPLEMENT_IBASE;

		IRegistry* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_REGISTRY, IRegistry, pI);

		return pI;
	}
	ISerial* _GetISerial()
	{
		IMPLEMENT_IBASE;

		ISerial* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_SERIAL, ISerial, pI);

		return pI;
	}
	ISerial2* _GetISerial2()
	{
		IMPLEMENT_IBASE;

		ISerial2* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_SERIAL2, ISerial2, pI);

		return pI;
	}
	IUtil* _GetIUtil()
	{
		IMPLEMENT_IBASE;

		IUtil* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_UTIL, IUtil, pI);

		return pI;
	}
	ILicense* _GetILicense()
	{
		IMPLEMENT_IBASE;

		ILicense* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_LICENSE, ILicense, pI);

		return pI;
	}
	IRelayMessage* _GetIRM()
	{
		IMPLEMENT_IBASE;

		IRelayMessage* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_RELAYMESSAGE, IRelayMessage, pI);

		return pI;
	}
	IIniFile* _GetINIFile()
	{
		IMPLEMENT_IBASE;

		IIniFile* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_INIFILE, IIniFile, pI);

		return pI;
	}
	ISyncMutex* _GetIMutex()
	{
		IMPLEMENT_IBASE;

		ISyncMutex* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_SYNC_MUTEX, ISyncMutex, pI);

		return pI;
	}
	ILog* _GetILog()
	{
		IMPLEMENT_IBASE;

		ILog* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_LOG, ILog, pI);

		return pI;
	}
	ISystemInfo* _GetISystemInfo()
	{
		IMPLEMENT_IBASE;

		ISystemInfo* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_SYSTEMINFO, ISystemInfo, pI);

		return pI;		
	}
	IDateTime* _GetIDateTime()
	{
		IMPLEMENT_IBASE;

		IDateTime* pI;
		IV_GET_IF(m_hInstStdIV, ID_DLL_STDIV, ID_STDIV_DATETIME, IDateTime, pI);

		return pI;
	}
};

