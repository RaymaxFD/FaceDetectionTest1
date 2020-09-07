
#pragma once

#include <IBase.h>
#include <media/IMedia.h>

class IChannelDisp_V1 : public IBase, public IMedia
{
public:
	enum _eViewMode
	{
		e4,
		e16,
		e32,
		e64,
	};

public:
	virtual void SetViewMode(_eViewMode eMode) = 0;
	virtual void Init(HWND hWnd) = 0;
	virtual void Update() = 0;
	virtual void OnSize() = 0;
	virtual void OnDestroy() = 0;
};