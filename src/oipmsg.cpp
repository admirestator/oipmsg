#include "oipmsg.h"

Oipmsg::Oipmsg()
{
    defaultUdpPort = IPMSG_DEFAULT_PORT;

    // choose default port or customered port to use
    udpPort = defaultUdpPort;

    udpServer = new Udpserver(selfUserInfo, udpPort);
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

void Oipmsg::getSelfUserInfo (User &user)
{
    StringList envVariables;
    envVariables << "USER.*" << "HOSTNAME.*";

    //系统中关于环境变量的信息存在environment中
    // can use new code for QProcessEnvironment
    QStringList environment = QProcess::systemEnvironment();

    int index = environment.indexOf(QRegExp("USER.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            username = stringList.at(1);
        }
    }

    index = environment.indexOf(QRegExp("HOSTNAME.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            hostname = stringList.at(1);
        }
    }

    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
    QNetworkInterface interface=list.at(1);
    QString hardwareAddress=interface.hardwareAddress();

}

void Oipmsg::updateSelfUserInfo(const User &user)
{

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

    // send user info

    /*
    QObject::connect(mainWin, SIGNAL(quitApp()),
                     app, SLOT(quit()));
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
                     */
}


bool Oipmsg::addUser(const QHostAddress &ipaddr, const QByteArray &packet)
{
    if (hosts->addHost(ipaddr, packet)) {
        //emit alluser(hosts->userList);

        //Refresh ui widget
        mainWin->buildItems(hosts);
        return true;
    }

    return false;
}

bool Oipmsg::delUser(const QString& username)
{
    if (hosts->delHost(username)) {
        emit alluser(hosts->userList);
        // refresh ui widget
        mainWin->buildItems(hosts);
        return true;
    }

    return flase;
}
