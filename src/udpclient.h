#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QUdpSocket>
#include <QThread>

#include "protocol.h"

namespace udpclient {
    class Udpclient;
};


class Udpclient : public QThread
{
public:
    Udpclient();
    ~Udpclient();

private:
    QUdpSocket *udpSocket;
    quint16 defaultUdpPort;
    quint16 udpPort;
    Protocol *protocolObj;
};

#endif // UDPCLIENT_H
