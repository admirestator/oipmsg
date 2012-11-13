#ifndef HOST_H
#define HOST_H

#include <QTime>
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
    QTime	     updateTime;
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
    ~Host();

    QList<HostInfo> hostList;

public slots:
    bool addHost(const QHostAddress &ipaddr, const QByteArray &packet);
    void displayHostInfo(const HostInfo &hostInifo);
    bool modifyHost(const HostInfo &hostInfo);
    bool setPriority(const int &prioity);
    bool setPubkey(const QString &pubkey);
    bool searchHost(const HostInfo &hostInfo);

};

#endif // HOST_H
