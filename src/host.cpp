#include "host.h"

Host::Host()
{
    hostList.clear();
}


Host::~Host()
{

}

bool Host::addHost(const QHostAddress& ipaddr, const QByteArray &packet)
{
    qDebug () << "add host";
    QList<QByteArray> argumentList = packet.split (':');
    HostInfo tmp;

    tmp.userName = argumentList.at(2).data();
    tmp.hostName = argumentList.at(3).data();
    tmp.hostAddress = ipaddr;
    tmp.portNo = 2425;
    tmp.nickName = argumentList.at(5).data();
    tmp.groupName = "";
    tmp.alterName = "";
    tmp.hostStatus = 0;
    tmp.updateTime = QTime::currentTime();
    tmp.priority = 0;
    tmp.pubKey = "";
    tmp.pubKeyUpdated = false;

    displayHostInfo(tmp);
    hostList.append(tmp);
    return true;
}

void Host::displayHostInfo(const HostInfo &hostInfo)
{

    qDebug () << hostInfo.userName
              << hostInfo.hostName
              << hostInfo.portNo
              << hostInfo.hostAddress
              << hostInfo.nickName
              << hostInfo.groupName
              << hostInfo.alterName
              << hostInfo.hostStatus
              << hostInfo.updateTime
              << hostInfo.priority
              << hostInfo.pubKey
              << hostInfo.pubKeyUpdated;
}

bool Host::modifyHost(const HostInfo &hostInfo)
{
    const HostInfo tmp = hostInfo;
    return true;
}

bool Host::setPriority(const int &prioity)
{
    qDebug () << prioity;
    return true;
}

bool Host::setPubkey(const QString &pubkey)
{
    qDebug () << pubkey;
    return true;
}


bool Host::searchHost(const HostInfo &hostInfo)
{

    const HostInfo tmp = hostInfo;
    return true;
}


