

#pragma once
#include <IWorker.h>

class IStopWatch : public IWorker
{
public:
	virtual void startTimer( ) = 0;
	virtual void stopTimer( ) = 0;
	virtual double getElapsedTime() = 0; // 초단위 시간이얌.
};
