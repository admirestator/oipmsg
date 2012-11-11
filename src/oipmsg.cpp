#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;
    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpServer = new Udpserver(udpPort);

}

Oipmsg::~Oipmsg()
{
    delete udpServer;
}


void Oipmsg::run()
{

    // set udp server
    udpServer->run ();

}
