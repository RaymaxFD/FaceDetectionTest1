
#pragma once

#include <IBase.h>

class IBufferPool;
class IBuffer;
class IString;
class IEvtDB_V1;

struct _stOwner
{
	int iID;
	TCHAR strName[MAX_PATH];
	bool bSex;
	int iAge;
};

struct _stBlood
{
	int iID;
	int iOwnerID;
	TCHAR strDate[MAX_PATH];
	int iBloodCheckingLineID;
};

struct _stCheckingLine
{
	int iID;
	int iDrugID;
	TCHAR strDate[MAX_PATH];
	COLORREF color;
	double dSlope;
	double dIntercept;
	TCHAR strMemo[1024];
	double dXMin;
	double dXMax;
	double R2; // 상관도
};

struct _stCA199
{
	int iID;
	int iBloodID;
	double fValue;
};

struct _stGPC
{
	int iID;
	int iBloodID;
	double fValue;
};

class IDB_V1 : public IBase
{
public:
	virtual void IEventAdd(IEvtDB_V1* pI) = 0;
	virtual void IEventRemove(IEvtDB_V1* pI) = 0;
	virtual void IEventReset() = 0;

public:
	virtual bool Open(IString* pIStr) = 0;
	virtual void Close() = 0;

	// 시약
public:
	virtual void DrugAdd(IString* pIStrName) = 0;
	virtual void DrugEdit(int iID, IString* pIStrName) = 0;
	virtual void DrugRemove(int iID) = 0;
	virtual void DrugQuery(IString* pIStrSQL) = 0;

	// 피검진자
public:
	virtual void OwnerAdd(_stOwner& st) = 0;
	virtual void OwnerEdit(int iID, _stOwner& st) = 0;
	virtual void OwnerRemove(int iID) = 0;
	virtual void OwnerQuery(IString* pIStrSQL) = 0;

	// 검진 데이터
public:
	virtual int BloodAdd(_stBlood& st) = 0;
	virtual void BloodEdit(int iID, _stBlood& st) = 0;
	virtual void BloodRemove(int iID) = 0;
	virtual void BloodQuery(IString* pIStrSQL) = 0;

	// 검량선
public:
	virtual void CheckingLineAdd(_stCheckingLine& st) = 0;
	virtual void CheckingLineEdit(int iID, _stCheckingLine& st) = 0;
	virtual void CheckingLineRemove(int iID) = 0;
	virtual void CheckingLineQuery(IString* pIStrSQL) = 0;

	// CA19-9
public:
	virtual void CA199Add(_stCA199& st) = 0;
	virtual void CA199Edit(int iID, _stCA199& st) = 0;
	virtual void CA199Remove(int iID) = 0;
	virtual void CA199Query(IString* pIStrSQL) = 0;

	// GPC
public:
	virtual void GPCAdd(_stGPC& st) = 0;
	virtual void GPCEdit(int iID, _stGPC& st) = 0;
	virtual void GPCRemove(int iID) = 0;
	virtual void GPCQuery(IString* pIStrSQL) = 0;

public:
	virtual void SetPool4Owner(IBufferPool* pI) = 0;
	virtual void SetPool4Blood(IBufferPool* pI) = 0;
	virtual void SetPool4CheckingLine(IBufferPool* pI) = 0;
};

class IEvtDB_V1
{
public:
	virtual void OnEvtDBDrugBegin(){}
	virtual void OnEvtDBDrug(int iID, IString* pIStrName){}
	virtual void OnEvtDBDrugEnd(){}

public:
	virtual void OnEvtDBBloodBegin(){}
	virtual void OnEvtDBBlood(int iID, IBuffer* pIBuff){}
	virtual void OnEvtDBBloodEnd(){}

public:
	virtual void OnEvtDBOwnerBegin(){}
	virtual void OnEvtDBOwner(int iID, IBuffer* pIBuff){}
	virtual void OnEvtDBOwnerEnd(){}

public:
	virtual void OnEvtDBCheckingLineBegin(){}
	virtual void OnEvtDBCheckingLine(int iID, IBuffer* pIBuff){}
	virtual void OnEvtDBCheckingLineEnd(){}

public:
	virtual void OnEvtDBCA199Begin(){}
	virtual void OnEvtDBCA199(int iID, IBuffer* pIBuff){}
	virtual void OnEvtDBCA199End(){}

public:
	virtual void OnEvtDBGPCBegin(){}
	virtual void OnEvtDBGPC(int iID, IBuffer* pIBuff){}
	virtual void OnEvtDBGPCEnd(){}
};