#pragma once

#include <IWorker.h>
#include <Media/IMedia.h>

class IOpticalFlow_V1 : public IWorker, public IMedia
{
public:
	virtual void Enable(bool b) = 0;
};
