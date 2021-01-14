
#pragma once
#include <IWorker.h>

#ifndef MAX_PATH
#define _MAX_PATH   260 /* max. length of full pathname */
#endif

#ifndef _MAX_DRIVE
#define _MAX_DRIVE  3   /* max. length of drive component */
#endif

#ifndef _MAX_DIR
#define _MAX_DIR    256 /* max. length of path component */
#endif

#ifndef _MAX_FNAME
#define _MAX_FNAME  256 /* max. length of file name component */
#endif

#ifndef _MAX_EXT
#define _MAX_EXT    256 /* max. length of extension component */
#endif

class IString;

class IEvtDirectory;
class IDirectory : public IWorker
{
public:
	virtual void AddIEvent(IEvtDirectory* pI) = 0;

public:
	// ���� IDirectory �������̽��� �� ���� ������ �ϱ� ���Ͽ�
	virtual void SetIndex(int iIndex = 0) = 0;

public:
	// ��ü ��θ� ������ �ָ� �˾Ƽ� �� �����.
	virtual bool Create(TCHAR* strPath) = 0;
	// �ش� ���丮�� ��� ���� ����
	virtual void DeleteAllFiles(TCHAR* strPath) = 0;
	// ���ϰ� ���丮�� �����Ͽ� ��� �� ����
	virtual void EmptyDirectory(TCHAR* strPath) = 0;

public:
	virtual bool SplitPath(TCHAR (&strInput)[MAX_PATH], TCHAR (&strDrive)[_MAX_DRIVE], TCHAR (&strDir)[_MAX_DIR], TCHAR (&strFileName)[_MAX_FNAME], TCHAR (&strExt)[_MAX_EXT]) = 0;

public:
	virtual bool GetRunPath(TCHAR (&strPath)[MAX_PATH]) = 0;
	virtual IString* GetRunPath() = 0;

public:	
	virtual bool SelectFolder(HWND hWnd, TCHAR (&strSelected)[MAX_PATH], TCHAR (&strInitFolder)[MAX_PATH], TCHAR* strTilte = NULL) = 0;

public:
	// ���� ���丮 ���� ������ �˻�
	virtual void QueryDirectories(const TCHAR* strPath) = 0;
	// ���� ���丮 ���� ���ϵ� �˻�
	virtual void QueryFiles(const TCHAR* strPath) = 0;
	// ���� ���丮 ���� ������ �������� �˻�
	virtual void QueryDirectoriesSub(const TCHAR* strPath) = 0;
	// ���� ���丮 ���� ���ϵ� �������� �˻�
	virtual void QueryFilesSub(const TCHAR* strPath) = 0;
};

class IEvtDirectory
{
public:
	virtual void IEvtDirQueryStart(int iIndex)                        {}
	virtual void IEvtDirQueryFound(int iIndex, TCHAR (&str)[MAX_PATH]){}
	virtual void IEvtDirQueryEnd(int iIndex)                          {}
};