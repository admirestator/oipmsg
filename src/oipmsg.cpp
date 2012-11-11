#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;
    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpClient = new Udpclient(udpPort);
    udpServer = new Udpserver(udpPort);

}

Oipmsg::~Oipmsg()
{
    delete udpClient;
    delete udpServer;
}


void Oipmsg::run()
{

    // set udp server
    //udpServer->bindPort ();
    udpServer->run ();
    // broadcast entry
    //udpClient->sendcmdBrEntry();

}
