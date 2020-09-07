

#pragma once

#include <IBase.h>

class IEncryption : public IBase
{
public:
	virtual bool Encryption(BYTE* pData, DWORD& dwData, BYTE* pPass, DWORD dwPass) = 0;
	virtual bool Decryption(BYTE* pData, DWORD& dwData, BYTE* pPass, DWORD dwPass) = 0;
};
