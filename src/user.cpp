#include "user.h"

User::User()
{
    portNo = 2425;
    userStatus = 0;
    updateTime = QDate::currentDate();
    priority = 0;
    pubKeyUpdated = false;
}

User::User(const QString &username, const QString &hostname,
           const QHostAddress &hostaddr, const QString &nickname)
{
    userName = username;
    hostName = hostname;
    hostAddress = hostaddr;
    portNo = 2425;
    nickName = nickname;
    //groupName = "";
    //alterName = "";
    userStatus = 0;
    updateTime = QDate::currentDate();
    priority = 0;
    //pubKey = "";
    pubKeyUpdated = false;
}


User::~User()
{

}

//operator = ()
void User::displayHostInfo() const
{
    qDebug() << userName;
    qDebug() << hostName;
    qDebug() << hostAddress;
    qDebug() << nickName;
    qDebug() << portNo;
    qDebug() << groupName;
    qDebug() << alterName;
    qDebug() << userStatus;
    qDebug() << updateTime;
    qDebug() << priority;
    qDebug() << pubKey;
    qDebug() << pubKeyUpdated;
}

//-----------------------------------------------
bool User::setUserName(const QString &username)
{
    userName = username;
    return true;
}

bool User::setHostname(const QString &hostname)
{
    hostName = hostname;
    return true;

}
bool User::setHostAddress(const QHostAddress &hostaddr)
{
    hostAddress = hostaddr;
    return true;
}

bool User::setNickName(const QString &nickname)
{
    nickName = nickname;
    return true;
}

bool User::setPort(const quint16 &port)
{
    qDebug() << "port" << port;
    portNo = port;
    return true;
}

bool User::setGroup(const QString &group)
{
    qDebug() << "group" << group;
    groupName = group;
    return true;
}

bool User::setAlterName(const QString &altername)
{
    qDebug() << "alterName" << altername;
    alterName = altername;
    return true;
}

bool User::setUserStatus(const quint32 &status)
{
    qDebug() << "status" << status;
    userStatus = status;
    return true;
}

bool User::setUpdateTime()
{
    updateTime = QDate::currentDate();
    qDebug() << "updateTime" << updateTime;
    return true;
}

bool User::setPriority(const int &prioity)
{
    qDebug () << "prioty" << prioity;
    priority = prioity;
    return true;
}

bool User::setPubkey(const QString &pubkey)
{
    qDebug () << "pubkey" << pubkey;
    pubKey = pubkey;
    return true;
}

bool User::setPubkeyUpdated(bool &status)
{
    pubKeyUpdated = status;
    return true;
}

//-------------------------------------------------
QString User::getUserName() const
{
    return userName;
}

QString User::getHostName() const
{
    return hostName;
}

QHostAddress User::getHostAddress() const
{
    return hostAddress;
}

quint16 User::getPort() const
{
    return portNo;
}

QString User::getNickName() const
{
    return nickName;
}

QString User::getGroupName() const
{
    return groupName;
}

QString User::getAlterName() const
{
    return alterName;
}

quint32 User::getUserStatus() const
{
    return userStatus;
}

QDate User::getUpdateTime() const
{
    return updateTime;
}

int User::getPriority() const
{
    return priority;
}

QString User::getPubkey() const
{
    return pubKey;
}

bool User::getPubkeyUpdated() const
{
    return pubKeyUpdated;
}
