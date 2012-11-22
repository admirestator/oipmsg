#include "host.h"

Host::Host()
{
    total_client = 0;
    userList.clear();
    max_client = 512;
}


Host::~Host()
{

}


quint16 Host::count() const
{
    return total_client;
}



bool Host::addHost(const QHostAddress& ipaddr,
                   const QByteArray &packet)
{

    //if (!usernew.getUserName().isEmpty())
    //    return false;

    QList<QByteArray> argumentList = packet.split (':');

    // if the user exists
    if (userList.find(argumentList.at(2).data()) != userList.end()) {
        //qDebug () << "User Exists!";
        return false;
    }

    total_client++;
    User tmp(argumentList.at(2), argumentList.at(3),
             ipaddr, argumentList.at(5));

    userList.insert(tmp.getUserName(), tmp);
    //usernew = tmp;
    //qDebug () << "Total Host" << total_client;

    return true;
}

bool Host::delHost(const QString &username)
{
    if (userList.find(username) != userList.end()) {
        qDebug () << "No User Exists!";
        return false;
    }

    userList.remove(username);
    total_client--;
    //emit delExistUser(username);

    qDebug() << "delHost" << total_client;
    return true;
}
