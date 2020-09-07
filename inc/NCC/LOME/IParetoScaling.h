
#pragma once

#include <IBase.h>

class IParetoScaling_V1 : public IBase
{
public:
	virtual void SetLen(DWORD dwLen) = 0;
	virtual void SetNomalized(double* pData, DWORD dwLen) = 0;
	virtual void SetnRefAverage(TCHAR* pStr) = 0;
	virtual void SetnRefStandardDeviation(TCHAR* pStr) = 0;
public:
	virtual bool GetParetoScaled(double* pData, DWORD dwLen) = 0;

public:
	virtual void ParetoScaling() = 0;
};
