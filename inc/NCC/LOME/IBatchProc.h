
#pragma once

#include <IBase.h>

#include <string>
using namespace std;

class IEvtBatchProc_V1;
class IBatchProc_V1 : public IBase
{
public:
	enum _eFileType
	{
		eTXT,
		eT2D,
		eNone,
	};
public:
	virtual void AddIEvent(IEvtBatchProc_V1* pI) = 0;

public:
	virtual void SetWorkingDirectory(TCHAR* pStr) = 0;
	virtual void SetOutputDirectory(TCHAR* pStr) = 0;
	virtual void SetSaveAsText(TCHAR* pStr) = 0;
	virtual void SetSaveText(TCHAR* pStr) = 0;
	virtual void SetNoText(TCHAR* pStr) = 0;	

public:
	virtual void Start(_eFileType eType) = 0;
	virtual void Stop() = 0;
	virtual void Pause(bool bPause) = 0;

public:
	virtual void SetMassToleranceValue(float fVal) = 0;
	virtual void SetMinIntensityValue(float fVal) = 0;
	virtual void SetMaxCompondsValue(int iVal) = 0;
	virtual void SetLastMZ(double dMZ) = 0;

public:
	virtual void KillMarkerView() = 0;
};

class IEvtBatchProc_V1
{
public:
	virtual void IEvtPatientDone(const TCHAR* pStr){}
	virtual void IEvtBatchProcDone(){}
	virtual void IEvtBatchProcLastMZError(){}
};