

#pragma once

#include <IBase.h>

class IHomingEVT_V1;
class IHoming_V1 : public IBase
{
public:
	virtual void AddEvent(IHomingEVT_V1* pI) = 0;

public:
	virtual void StartHoming() = 0;
};

class IHomingEVT_V1
{
public:
	enum _eEvent
	{
		eHomingDone,
	};

public:
	virtual void OnEvtHoming(IHomingEVT_V1::_eEvent e) = 0;
};
