#pragma once

#include <IWorker.h>

// 하드 디스크 용량 체크를 전담함.
class IEvtHDDChecker
{
public:
	virtual void IEvtHDDChecker_Sufficent(TCHAR ucDrive) {}
	virtual void IEvtHDDChecker_NotSufficent(TCHAR ucDrive) {}
};

class IHDDChecker : public IWorker
{
public:
	virtual void IEvtAdd(IEvtHDDChecker* pI) = 0;
	virtual void IEvtRemove(IEvtHDDChecker* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void DriveAdd(TCHAR ucDrive) = 0;
	virtual void DriveRemove(TCHAR ucDrive) = 0;
	virtual void DriveReset() = 0;
	virtual void SetDiskMargin(TCHAR ucDrive, DWORD dwMarginGB) = 0;
	virtual bool IsSufficent(TCHAR ucDrive) = 0;
	virtual TCHAR GetFreeDrive() = 0;
};
