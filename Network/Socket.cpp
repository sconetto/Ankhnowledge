#include "Socket.h"
#include "NetWorkExceptions.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

Socket::Socket()
{
	socket = NULL;
	set = SDLNet_AllocSocketSet(1);
}

Socket::~Socket()
{
	if(!(socket == NULL))
	{
		SDLNet_TCP_DelSocket(set, socket);
		SDLNet_FreeSocketSet(set);
		SDLNet_TCP_Close(socket);
	}

}

void Socket::SetSocket (TCPsocket SDLSocket)
{
	if(!(socket == NULL))
	{
		SDLNet_TCP_DelSocket(set, socket);
		SDLNet_TCP_Close(socket);
	}

	socket = SDLSocket;
	if(SDLNet_TCP_AddSocket(set, socket) == -1)
	{
		socket = NULL;
		throw AddSocketException(-1, SDLNet_GetError());
	}
}

bool Socket::Ok() const
{
	return !(socket == NULL);
}

bool Socket::Ready() const
{
	bool ready = false;
	int numReady = SDLNet_CheckSockets(set, 0);

	if(numReady == -1)
		throw CheckSocketException(-1, SDLNet_GetError());
	else
		if(numReady)
			ready = SDLNet_SocketReady(socket);

	return ready;
}

void Socket::OnReady(){}