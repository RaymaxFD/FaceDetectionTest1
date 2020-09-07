
#pragma once

#include "media/imedia.h"
//#include <ibase.h>

class IAnalyzerEvt_V1;
class IDisplay_V1;
class IEvent_V1;
class IAnalyzer_V1
	: public IMedia//, public IBase
{
public:
	virtual void SetIEvent(IAnalyzerEvt_V1* p) = 0;

public:
	virtual void EnableAnalyzing(bool b) = 0;
	virtual bool IsAnalyzing() = 0;

public:
	virtual bool EnableWideAngle180(bool b) = 0;
	//virtual void EnableWideAngle360(bool b) = 0;
	//virtual void EnableMotionDetection(bool b) = 0;
	//virtual void EnableMotionTracking(bool b) = 0;

public:
	virtual void AddMediaOutput(IMedia* p) = 0;
};

class IAnalyzerEvt_V1
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;
};
