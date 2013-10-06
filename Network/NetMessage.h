#ifndef SDLNETWORK_H_
#define SDLNETWORK_H_

#include <iostream>
#include <string>
#include <cstring>
#include "SDLNetwork.SDLNETWORK_H_"

#ifdef WIN32
	#include <"SDL_net.h">
	#include <"windows.h">
#else
	#include <SDL/SDL_net.h>
#endif

typedef char charbuf[256];

class NetMessage
{
	public:
		NetMessage();
		virtual int NumToLoad(); //Indicates how many bytes may have to be loaded into the instance
		virtual int NumToUnLoad(); //Indicates how many bytes may have to be downloaded into the instance
		void LoadBytes(charbuf& input, int size);
		void UnLoadBytes(charbuf& output);
		void finish(); //Set the objects state to full -> No more data to be load


	protected:
		charbuf buffer;
		enum bufferStates
		{
			EMPTY,
			READING,
			WRINTING,
			FULL
		};

		bufferStates state;

		void reset(); //Change message states to empty
};