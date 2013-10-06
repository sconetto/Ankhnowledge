#include <iostream>
#include "SDLNetwork.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

void SDLNetwork::RunException(const string& message)
{
    throw message;
}

bool SDLNetwork::InitializeNetwork()
{
    if (SDLNet_Init() < 0)
    {
        RunException("Initializing NetWork Exception" + (string) SDL_GetError());
        return false;
    }
    
    return true;
}

void SDLNetwork::QuitNetwork()
{
    SDLNet_Quit();
}