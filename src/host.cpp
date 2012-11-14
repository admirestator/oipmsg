#include "host.h"

Host::Host()
{
    total_client = 0;
    hostList.clear();
    max_client = 512;
}


Host::~Host()
{

}


quint16 Host::count() const
{
    return total_client;
}



bool Host::addHost(const QHostAddress& ipaddr, const QByteArray &packet)
{

    QList<QByteArray> argumentList = packet.split (':');

    // if the user exists
    if (hostList.find(argumentList.at(2).data()) != hostList.end()) {
        qDebug () << "User Exists!";
        return false;
    }

    total_client++;
    HostInfo tmp;

    tmp.userName = argumentList.at(2).data();
    tmp.hostName = argumentList.at(3).data();
    tmp.hostAddress = ipaddr;
    tmp.portNo = 2425;
    tmp.nickName = argumentList.at(5).data();
    tmp.groupName = "";
    tmp.alterName = "";
    tmp.hostStatus = 0;
    tmp.updateTime = QDate::currentDate();
    tmp.priority = 0;
    tmp.pubKey = "";
    tmp.pubKeyUpdated = false;

    displayHostInfo(tmp);
    hostList.insert(tmp.userName, tmp);

    qDebug () << "addHost" << total_client;
    return true;
}

bool Host::delHost(const QString &username)
{
    if (hostList.find(username) != hostList.end()) {
        qDebug () << "No User Exists!";
        return false;
    }

    hostList.remove(username);
    total_client--;
    qDebug() << "delHost" << total_client;
    return true;
}

void Host::displayHostInfo()
{

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


bool Host::setPort(const QString &username, const quint16 &port)
{
    qDebug() << "port" << port;
    hostList[username].portNo = port;
    return true;
}

bool Host::setGroup(const QString &username, const QString &group)
{
    qDebug() << "group" << group;
    hostList[username].groupName = group;
    return true;
}

bool Host::setAlterName(const QString &username, const QString &alterName)
{
    qDebug() << "alterName" << alterName;
    hostList[username].alterName = alterName;
    return true;
}

bool Host::setHostStatus(const QString &username, const quint32 &status)
{
    qDebug() << "status" << status;
    hostList[username].hostStatus = status;
    return true;
}

bool Host::setUpdateTime(const QString &username)
{
    hostList[username].updateTime = QDate::currentDate();
    qDebug() << "updateTime" << hostList[username].updateTime;
    return true;
}

bool Host::setPriority(const QString &user, const int &prioity)
{
    qDebug () << "prioty" << prioity;
    hostList[user].priority = prioity;
    return true;
}

bool Host::setPubkey(const QString &user, const QString &pubkey)
{
    qDebug () << "pubkey" << pubkey;
    hostList[user].pubKey = pubkey;
    return true;
}
