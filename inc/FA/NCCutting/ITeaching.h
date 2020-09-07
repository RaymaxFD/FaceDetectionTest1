
#pragma once

#include <IBase.h>
#include <fa/nccutting/ICamera.h>
#include <fa/nccutting/IMotion.h>

class ITeaching_V1 : public IBase
{
public:
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eFrontRear) = 0;

public:
	virtual void SetICamera(ICamera_V1::_eCamIndex eCam, ICamera_V1* pICam) = 0;
	virtual void Teaching(RECT rtROI) = 0;
};