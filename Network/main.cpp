#include <iostream>
#include "SDLNetwork.h"
#include "NetMessage.h"
#include "Socket.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

void client();
void server();

int main()
{
	char op;

	cout << "1 - server\n2 - client" << endl;
	cin >> op;

	switch(op)
	{
		case '1':
			server();
			break;
		case '2':
			client();
			break;
	}
}

void client()
{
	ClientSocket* tcpclient = NULL;
    IPAddress* remoteip = NULL;
    //NetMessage message;

    bool connected = false;

    tcpclient = new ClientSocket();
    remoteip = new IPAddress("192.168.254.3", 1234);

    connected = tcpclient->Connect(*remoteip);

    cout << "Client: " << connected;

    delete remoteip;
 	delete tcpclient;
}

void server()
{
	HostSocket *tcplistener = NULL;
	ClientSocket *tcpclient = NULL;
 	bool connected = false;

 	tcplistener = new HostSocket(1234);
 	if(!tcplistener->Ok())
 	{
 		cout << "Problema com listener do Server" << endl;
 		exit(-1);
 	}

 	tcpclient = new ClientSocket();
 	connected = tcplistener->Accept (*tcpclient);

	cout << "Host: " << connected;

 	//char info = "1";

 	delete tcpclient;
 	delete tcplistener;
}