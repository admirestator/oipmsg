#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;

    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpServer = new Udpserver(udpPort);
    hosts = new Host();

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
    connect(udpServer, SIGNAL(signalBrEntry(const QHostAddress&,
                                            const QByteArray&)),
          this, SLOT(addNewUser(const QHostAddress&,
                                const QByteArray&)));

    // br_exit
    connect(udpServer, SIGNAL(signalBrExit(const QString&)),
          this, SLOT(delUser(const QString&)));

    // br_ansentry with new user
    connect(udpServer, SIGNAL(signalAnsentry(const QHostAddress&,
                                            const QByteArray&)),
          this, SLOT(addNewUser(const QHostAddress&,
                                const QByteArray&)));
}

bool Oipmsg::addNewUser(const QHostAddress &ipaddr, const QByteArray &packet)
{
    hosts->addHost(ipaddr, packet);
    return true;
}

bool Oipmsg::delUser(const QString& username)
{
    hosts->delHost(username);
    return true;
}
