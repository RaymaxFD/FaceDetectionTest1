
#pragma once

#include "IBase.h"

class ITextFile : public IBase
{
public:
	virtual bool OpenFile(PCTSTR lpFileName) = 0;
	virtual DWORD WriteToFile(PCTSTR lpContent, DWORD dwLen) = 0;
	virtual void CloseFile() = 0;
};
