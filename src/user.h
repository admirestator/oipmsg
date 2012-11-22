#ifndef USER_H
#define USER_H

#include <QString>
#include <QHostAddress>
#include <QDate>

#include "protocol.h"

namespace user {
    class user;
}

class User
{
public:
    User();
    User(const QString &username, const QString &hostname,
         const QHostAddress &hostaddress, const QString &nickname);
    ~User();

    void displayHostInfo() const;

    bool setUserName(const QString &username);
    bool setHostname(const QString &hostname);
    bool setHostAddress(const QHostAddress &hostaddr);
    bool setPort(const quint16 &port = IPMSG_DEFAULT_PORT);
    bool setNickName(const QString &nickname);
    bool setGroup(const QString &group);
    bool setAlterName(const QString &altername);
    bool setUserStatus(const quint32 &status);
    bool setUpdateTime();
    bool setPriority(const int &prioity);
    bool setPubkey(const QString &pubkey);
    bool setPubkeyUpdated(bool &status);

    QString getUserName() const;
    QString getHostName() const;
    QHostAddress getHostAddress() const;
    quint16 getPort()const;
    QString getNickName() const;
    QString getGroupName() const;
    QString getAlterName() const;
    quint32 getUserStatus() const;
    QDate getUpdateTime() const;
    int getPriority() const;
    QString getPubkey() const;
    bool getPubkeyUpdated() const;

private:
    QString      userName;
    QString      hostName;
    QHostAddress hostAddress;
    quint16	     portNo;
    QString	     nickName;
    QString     	 groupName;
    QString 	     alterName;
    quint32 	     userStatus;
    QDate	     updateTime;
    int		     priority;
    QString	     pubKey;
    bool 	     pubKeyUpdated;

};

#endif // USER_H
