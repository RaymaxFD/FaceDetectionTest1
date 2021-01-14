
#pragma once

#include <Media/IMedia.h>
#include <IBase.h>

class ISaveBmpRealTime : public IBase, public IMedia
{
public:
	virtual void ResetCounter() = 0;
	virtual void SetFolder(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void SetFileName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void EnableRecord(bool) = 0;
	virtual void SetDimension(long lW, long lH) = 0;

public:
	virtual void QueryYUV() = 0;
	virtual void SaveYUV2RGB() = 0;
};
