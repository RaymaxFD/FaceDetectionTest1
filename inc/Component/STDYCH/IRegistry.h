
#pragma once

#include "ibase.h"

class IRegistry : public IBase
{
public:
	virtual bool ReadNumber(TCHAR* strCompony, TCHAR* strProduct, TCHAR* strItem, TCHAR* strItemSub, DWORD& dwValue, DWORD& dwErr) = 0;
	virtual bool WriteNumber(TCHAR* strCompony, TCHAR* strProduct, TCHAR* strItem, TCHAR* strItemSub, DWORD dwValue, DWORD& dwErr) = 0;
	virtual bool ReadString(TCHAR* strCompony, TCHAR* strProduct, TCHAR* strItem, TCHAR* strItemSub, TCHAR* strValue, DWORD dwValueLen, DWORD& dwErr) = 0;
	virtual bool WriteString(TCHAR* strCompony, TCHAR* strProduct, TCHAR* strItem, TCHAR* strItemSub, TCHAR* strValue, DWORD& dwErr) = 0;

public:
	virtual bool SetRegistyStartProgram(bool bAutoExec, LPCTSTR lpValueName, LPCTSTR lpExeFileName, DWORD& dwError) = 0;
};