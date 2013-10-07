#include "IPAddress.h"
#include "NetWorkExceptions.h"

IPAddress::IPAddress()
{
    adress.host = 0;
    adress.port = 0;
}

IPAddress::IPAddress(Uint16 port)
{
    if(SDLNet_ResolveHost(&adress, NULL, port) < 0)
    {
        adress.host = 0;
        adress.port = 0;
        throw ResolveHostException(-1, "Impossible to resolve host");
    }
}
 
 
IPAddress::IPAddress (std::string host, Uint16 port)
{
    if (SDLNet_ResolveHost(&adress, host.c_str(), port) < 0)
    {
        adress.host = 0;
        adress.port = 0;
        throw ResolveHostException(-1, "Impossible to resolve host");
    }
}
 
bool IPAddress::Ok() const
{
    return !(adress.port == 0);
}
 
void IPAddress::SetIp (IPaddress sdlIP)
{
    adress = sdlIP;
}
 
IPaddress IPAddress::GetIpAddress() const
{
    return adress;
}
 
Uint32 IPAddress::GetHost() const
{
    return adress.host;
}
 
Uint16 IPAddress::GetPort() const
{
    return adress.port;
}