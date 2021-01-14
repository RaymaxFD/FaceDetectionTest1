

#pragma once

#include <IBase.h>
#include <NCC/LOME/Packet.h>

class IPacketGen_V1 : public IBase
{
public:
	virtual bool PacketGen(USHORT usCmd, BYTE* pParam, long lParam, BYTE* pPad, long& lPad) = 0;
};
