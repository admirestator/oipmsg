#ifndef HOST_H
#define HOST_H

#include <QTime>
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

    QList<Host> hostList;

public slots:
    bool addHost(const QByteArray &packet);
    bool modifyHost(const HostInfo &hostInfo);
    bool searchHost(const HostInfo &hostInfo);

};

#endif // HOST_H
