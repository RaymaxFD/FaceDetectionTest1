

#pragma once

#include <IBase.h>

class INomalize_V1 : public IBase
{
public:
	virtual void SetReArrangedIntensity(double* pData, DWORD dwLen) = 0;
	virtual void SetnRef2ndColFile(TCHAR* pStr) = 0;

public:
	virtual void Nomalize() = 0;

public:
	virtual void GetNomalizedLen(DWORD& dwLen) = 0;
	virtual void GetNomalizedData(double* pData) = 0;
};