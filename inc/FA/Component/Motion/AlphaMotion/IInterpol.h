
#pragma once

#include <IBase.h>

class IEvtInterpol_V1;
class IAxis_V1;

class IInterpol_V1 : public IBase
{
public:
	enum _eAxis
	{
		AXIS_0,
		AXIS_1,
		AXIS_2,
		AXIS_3,
		AXIS_MAX,
	};

	enum _eDir
	{
		DIR_CW,
		DIR_CCW,
	};

public:
	virtual void AddIEvent(IEvtInterpol_V1* pI) = 0;

public:
	virtual void SetAxis(int iAxis, IAxis_V1* pI) = 0;

public:
	virtual void SetBoardNbr(USHORT usBoard) = 0;

public:
	virtual bool InterpolationMoveAbs(int (&iAxis)[4], long (&lTarget)[4]) = 0;
};

class IEvtInterpol_V1
{
public:
	virtual void EvtInterpolationDone()                                               {}
};
