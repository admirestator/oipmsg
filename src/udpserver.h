#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QThread>
#include <QObject>

#include "protocol.h"
#include "udpclient.h"

namespace udpserver {
    class Udpserver;
};


class Udpserver : public QThread
{
    Q_OBJECT
public:
    Udpserver(quint16 &udpport);
    virtual ~Udpserver();

    QUdpSocket *udpSocket;
    Protocol *protocolObj;

    void run();

private:
    quint16 port;
    bool bindPort();
    Udpclient *udpClient;

    bool sendcmdBrEntry();

//private slots:
public slots:
    void dataReceived();
};

#endif // UDPCOMM_H
