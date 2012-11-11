//#include <QTranslation>
#include <QThread>
#include "udpserver.h"

Udpserver::Udpserver(quint16 &udpport)
{
    port = udpport;
    udpSocket = new QUdpSocket();
    protocolObj = new Protocol();


    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));

}

Udpserver::~Udpserver()
{
    delete udpSocket;
    delete protocolObj;
}

bool Udpserver::bindPort ()
{
    if (!udpSocket->bind(QHostAddress::LocalHost, port)) {
        qDebug() << (QObject::tr("Bind UDP Port Error!"));

        // connect to the main windows and have a choice to
        // rebind a different port
        return false;
    }

    return true;
}

void Udpserver::processPendingDatagrams()
{
    qDebug() << "hello google";

}
