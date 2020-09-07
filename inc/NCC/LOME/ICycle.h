

#pragma once

#include <IBase.h>
#include <NCC/LOME/IBatchProc.h>

class IEvtCycle_V1;
class ICycle_V1 : public IBase
{
public:
	enum _eState
	{
		eIdle,
		eBatchProc,
		eReArrange,
		eNomalize,
		eParetoScaling,
		eWeightingFactor,
		eCompleted,
	};

public:
	virtual bool IsIdle() = 0;

public:
	virtual void AddIEvent(IEvtCycle_V1* pI) = 0;

public:
	virtual void SetnRefMassFile(TCHAR* pStr) = 0;
	virtual void SetnRef2ndColFile(TCHAR* pStr) = 0;
	virtual void SetnRefAverage(TCHAR* pStr) = 0;
	virtual void SetnRefStandardDeviation(TCHAR* pStr) = 0;
	virtual void SetWeighttingFactor(TCHAR* pStr) = 0;

public:
	virtual void Reset() = 0;
	virtual void Start(IBatchProc_V1::_eFileType eFileType) = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool bPause) = 0;

public:
	virtual void SetMassToleranceValue(float fVal) = 0;
	virtual void SetMinIntensityValue(float fVal) = 0;
	virtual void SetMaxCompondsValue(int iVal) = 0;
	virtual void SetLastMZ(double dMZ) = 0;
	virtual void SetWorkingDirectory(TCHAR* pStr) = 0;
	virtual void SetOutputDirectory(TCHAR* pStr) = 0;
	virtual void SetSaveAsText(TCHAR* pStr) = 0;
	virtual void SetSaveText(TCHAR* pStr) = 0;
	virtual void SetNoText(TCHAR* pStr) = 0;

public:
	virtual void GetScore(double& dScore) = 0;
};

class IEvtCycle_V1
{
public:
	virtual void IEvtCycleDone(){}
	virtual void IEvtCycleNoFile(){}
	virtual void IEvtCycleState(ICycle_V1::_eState eState){}
	virtual void IEvtCycleScreeneeFileDone(){}
	virtual void IEvtCycleScreeneeDone(){}
};