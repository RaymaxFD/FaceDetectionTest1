
#pragma once

#include <IBase.h>

class IMouse : public IBase
{
public:
	virtual void Click(int iX, int iY) = 0;
};