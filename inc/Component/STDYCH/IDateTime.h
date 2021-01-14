#pragma once

#include <IBase.h>

class IDateTime : public IBase
{
public:
	virtual void GetNow() = 0;

public:
	virtual void SetDateTime(SYSTEMTIME st) = 0;
	virtual void GetDateTime(SYSTEMTIME& st) = 0;

public:
	virtual void Add(SYSTEMTIME st) = 0;
	virtual void Minus(SYSTEMTIME st) = 0;

public:
	virtual double VariantTime() = 0;

};
