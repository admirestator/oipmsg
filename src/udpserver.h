#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include "protocol.h"

namespace udpserver {
    class Udpserver;
};


class Udpserver : public QThread
{
public:
    Udpserver();
    virtual ~Udpserver();

private:
    QUdpSocket *udpSocket;
    quint16 defaultUdpPort;
    quint16 udpPort;
    Protocol *protocolObj;
};

#endif // UDPCOMM_H
