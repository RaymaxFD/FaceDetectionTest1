#pragma once

#include <IWorker.h>
#include <Media\IMedia.h>

class IString;
class IBuffer;

class IEvtTrainning_V1;
class ITrainning_V1 : public IWorker, public IMedia
{
public:
	virtual void IEvtAdd(IEvtTrainning_V1* pI) = 0;
	virtual void IEvtRemove(IEvtTrainning_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void Trainning(IString* pIStrVGG16, IString* pIStrMap, int iPersonCnt, IString* pIStrModel, bool forceReTrain) = 0;
};

class IEvtTrainning_V1
{
public:
	virtual void IEvtTrainningOkV1() {}
	virtual void IEvtTrainningFailV1() {}
};
