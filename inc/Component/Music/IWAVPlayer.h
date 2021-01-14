#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IWAVPlayer : public IWorker, public IMedia
{
public:
	virtual void PlayWav(TCHAR* pStrFile) = 0;
};
