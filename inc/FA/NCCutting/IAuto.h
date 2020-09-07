
#pragma once

#include <IBase.h>
#include "Sheet.h"

class IFindFirstLine_V1;
class ISheetLoad_V1;
class ISheetUnload_V1;
class IAutoMotion_V1;
class IAutoMotionSemi_V1;
class IMotion_V1;
class IMotionStep_V1;
class IEvtAuto_V1;
class ICamera_V2;
class IPressure;
class ICheckTwoLines_V1;

class IAuto_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtAuto_V1* pI) = 0;

public:
	virtual void SetSheet(_stSheet& st) = 0;
	virtual void SetInterfaces(IFindFirstLine_V1* pIFindFirstLine, ISheetLoad_V1* pISheetLoad, ISheetUnload_V1* pISheetUnload, IAutoMotion_V1* pIAutoMotion, IAutoMotionSemi_V1* pIAutoMotionSemi, IMotion_V1* pIServo, IPressure* pIRegFront, IPressure* pIRegRear) = 0;
	virtual void SetCameraInterfaces(ICamera_V2* pICamFrontLeft, ICamera_V2* pICamFrontRight, ICamera_V2* pICamRearLeft, ICamera_V2* pICamRearRight) = 0;

public:
	virtual bool AutoStart(bool bSimul = false) = 0;
	virtual bool AutoSemiStart(bool bSimul = false) = 0;
	virtual void AutoStop() = 0;
	virtual void AutoPause(bool bPause) = 0;
	virtual bool TestLine() = 0;
	virtual bool IsSimul() = 0;

public:
	virtual void SetPressure(USHORT usFront, USHORT usRear) = 0;

public:
	virtual void SetICheckTwoLinesFront(ICheckTwoLines_V1* pI) = 0;
	virtual void SetICheckTwoLinesRear(ICheckTwoLines_V1* pI) = 0;
};

class IEvtAuto_V1
{
public:
	virtual void EvtAutoDone(bool bSimul){}
	virtual void EvtErrLinePos(){}
};
