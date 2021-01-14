

#pragma once

#include <Media/IMedia.h>
#include <fa/nccutting/ICamera.h>

class IBuffer;
class IEvtPatternMatching_V2;

class IPatternMatching_V2 : public IBase, public IMedia
{
public:
	virtual void AddIEvent(IEvtPatternMatching_V2* pI) = 0;

public:
	virtual void SetICamera(ICamera_V1::_eCamIndex eCam, ICamera_V1* pI) = 0;

public:
	virtual bool Teaching(IBuffer* pIBuff, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, RECT& rtROI, TCHAR* pStr) = 0;
	virtual bool Matching(IBuffer* pIBuff, DWORD dwWidth, DWORD dwHeight, DWORD dwDepth, TCHAR* pStr) = 0;

public:
	virtual bool Teaching(DWORD dwCamIndex, RECT& rtROI, TCHAR* pStr) = 0;
	virtual bool Matching(DWORD dwCamIndex, TCHAR* pStr) = 0;
};


class IEvtPatternMatching_V2
{
public:
	virtual void IEvtPatternMatchingFound(long lCenterX, long lCenterY){}
	virtual void IEvtPatternMatchingDone(){}
};