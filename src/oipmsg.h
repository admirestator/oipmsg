#ifndef OIPMSG_H
#define OIPMSG_H

#include <QThread>
#include <QList>

#include "udpserver.h"
#include "udpclient.h"
#include "host.h"

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

    QList<Host> userList;

};

#endif // OIPMSG_H
