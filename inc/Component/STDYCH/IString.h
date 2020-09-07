
#pragma once
#include <IBase.h>

class IString : public IBase
{
public:
	virtual void Set1(TCHAR* pStr) = 0;
	virtual void Set2(IString* pStr) = 0;
	virtual TCHAR* Get() = 0;
	virtual void Add1(TCHAR* pStr) = 0;
	virtual void Add2(IString* pStr) = 0;
	virtual void Format(const TCHAR* pStr, ...) = 0;
	virtual void Reset() = 0;
	virtual long Length() = 0;

public:
	virtual bool MakeUpper(TCHAR (&str)[MAX_PATH]) = 0;
	virtual bool SplitPath(TCHAR (&strInput)[MAX_PATH], TCHAR (&strDrive)[_MAX_DRIVE], TCHAR (&strDir)[_MAX_DIR], TCHAR (&strFileName)[_MAX_FNAME], TCHAR (&strExt)[_MAX_EXT]) = 0;

public:
	virtual bool MakeUpper() = 0;
	virtual bool SplitPath(TCHAR(&strDrive)[_MAX_DRIVE], TCHAR(&strDir)[_MAX_DIR], TCHAR(&strFileName)[_MAX_FNAME], TCHAR(&strExt)[_MAX_EXT]) = 0;

public:
	virtual bool Find(TCHAR* pStr) = 0;

public:
	virtual void Left(int iLen, TCHAR* pStrReturn) = 0;
	virtual void Right(int iLen, TCHAR* pStrReturn) = 0;
	virtual void Mid(int iFrom, int iTo, TCHAR* pStrReturn) = 0;

public:
	virtual bool IsSame(TCHAR* pStr) = 0;
	virtual bool IsSame(IString* pIStr) = 0;
public:
	virtual bool IsSameLeft(int iLen, TCHAR* pStr) = 0;
	virtual bool IsSameRight(int iLen, TCHAR* pStr) = 0;
	virtual bool IsSameMid(int iFrom, int iTo, TCHAR* pStr) = 0;
};
