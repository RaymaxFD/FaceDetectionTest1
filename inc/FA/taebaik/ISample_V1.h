#pragma once


#include <IBase.h>

class ISample_V1 : public IBase
{
public:
	virtual void	OnProcess() = 0;
};