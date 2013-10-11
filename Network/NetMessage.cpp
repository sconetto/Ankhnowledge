#include <iostream>
#include "SDLNetwork.h"
#include "NetMessage.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif


NetMessage::NetMessage()
{
    reset();
}
 
void NetMessage::reset()
{
    for (int i = 0; i < 256; i++)
        buffer[i] = 0;
    state = EMPTY;
}
 
void NetMessage::finish()
{
    if (state == READING)
        state = FULL;
}
 
int NetMessage::NumToLoad()
{
    if (state == EMPTY)
        return 255;
    else
        return 0;
}
 
int NetMessage::NumToUnLoad()
{
    if (state == FULL)
        return strlen(buffer) + 1;
    else
        return 0;
}
 
void NetMessage::LoadBytes(charbuf& input, int size)
{
    for (int i = 0; i < size; i++)
        buffer[i] = input[i];
    state = READING;
}
 
void NetMessage::UnLoadBytes(charbuf& output)
{
    for (int i = 0; i < this->NumToUnLoad(); i++)
        output[i] = buffer[i];
    reset();
}