#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;

    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpServer = new Udpserver(udpPort);

    buildConnection();
}

Oipmsg::~Oipmsg()
{
    delete udpServer;
    delete hosts;
}


void Oipmsg::run()
{

    // set udp server
    udpServer->run ();

}

void Oipmsg::buildConnection()
{
    // br_entry with new user
    connect(udpServer, SIGNAL(signalBrEntry(const QByteArray&)),
          this, SLOT(addNewUser(const QByteArray&)));
}

bool Oipmsg::addNewUser(const QByteArray &packet)
{
    hosts->addHost(packet);
    return true;
}
