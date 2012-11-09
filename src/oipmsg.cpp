#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    udpClient = new Udpclient();
    udpServer = new Udpserver();
}

Oipmsg::~Oipmsg()
{
    delete udpClient;
    delete udpServer;
}

