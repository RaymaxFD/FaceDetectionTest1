
#pragma once

#include <IWorker.h>

/*
expire day ����� ���?
- ���α׷��� ����� ���� ��¥/�ð��� ����ü�� �߰�
- encryption�Ͽ� ���Ͽ� ����
- ���� ��¥�� ���������� ����� ���� ��¥/�ð����� �� �����̸� ���� ��¥ �Ϸ� �߰�. 
- ���� ��¥�� �̸� ������ ��¥�� �������� ���α׷� ����
*/

class IEvtLicense;

class ILicense : public IWorker
{
public:
	virtual void IEventAdd(IEvtLicense* pI) = 0;
	virtual void IEventRemove(IEvtLicense* pI) = 0;
	virtual void IEventReset(IEvtLicense* pI) = 0;

public:
	virtual bool GenLicense(TCHAR* strLicFile, BYTE* strPass, int iDueDay = -1) = 0;
	virtual bool CheckLicense(TCHAR* strLicFile, BYTE* strPass) = 0;
	virtual bool ChangePass(TCHAR* strLicFile, BYTE* strPassOld, BYTE* strPassNew) = 0;
};

class IEvtLicense
{
public:
	virtual void IEvtLicenseGenerationOk() {}
	virtual void IEvtLicenseGenerationFail() {}

public:
	virtual void ILicenseCheckOk(){}
	virtual void ILicenseCheckFail(){}
};