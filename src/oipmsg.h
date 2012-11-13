#ifndef OIPMSG_H
#define OIPMSG_H

#include <QThread>
#include <QList>
#include <QByteArray>

#include "udpserver.h"
//#include "host.h"

namespace oipmsg {
    class Oipmsg;
};

class Oipmsg : public QThread
{
public:
    Oipmsg();
    virtual ~Oipmsg();

    Udpserver *udpServer;
    Host *hosts;

    void run();

private:
    quint16 defaultUdpPort;
    quint16 udpPort;

    void buildConnection();

};

#endif // OIPMSG_H
