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

public slots:
    bool addUser(const QHostAddress& ipaddr, const QByteArray &packet);
    bool delUser(const QString &username);

signals:
    void newuser(const User &userinfo);
    void alluser(const QHash<QString, User> &allusers);

private slots:
    //Update self user info
    bool getSelfUserInfo();
    void updateSelfUserInfo(const User &userinfo);

private:
    //User info
    User selfUserInfo;
    Host *hosts;

    //UI Widget
    MainWindow *mainWin;
    Screenshot *screenshot;

    //Tcp communication
    quint16 defaultUdpPort;
    quint16 udpPort;
    Udpserver *udpServer;

    //Build signals and slots
    void buildConnection();
};

#endif // OIPMSG_H
