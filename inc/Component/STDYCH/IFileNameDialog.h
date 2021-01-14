
#pragma once

#include <IWorker.h>

class IFileNameDialog : public IWorker
{
public:
	virtual void SetTitle(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void SetInit(TCHAR(&str)[MAX_PATH]) = 0;
	virtual bool GetOpenFileNames(HWND hWnd, TCHAR* str, DWORD nStrMax, TCHAR* strFilter = (TCHAR*)L"All\0 *.*\0Text\0*.txt\0") = 0;
	virtual bool GetSaveFileNames(HWND hWnd, TCHAR(&str)[MAX_PATH], int& iFilterIndex, TCHAR* strFilter = (TCHAR*)L"Text\0*.txt\0All\0 *.*\0") = 0;
};