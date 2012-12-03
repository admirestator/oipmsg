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

bool Oipmsg::getSelfUserInfo ()
{
    QStringList envVariables;
    envVariables << "USER.*" << "HOSTNAME.*";

    //系统中关于环境变量的信息存在environment中
    // can use new code for QProcessEnvironment
    QStringList environment = QProcess::systemEnvironment();

    int index = environment.indexOf(QRegExp("USER.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            selfUserInfo.setUserName (stringList.at(1));
        }
    }

    index = environment.indexOf(QRegExp("HOSTNAME.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            selfUserInfo.setUserName (stringList.at(1));
        }
    }

    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
    QNetworkInterface interface=list.at(1);
    QString hardwareAddress=interface.hardwareAddress();

    return true;
}


void Oipmsg::updateSelfUserInfo(const User &userinfo)
{
    selfUserInfo = userinfo;
}


void Oipmsg::buildConnection()
{
    // Br_entry with new user
    connect(udpServer, SIGNAL(signalBrEntry(const QHostAddress&,
                                            const QByteArray&)),
            this, SLOT(addUser(const QHostAddress&,
                               const QByteArray&)));

    // Br_exit
    connect(udpServer, SIGNAL(signalBrExit(const QString&)),
          this, SLOT(delUser(const QString&)));

    // Br_ansentry with new user
    connect(udpServer, SIGNAL(signalAnsentry(const QHostAddress&,
                                            const QByteArray&)),
          this, SLOT(addUser(const QHostAddress&,
                             const QByteArray&)));

    // Send user msg
    connect(mainWin, SIGNAL(sendMsgInfo(const QHostAddress&, const QString&)),
            udpServer, SLOT(sendcmdSendmsg(const QHostAddress&, const QString&)));

    // Recv user msg
    connect(udpServer, SIGNAL(recvMsg(const QByteArray&)),
            mainWin, SLOT(recvMsg(const QByteArray&)));

    // emit refresh
    connect(mainWin, SIGNAL(refreshUser()),
            udpServer, SLOT(sendcmdBrEntry()));
}


bool Oipmsg::addUser(const QHostAddress &ipaddr, const QByteArray &packet)
{
    if (hosts->addHost(ipaddr, packet)) {
        qDebug () << "adduser:" << packet;
        //Refresh ui widget
        mainWin->buildItems(hosts->userList);
        return true;
    }

    return false;
}

bool Oipmsg::delUser(const QString& username)
{
    if (hosts->delHost(username)) {
        // refresh ui widget
        mainWin->buildItems(hosts->userList);
        return true;
    }

    return false;
}
