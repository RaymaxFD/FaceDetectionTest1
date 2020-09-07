
#pragma once

#include <IBase.h>

class IIPCamMan : public IBase
{
public:
	virtual void Move2First() = 0;
	virtual bool GetNext(TCHAR (&strCamDll)[MAX_PATH], GUID& idCam, 
		TCHAR (&strDecoderDll)[MAX_PATH], GUID& idDecoder, 
		TCHAR (&strMaker)[MAX_PATH], TCHAR (&strModel)[MAX_PATH]) = 0;
};
