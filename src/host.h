#ifndef HOST_H
#define HOST_H

#include <QDate>
#include <QHash>
#include <QList>
#include <QHostAddress>

#include "user.h"

namespace host {
    class Host;
};


class Host
{
public:
    Host();
    virtual ~Host();

    QHash <QString, User> userList;

private:
    // default max client
    quint16 max_client;
    quint16 total_client;

public slots:
    quint16 count() const;

    bool addHost(const QHostAddress &ipaddr,
                 const QByteArray &packet);

    bool delHost(const QString &username);



};

#endif // HOST_H
