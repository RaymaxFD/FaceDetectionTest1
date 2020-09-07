
#pragma once

#include <IBase.h>
#include <fa/nccutting/IMotion.h>

class IEvtCheckTwoLines_V1;
class IPatternMatching_V1;
class ICamera_V2;

class ICheckTwoLines_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtCheckTwoLines_V1* pI) = 0;

public:
	virtual void SetStartingPoint(DWORD dwY) = 0;
	virtual void SetROI(RECT& rtROI) = 0;

public:
	virtual void SetIServo(IMotion_V1* pI) = 0;
	virtual void SetFrontRear(IMotion_V1::_eFrontRear eTable) = 0;
	virtual void SetIPatternMatching(IPatternMatching_V1* pILeft, IPatternMatching_V1* pIRight) = 0;
	virtual void SetPatternFile(char (&strLeft)[MAX_PATH], char (&strRight)[MAX_PATH]) = 0;
	virtual void SetICameras(ICamera_V2* pICamLeft, ICamera_V2* pICamRight) = 0;
	virtual void SetAutoRotation(bool bUse) = 0;

public:
	virtual bool CheckTwoLines(bool bFirstLine) = 0;
	virtual void CheckTwoLinesStop() = 0;
};

class IEvtCheckTwoLines_V1
{
public:
	virtual void CheckTwoLineOk(){}
	virtual void LinePosErr(){}
};
