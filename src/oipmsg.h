#ifndef OIPMSG_H
#define OIPMSG_H

#include <QThread>
#include "udpserver.h"
#include "udpclient.h"

class Oipmsg : public QThread
{
public:
    Oipmsg();
    virtual ~Oipmsg();

    Udpclient *udpClient;
    Udpserver *udpServer;

    void run();

private:
    quint16 defaultUdpPort;
    quint16 udpPort;

};

#endif // OIPMSG_H
