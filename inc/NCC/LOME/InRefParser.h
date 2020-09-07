

#pragma once

#include <IBase.h>

class IEvtnRefParser_V1;
class InRefParser_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtnRefParser_V1* pI) = 0;

public:
	virtual void SetnRefFile(TCHAR* pStr) = 0;

public:
	virtual void SavenRefMass(TCHAR* pStr) = 0;
	virtual void SavenRef2ndCol(TCHAR* pStr) = 0;

public:
	virtual void SaveAverageAndStandardDeviaion(TCHAR* pStrAverage, TCHAR* pSD) = 0;
};

class IEvtnRefParser_V1
{
};