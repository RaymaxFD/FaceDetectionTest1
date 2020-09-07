#pragma once

#include <IBaseDll.h>
#include <IBaseGUID.h>
#include <IV_Macro.h>

#include <Component/Socket/ISockClient.h>
#include <Component/Socket/ISockServer.h>
#include <Component/Socket/ISockPing.h>
#include <Component/Socket/ISockNetworkSearch.h>
#include <Component/Socket/ISockUtil.h>

class CSocketIV
{
public:
	CSocketIV()
		: m_hInstSocket(NULL)
	{}
	~CSocketIV() {}

private:
	HINSTANCE m_hInstSocket;

public:
	ISockClient* _GetISockClient()
	{
		IMPLEMENT_IBASE;

		ISockClient* pI;
		IV_GET_IF(m_hInstSocket, ID_DLL_SOCKET, ID_SOCKET_CLIENT, ISockClient, pI);

		return pI;
	}
	ISockServer* _GetISockServer()
	{
		IMPLEMENT_IBASE;

		ISockServer* pI;
		IV_GET_IF(m_hInstSocket, ID_DLL_SOCKET, ID_SOCKET_SERVER, ISockServer, pI);

		return pI;
	}
	ISockPing* _GetISockPing()
	{
		IMPLEMENT_IBASE;

		ISockPing* pI;
		IV_GET_IF(m_hInstSocket, ID_DLL_SOCKET, ID_SOCKET_PING, ISockPing, pI);

		return pI;
	}
	ISockNetworkSearch* _GetISockNS()
	{
		IMPLEMENT_IBASE;

		ISockNetworkSearch* pI;
		IV_GET_IF(m_hInstSocket, ID_DLL_SOCKET, ID_SOCKET_NETWORK_SEARCH, ISockNetworkSearch, pI);

		return pI;
	}
	ISockUtil* _GetISockUtil()
	{
		IMPLEMENT_IBASE;

		ISockUtil* pI;
		IV_GET_IF(m_hInstSocket, ID_DLL_SOCKET, ID_SOCKET_UTIL, ISockUtil, pI);

		return pI;
	}
};
