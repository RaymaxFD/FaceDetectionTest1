

#pragma once

#include <IBase.h>
class IString;
class IBuffer;
class IFile : public IBase
{
public:
	virtual bool Open(TCHAR* pStr) = 0;
	virtual bool Create(TCHAR* pStr, bool bOverWrite = true) = 0;
	//virtual bool Create(IString* pIStr) = 0; // ->Get()을 쓰세요.
	virtual long Write(IBuffer* pIBuff, bool bOverlapped = false) = 0;
	virtual long Write(BYTE* pData, long lSave, bool bOverlapped = false) = 0;
	virtual long Read(BYTE* pData, long lRead, bool bOverlapped = false) = 0;
	virtual void Close() = 0;

public:
	virtual void GetFileName(TCHAR (&strFile)[MAX_PATH]) = 0;
	virtual bool GetFileSize(DWORD& dwSizeHigh, DWORD& dwSizeLow) = 0;
	virtual bool IsPathFileExists(TCHAR* p) = 0;

public:
	virtual void SetAttributeNormal() = 0;
	virtual void SetAttributeHidden() = 0;
	virtual void SetAttributeSystem() = 0;
	virtual void SetAttributeReadOnly() = 0;
	virtual void SetAttributeWriteOnly() = 0;

public:
	virtual bool GetFileTime(SYSTEMTIME& stCreation, SYSTEMTIME& stLastAccess, SYSTEMTIME& stWrite) = 0;

public:
	virtual void Delete() = 0;
};
