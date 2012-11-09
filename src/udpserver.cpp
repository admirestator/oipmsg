//#include <QTranslation>
#include <QThread>
#include "udpserver.h"

Udpserver::Udpserver()
{
    udpSocket = new QUdpSocket();
    protocolObj = new Protocol();
    defaultUdpPort = IPMSG_DEFAULT_PORT;


    // choose default port or customered port to use
    udpPort = defaultUdpPort;


    if (!udpSocket->bind(QHostAddress::LocalHost, udpPort)) {
        qDebug() << (QObject::tr("Bind UDP Port Error!"));

        // connect to the main windows and have a choice to
        // rebind a different port
    }

    //connect(udpSocket, SIGNAL(readyRead()),
    //        this, SLOT(readPendingDatagrams()));

}

Udpserver::~Udpserver()
{
    delete udpSocket;
    delete protocolObj;
}
