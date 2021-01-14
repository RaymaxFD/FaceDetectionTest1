
#pragma once

#include <IBase.h>

class IUtil : public IBase
{
public:
	virtual void TrayHide() = 0;
	virtual void TrayShow() = 0;
	virtual bool IsTrayAutoHide() = 0;

public:
	virtual void DoEvents() = 0;

public:
	virtual bool GetResolution(int iMon, DWORD& dwW, DWORD& dwH) = 0;
	virtual bool SetResolution(int iMon, DWORD dwW, DWORD dwH) = 0;

public:
	virtual void FolderOpen(TCHAR* pStr = NULL) = 0;

public:
	virtual ULONG Rand(ULONG iFrom, ULONG iTo, uint32_t seed = 0) = 0;

public:
	virtual void LaunchExe(TCHAR* pStr) = 0;
};