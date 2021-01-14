
#pragma once

#include <IWorker.h>

/*
expire day 계산은 어떻게?
- 프로그램이 종료될 때의 날짜/시간을 구조체에 추가
- encryption하여 파일에 저장
- 현재 날짜가 마지막으로 기재된 종료 날짜/시간보다 더 이전이면 누적 날짜 하루 추가. 
- 누적 날짜가 미리 정해진 날짜와 같아지면 프로그램 종료
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