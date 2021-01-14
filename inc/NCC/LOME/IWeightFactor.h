

#pragma once

#include <IBase.h>

class IWeightFactor_V1 : public IBase
{
public:
	virtual void SetLen(DWORD dwLen) = 0;
	virtual void SetWeightingFactor(TCHAR* pStr) = 0;
	virtual void SetParetoScaled(double* pData, DWORD dwLen) = 0;

public:
	virtual void WeightFactor() = 0;

public:
	virtual void GetWeighted(double* pData) = 0;
};