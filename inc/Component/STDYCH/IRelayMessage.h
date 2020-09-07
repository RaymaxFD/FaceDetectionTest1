

#pragma once

#include <IWorker.h>

class IRelayMessage : public IWorker
{
public:
	virtual bool RelayMessage(HWND hWndFrom, UINT message, WPARAM wParam = 0, LPARAM lParam = 0) = 0;
};
