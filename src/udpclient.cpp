#include "udpclient.h"
#include <unistd.h>

Udpclient::Udpclient(quint16 &udpport)
{
    udpSocket = new QUdpSocket();
    protocolObj = new Protocol();
    port = udpport;

}

Udpclient::~Udpclient()
{
    delete udpSocket;
    delete protocolObj;
}
bool sendcmdNooperation()
{
    return true;
}


bool Udpclient::sendcmdBrEntry()
{
    qDebug() << "broad entry";
    QByteArray datagram = protocolObj->buildcmdBrEntry();
    while (1) {
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, port);
    qDebug() << datagram << port;
    sleep(60);
    }

    return true;
}


bool Udpclient::sendcmdBrExit()
{
    QByteArray cmdBrExit;
    return true;
}

bool Udpclient::sendcmdAnsentry()
{
    QByteArray cmdAnsentry;
    return true;
}

bool Udpclient::sendcmdBrAbsence()
{
    QByteArray cmdAbsence;
    return true;
}

bool Udpclient::sendcmdBrIsgetlist()
{
    QByteArray cmdIsgetlist;
    return true;
}

bool Udpclient::sendcmdOkgetlist()
{
    QByteArray cmdOkgetlist;
    return true;
}
bool Udpclient::sendcmdGetlist()
{
    QByteArray cmdGetlist;
    return true;
}

bool Udpclient::sendcmdAnslist()
{
    QByteArray cmdAnslist;
    return true;
}

bool Udpclient::sendcmdBrIsgetlist2()
{
    QByteArray cmdIsgetlist2;
    return true;
}

bool Udpclient::sendcmdSendmsg()
{
    QByteArray cmdSendmsg;
    return true;
}

bool Udpclient::sendcmdRecvmsg()
{
    QByteArray cmdRecvmsg;
    return true;
}

bool Udpclient::sendcmdReadmsg()
{
    QByteArray cmdReadmsg;
    return true;
}

bool Udpclient::sendcmdDelmsg()
{
    QByteArray cmdDelmsg;
    return true;
}

bool Udpclient::sendcmdAnsreadmsg()
{
    QByteArray cmdAnsreadmsg;
    return true;
}

bool Udpclient::sendcmdGetinfo()
{
    QByteArray cmdGetinfo;
    return true;
}

bool Udpclient::sendcmdSendinfo()
{
    QByteArray cmdSendinfo;
    return true;
}

bool Udpclient::sendcmdGetabsenceinfo()
{
    QByteArray cmdGetabsenceinfo;
    return true;
}

bool Udpclient::sendcmdSendabsenceinfo()
{
    QByteArray cmdSendabsenceinfo;
    return true;
}

bool Udpclient::sendcmdGetfiledata()
{
    QByteArray cmdGetfiledata;
    return true;
}

bool Udpclient::sendcmdReleasefiles()
{
    QByteArray cmdReleasefiles;
    return true;
}

bool Udpclient::sendcmdGetdirfiles()
{
    QByteArray cmdGetdirfiles;
    return true;
}

bool Udpclient::sendcmdGetpubkey()
{
    QByteArray cmdGetpubkey;
    return true;
}

bool Udpclient::sendcmdAnspubkey()
{
    QByteArray cmdAspubkey();
    return true;
}

