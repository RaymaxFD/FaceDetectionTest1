
#pragma once

#include <IBase.h>
#include <fa/nccutting/IMotion.h>

class ICutting_V1;

class IEvtTestCut_V1;
class ITestCut_V1 : public IBase
{
public:
	virtual void SetICutting(ICutting_V1* pI) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;
};

class IEvtTestCut_V1
{
};
