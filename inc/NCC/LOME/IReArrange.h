

#pragma once

#include <IBase.h>

class IEvtReArrange_V1;

class IReArrange_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtReArrange_V1* pI) = 0;

public:
	virtual void SetPatientFile(TCHAR* pStr) = 0;

public:
	virtual void SetnRefMass(TCHAR* pStr) = 0;

public:
	virtual void ReArrange() = 0;


public:
	virtual void GetReArrangedIntensityLen(DWORD& dwLen) = 0;
	virtual void GetReArrangedIntensityData(double* pData) = 0;
};

class IEvtReArrange_V1
{
public:
	virtual void OnEvtReArrangeOverTwo(double dMass, double dIntensity){}
	virtual void OnEvtReArrangedone(){}
};