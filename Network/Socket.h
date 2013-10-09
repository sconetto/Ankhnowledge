#ifndef SOCKET_H_
#define SOCKET_H_

#include <iostream>
#include "IPAddress.h"
#include "NetMessage.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

class Socket
{
	public:
		Socket();
	    virtual ~Socket();
	    virtual void SetSocket (TCPsocket SDLSocket); //set a Socket object from a existing SDL socket
	    bool Ok() const; //indicate if theres is a TCPsocket associated to the instance
	    bool Ready() const; //True if there are bytes ready to be read
	    virtual void OnReady(); //Check if there is any activity in the socket

	protected:
		TCPsocket socket;
    	SDLNet_SocketSet set;
};


class ClientSocket;

class HostSocket : public Socket {
	public:
		HostSocket (IPAddress& ip); //create and open a new socket, with an existing IPAddress object
		HostSocket (Uint16 port); //create and open a new socket with the desired port
		bool Accept (ClientSocket&); //set a client Socket object after listening to the port
		virtual void OnReady(); //pure virtual
};



class ClientSocket : public Socket {
	public:
		ClientSocket();
		ClientSocket(string host, Uint16 port);  //Create the object and connect to a host, in a given port
		bool Connect(IPAddress& remote); //make a connection to communicate with a remote host
		bool Connect(HostSocket& listenerSocket); //make a connection to communicate with a client
		void SetSocket(TCPsocket SDLSocket); //set a Socket object from an existing SDL_net socket
		IPAddress getIpAddress() const; //return a CIpAddress object associated to the remote host
		virtual void OnReady(); //pure virtual
		bool Receive(NetMessage& data); //receive data and load it into a NetMessage object
		bool Send(NetMessage& data); //send data from a NetMessage object

	private:
		IPAddress remoteIP;
};


#endif