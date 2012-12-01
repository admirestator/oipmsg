#ifndef OIPMSG_H
#define OIPMSG_H

#include <QThread>
#include <QList>
#include <QByteArray>

#include "main_window.h"
#include "host.h"
#include "udpserver.h"
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

    void run();

private:
    // UI
    Screenshot *screenshot;
    MainWindow *mainWin;

    // tcp communication
    Udpserver *udpServer;
    Host *hosts;
    quint16 defaultUdpPort;
    quint16 udpPort;

    // build signals and slots
    void buildConnection();

signals:
    void newuser(const User &userinfo);
    void alluser(const QHash<QString, User> &allusers);

public slots:
    bool addUser(const QHostAddress& ipaddr, const QByteArray &packet);
    bool delUser(const QString &username);

};

#endif // OIPMSG_H
