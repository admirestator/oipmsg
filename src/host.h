#ifndef HOST_H
#define HOST_H

#include <QTime>

class Host
{
public:
    Host();

    QString userName;
    QString hostName;
    quint32 	addr;
    quint16	portNo;
    QString	nickName;
    QString 	groupName;
    QString 	alterName;
    quint32 	hostStatus;
    QTime	updateTime;
    int		priority;
    QString	pubKey;
    bool 	pubKeyUpdated;

};

#endif // HOST_H
