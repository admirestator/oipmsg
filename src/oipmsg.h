#ifndef OIPMSG_H
#define OIPMSG_H

#include <QThread>
#include <QList>
#include <QByteArray>

#include "udpserver.h"
#include "host.h"
#include "screenshot.h"

namespace oipmsg {
    class Oipmsg;
};

class Oipmsg : public QThread
{
    Q_OBJECT
public:
    Oipmsg();
    ~Oipmsg();

    Udpserver *udpServer;
    Host *hosts;

    void run();

private:
    quint16 defaultUdpPort;
    quint16 udpPort;

    void buildConnection();

public slots:
    bool addNewUser(const QHostAddress& ipaddr, const QByteArray &packet);
    bool delUser(const QString &username);
};

#endif // OIPMSG_H
