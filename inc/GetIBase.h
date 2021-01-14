
#pragma once

#include "ibase.h"

HINSTANCE OpenIBaseDll(TCHAR* pStrDllFilePath);
IBase* GetIBaseInterface(HINSTANCE hDll, GUID id);
void CloseIBaseDll(HINSTANCE hDll);
