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

    qDebug () << packet;
    total_client++;
    User tmp(argumentList.at(2), argumentList.at(3),
             ipaddr, argumentList.at(5));

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
