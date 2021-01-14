#pragma once

#include <IBase.h>

class IKMeans : public IBase
{
public:
	virtual void SetCluster(int iCluster = 10) = 0;
	virtual void SetIteration(int iIter = 100) = 0;
	virtual void PointAdd(POINT pt) = 0;
	virtual void PointReset() = 0;

public:
	virtual void Run() = 0;
	virtual void GetCenters(int iPos, vector<POINT>& vec) = 0;
	virtual void GetClusterMembers(int iPos, vector<POINT>& vec) = 0;
};
