#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QObject>
#include "protocol.h"

namespace udpserver {
    class Udpserver;
};


class Udpserver : QObject
{
    Q_OBJECT
public:
    Udpserver(quint16 &udpport);
    virtual ~Udpserver();

    QUdpSocket *udpSocket;
    Protocol *protocolObj;

    bool bindPort();

private:
    quint16 port;

private slots:
    void processPendingDatagrams();
};

#endif // UDPCOMM_H
