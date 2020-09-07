

#pragma once

#include <IBase.h>
#include <NCC/LOME/Packet.h>

class IPacketParse_V1 : public IBase
{
public:
	virtual bool Parse(BYTE (&ucInput)[LEN_PAD], int iLen) = 0;
};
