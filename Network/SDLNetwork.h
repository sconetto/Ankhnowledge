#ifndef SDLNETWORK_H_
#define SDLNETWORK_H_

#include <iostream>
#include <string>
#include <cstring>

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

typedef char charbuf[256];

class SDLNetwork
{
	public:
		static bool InitializeNetwork();
		static void QuitNetwork();

	private:
		static void RunException(const string& message);
};

#endif
