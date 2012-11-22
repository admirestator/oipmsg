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
          this, SLOT(addUser(const QHostAddress&,
                                const QByteArray&)));

    // br_exit
    connect(udpServer, SIGNAL(signalBrExit(const QString&)),
          this, SLOT(delUser(const QString&)));

    // br_ansentry with new user
    connect(udpServer, SIGNAL(signalAnsentry(const QHostAddress&,
                                            const QByteArray&)),
          this, SLOT(addUser(const QHostAddress&,
                                const QByteArray&)));

}

bool Oipmsg::addUser(const QHostAddress &ipaddr, const QByteArray &packet)
{
    //QList<QByteArray> argumentList = packet.split (':');
    /*
    User tmp(argumentList.at(2), argumentList.at(3),
             ipaddr, argumentList.at(5));
             */

    if (hosts->addHost(ipaddr, packet)) {
        emit alluser(hosts->userList);
        return true;
    }
    return false;
}

bool Oipmsg::delUser(const QString& username)
{
    hosts->delHost(username);
    emit alluser(hosts->userList);
    return true;
}
