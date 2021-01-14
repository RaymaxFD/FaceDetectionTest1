#pragma once

#include <IBase.h>
class IString;

class IRTSPAddrGen_V1 : public IBase
{
public:
	enum _eMaker
	{
		eMakerHIK,
		eMakerHiView,
		eMakeCantonk,
	};

public:
	virtual IString* Gen4PreView(_eMaker eMaker, TCHAR* strIP, DWORD dwPort, TCHAR* strID, TCHAR* strPass, int iChannel = 1, int iSubStream = 1) = 0;
	virtual IString* Gen4PlayBack(_eMaker eMaker, TCHAR* strIP, DWORD dwPort, TCHAR* strID, TCHAR* strPass, SYSTEMTIME stBegin, SYSTEMTIME stEnd, int iChannel = 1, int iSubStream = 1) = 0;
};
