
#pragma once

#include <IWorker.h>

class IEvtTimer;
class ITimer : public IWorker
{
public:
	virtual void SetID(int iID) = 0;

public:
	virtual void IEvtAdd(IEvtTimer* pI) = 0;
	virtual void IEvtRemove(IEvtTimer* pI) = 0;
	virtual void IEvtReset(IEvtTimer* pI) = 0;

public:
	struct _stDateTime
	{
		int iDayOf365;
		int iYear;
		int iMonth;
		int iDayOfWeek; // 일요일이 1이얌.
		int iDay;
		int iHour;
		int iMinute;
		int iSecond;
		int iMilliseconds;
	};
public:
	virtual _stDateTime CurrentDateTime() = 0;
};

class IEvtTimer
{
public:
	virtual void OnTimer(int iID){}
};