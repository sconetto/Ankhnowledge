#include "Socket.h"
#include "IPAddress.h"
#include "NetWorkExceptions.h"
#include "NetMessage.h"

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

ClientSocket::ClientSocket()
{
    Socket();
}
 
ClientSocket::ClientSocket(string host, Uint16 port)
{
    IPAddress remote (host.c_str(), port);
    
    if (!remote.Ok())
        socket = NULL;
    else
    {
        Socket();
        Connect(remote);
    }
}
 
bool ClientSocket::Connect(HostSocket& listenerSocket)
{
    return false;
}
 
bool ClientSocket::Connect(IPAddress& remote)
{
    TCPsocket clientSocket;
    IPaddress ip = remote.GetIpAddress();

    if((clientSocket = SDLNet_TCP_Open(&ip)))
    {
        SetSocket(clientSocket);
        return true;
    }
    else
        return false;
        // throw OpenSocketException(-1, SDLNet_GetError());
}
 
void ClientSocket::SetSocket(TCPsocket SDLSocket)
{
    Socket::SetSocket(SDLSocket);
    IPaddress* ips;

    if((ips = SDLNet_TCP_GetPeerAddress(socket)))
    {
        remoteIP.SetIp(*ips);
        Uint32 host = remoteIP.GetHost();
        Uint16 port = remoteIP.GetPort();
        cout << "Client connected: " << SDLNet_Read32(&host) << ' '
            << SDLNet_Read16 (&port) << endl;
    }
    else
        throw GetPeerAddressException(-1, SDLNet_GetError());
}
 
IPAddress ClientSocket::getIpAddress () const
{
    return remoteIP;
}
 
bool ClientSocket::Receive(NetMessage& data)
{
    if (socket == NULL)
        return false;
    
    charbuf buf;
 
    //Check if the instance can receive bytes, if it can, load the number of bytes specified by NumToLoad() virtual function
    while(data.NumToLoad() > 0)
    {
        if(SDLNet_TCP_Recv(socket, buf, data.NumToLoad()) > 0)
            data.LoadBytes (buf, data.NumToLoad());
        else
            return false;
    }

    data.finish();
    return true;
}
 
bool ClientSocket::Send(NetMessage& data)
{
    if (socket == NULL)
        return false;

    charbuf buf;
    int len;
 
//Check if the instance can send bytes, if it can, unload the number of bytes specified by NumToLoad() virtual function
    while ((len = data.NumToUnLoad()) > 0)
    {
        data.UnLoadBytes(buf);

        if (SDLNet_TCP_Send(socket, (void *)buf, len) < len)
        {
            //std::cerr << "SDLNet_TCP_Send: " << SDLNet_GetError() << std::endl;
            return false;
        }
    }

    return true;
}
 
void ClientSocket::OnReady() {}