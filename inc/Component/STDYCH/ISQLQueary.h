#pragma once

#include <IBase.h>

class IString;

class ISQLQueary : public IBase
{
public:
	virtual void ColumnAdd(IString* pIStr) = 0;
	virtual void ColumnReset() = 0;

	virtual void SetTable(IString* pIStr) = 0;

	virtual void WhereAdd(IString* pIStr, bool bOr = false) = 0;
	virtual void WhereDateAdd(IString* pIStr, DATE dtBegin, DATE dtEnd, bool bOr = false) = 0;
	virtual void WhereReset() = 0;

	virtual void GetSQL(IString** ppIStr) = 0;
};