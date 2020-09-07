

#pragma once

#include "IBase.h"

class ISplitPath : public IBase
{
public:
	virtual void GetDrive(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetPath(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetFileName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetExt(TCHAR (&str)[MAX_PATH]) = 0;
};
