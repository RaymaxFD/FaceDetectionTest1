
#pragma once

#include <IBase.h>

class IString;

class IExcel_V1 : public IBase
{
public:
	virtual void New(int iSheet) = 0;
	virtual void ChooseWorkSheet(int iSheet) = 0;

	virtual void SetText(int iCol, int iRow, IString* pIStr) = 0;
	virtual void SetInt(int iCol, int iRow, int iVal) = 0;
	virtual void SetDouble(int iCol, int iRow, double dVal) = 0;

	virtual void Save(IString* pIStr) = 0;
	virtual void Close() = 0;
};