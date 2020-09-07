

#pragma once

#include <Media/IMedia.h>

class IBuffer;
class IEvtPatternMatching_V1;

class IPatternMatching_V1 : public IMedia
{
public:
	virtual void AddIEvent(IEvtPatternMatching_V1* pI) = 0;

public:
	virtual bool Teaching(IBuffer* pIBuff, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT& rtROI, char* pStr) = 0;
	virtual bool Matching(IBuffer* pIBuff, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT& rtROI, char* pStr) = 0;

public:
	virtual bool Teaching(DWORD dwCamIndex, RECT& rtROI, char* pStr) = 0;
	virtual bool Matching(DWORD dwCamIndex, char* pStr) = 0;

public:
	virtual void Save(IBuffer* pIBuff, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT& rtROI, char* pStrFile) = 0;
};


class IEvtPatternMatching_V1
{
public:
	virtual void IEvtPatternMatchingFound(double dScore, double dCenterX, double dCenterY){}
	virtual void IEvtPatternMatchingDone(){}
	virtual void IEvtPatternMatchingFail(){}
};