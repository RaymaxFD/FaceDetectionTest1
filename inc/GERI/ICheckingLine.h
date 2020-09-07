#pragma once

#include <IBase.h>

class ICheckingLine_V1 : public IBase
{
public:
	virtual void LSReset() = 0;
	virtual void LSAdd(double dX, double dY) = 0;
	virtual void LSMoveFirst() = 0;
	virtual bool LSGetNext(double& dX, double& dY) = 0;
	virtual void LSGetFirst(double& dX, double& dY) = 0;
	virtual void LSGetLast(double& dX, double& dY) = 0;
	virtual size_t LSGetCount() = 0;
public:
	virtual void LSXReset() = 0;
	virtual void LSXAdd(double dX) = 0;
	virtual void LSXMoveFirst() = 0;
	virtual bool LSXGetNext(double& dX) = 0;
	virtual void LSXGetFirst(double& dX) = 0;
	virtual void LSXGetLast(double& dX) = 0;
	virtual size_t LSXGetCount() = 0;
public:
	virtual void LSYReset() = 0;
	virtual void LSYAdd(double dY) = 0;
	virtual void LSYMoveFirst() = 0;
	virtual bool LSYGetNext(double& dY) = 0;
	virtual void LSYGetFirst(double& dY) = 0;
	virtual void LSYGetLast(double& dY) = 0;
	virtual size_t LSYGetCount() = 0;

public:
	virtual void CalcLeastSquare(double& dSlope, double& dIntercept, double& R2) = 0;
};

class ICheckingLine_V2 : public ICheckingLine_V1
{};

class ICheckingLine_V3 : public ICheckingLine_V1
{
public:
	virtual void EnableIntercept(bool b) = 0; // 장박사님 알고리즘 사용 여부
};