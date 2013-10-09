#include "Socket.h"
#include "IPAddress.h"
#include "NetWorkExceptions.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;


HostSocket::HostSocket (IPAddress& ip)
{
	Socket();
	IPaddress ipHost = ip.GetIpAddress();

	if(!(socket = SDLNet_TCP_Open(&ipHost)))
	{
		SDLNet_FreeSocketSet(set);
		throw OpenSocketException(-1, SDLNet_GetError());
	}
}

HostSocket::HostSocket (Uint16 port)
{
	IPAddress ipListener (port);

	if(!ipListener.Ok())
		socket = NULL;
	else
	{
		Socket();
		IPaddress ipHost = ipListener.GetIpAddress();

		if(!(socket = SDLNet_TCP_Open(&ipHost)))
		{
			SDLNet_FreeSocketSet(set);
			throw OpenSocketException(-1, SDLNet_GetError());
		}
	}
}

bool HostSocket::Accept (ClientSocket& clientSocket)
{
	TCPsocket client;
	
	if((client = SDLNet_TCP_Accept(socket)))
	{
		clientSocket.SetSocket(client);
		return true;
	}

	return false;
}

void HostSocket::OnReady(){}