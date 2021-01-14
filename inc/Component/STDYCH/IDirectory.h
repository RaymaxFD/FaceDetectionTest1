
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
	// 여러 IDirectory 인터페이스를 쓸 때에 구별을 하기 위하여
	virtual void SetIndex(int iIndex = 0) = 0;

public:
	// 전체 경로만 지정해 주면 알아서 다 만든다.
	virtual bool Create(TCHAR* strPath) = 0;
	// 해당 디렉토리의 모든 파일 삭제
	virtual void DeleteAllFiles(TCHAR* strPath) = 0;
	// 파일과 디렉토리를 포함하여 모두 다 삭제
	virtual void EmptyDirectory(TCHAR* strPath) = 0;

public:
	virtual bool SplitPath(TCHAR (&strInput)[MAX_PATH], TCHAR (&strDrive)[_MAX_DRIVE], TCHAR (&strDir)[_MAX_DIR], TCHAR (&strFileName)[_MAX_FNAME], TCHAR (&strExt)[_MAX_EXT]) = 0;

public:
	virtual bool GetRunPath(TCHAR (&strPath)[MAX_PATH]) = 0;
	virtual IString* GetRunPath() = 0;

public:	
	virtual bool SelectFolder(HWND hWnd, TCHAR (&strSelected)[MAX_PATH], TCHAR (&strInitFolder)[MAX_PATH], TCHAR* strTilte = NULL) = 0;

public:
	// 현재 디렉토리 내의 폴더들 검색
	virtual void QueryDirectories(const TCHAR* strPath) = 0;
	// 현재 디렉토리 내의 파일들 검색
	virtual void QueryFiles(const TCHAR* strPath) = 0;
	// 현재 디렉토리 내의 폴더들 하위까지 검색
	virtual void QueryDirectoriesSub(const TCHAR* strPath) = 0;
	// 현재 디렉토리 내의 파일들 하위까지 검색
	virtual void QueryFilesSub(const TCHAR* strPath) = 0;
};

class IEvtDirectory
{
public:
	virtual void IEvtDirQueryStart(int iIndex)                        {}
	virtual void IEvtDirQueryFound(int iIndex, TCHAR (&str)[MAX_PATH]){}
	virtual void IEvtDirQueryEnd(int iIndex)                          {}
};