#include "udpserver.h"

Udpserver::Udpserver(quint16 &udpport)
{
    port = udpport;
    udpSocket = new QUdpSocket();
    udpClient = new Udpclient(port);
    protocolObj = new Protocol();

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(dataReceived()));
}

Udpserver::~Udpserver()
{
    delete udpSocket;
    delete udpClient;
    delete protocolObj;
}

void Udpserver::run()
{
    if (!bindPort()) {
        qDebug("Can't bind port!");
        exit(-2);
    }

    // broadcast entry
    udpClient->sendcmdBrEntry();
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

void Udpserver::dataReceived()
{
    qDebug() << "hello google";
    while (udpSocket->hasPendingDatagrams())
     {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         udpSocket->readDatagram(datagram.data(), datagram.size());

         qDebug () << datagram.data();
     }
}
