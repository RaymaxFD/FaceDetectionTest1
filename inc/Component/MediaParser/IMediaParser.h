
#pragma once
#include <IWorker.h>
#include <Media\IMedia.h>

class IMediaParser : public IWorker, public IMedia
{
};