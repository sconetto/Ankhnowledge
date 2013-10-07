#ifndef IPADRESS_H_
#define IPADRESS_H_


#include <iostream>

#ifdef WIN32
    #include <"SDL_net.h">
    #include <"windows.h">
#else
    #include <SDL/SDL_net.h>
#endif

using namespace std;

class IPAddress {
  private:
    IPaddress adress; //the IPaddress structure
  public:
    IPAddress();
    IPAddress(Uint16 port); //create and associate a port to the instance
    IPAddress(string host, Uint16 port); //create and associate a port and a host to the instance
    void SetIp(IPaddress sdlIP); //set a IpAddress object from an existing SDL IPaddress
    bool Ok() const; //True if the object have a port and a host associated to it
    IPaddress GetIpAddress() const; //return a SDL_net IPaddress structure
    Uint32 GetHost() const; //return the host
    Uint16 GetPort() const; //return the port
};

#endif

