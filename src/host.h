#ifndef HOST_H
#define HOST_H

#include <QDate>
#include <QHash>
#include <QList>
#include <QHostAddress>

typedef struct host_t {
    QString      userName;
    QString      hostName;
    QHostAddress hostAddress;
    quint16	     portNo;
    QString	     nickName;
    QString     	 groupName;
    QString 	     alterName;
    quint32 	     hostStatus;
    QDate	     updateTime;
    int		     priority;
    QString	     pubKey;
    bool 	     pubKeyUpdated;
} HostInfo;


namespace host {
    class Host;
};


class Host
{
public:
    Host();
    virtual ~Host();

    QHash <QString, HostInfo> hostList;

private:
    // default max client
    quint16 max_client;
    quint16 total_client;

public slots:
    quint16 count() const;
    void displayHostInfo();
    void displayHostInfo(const HostInfo &hostInfo);

    bool addHost(const QHostAddress &ipaddr, const QByteArray &packet);
    bool delHost(const QString &username);

    bool setPort(const QString &username, const quint16 &port);
    bool setGroup(const QString &username, const QString &group);
    bool setAlterName(const QString &username, const QString &alterName);
    bool setHostStatus(const QString &username, const quint32 &status);
    bool setUpdateTime(const QString &username);
    bool setPriority(const QString &username, const int &prioity);
    bool setPubkey(const QString &username, const QString &pubkey);

};

#endif // HOST_H
