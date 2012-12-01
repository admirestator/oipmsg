#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;

    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpServer = new Udpserver(udpPort);
    hosts = new Host();
    mainWin = new MainWindow();
    mainWin->show();
    buildConnection();
}

Oipmsg::~Oipmsg()
{
    delete screenshot;
    delete mainWin;
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


/*
bool buildConnection(const Oipmsg *oipmsgobj, const MainWindow *mainwinobj)
{
    QObject::connect(mainWin, SIGNAL(quitApp()),
                     app, SLOT(quit()));
    QObject::connect (oipmsgobj,
                      SIGNAL(alluser(const QHash <QString, User> &)),
                      mainwinobj,
                      SLOT(buildItems(const QHash <QString,User> &)));

    // send user info
    QObject::connect(mainwinobj,
                     SIGNAL(sendInfo(const QHostAddress&, const QString&)),
                     oipmsgobj->udpServer,
                     SLOT(sendcmdSendmsg(const QHostAddress&, const QString&)));

    // recv user info
    QObject::connect(oipmsgobj->udpServer,
                     SIGNAL(gotMsg(const QByteArray&)),
                     mainwinobj,
                     SLOT(recvMsg(const QByteArray&)));

    // emit refresh
    QObject::connect(mainwinobj, SIGNAL(refreshUser()),
                     oipmsgobj->udpServer, SLOT(sendcmdBrEntry()));

    return true;
}
*/

bool Oipmsg::addUser(const QHostAddress &ipaddr, const QByteArray &packet)
{
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
