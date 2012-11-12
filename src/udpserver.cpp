#include "udpserver.h"

Udpserver::Udpserver(quint16 &udpport)
{
    port = udpport;
    udpSocket = new QUdpSocket();
    protocolObj = new Protocol();

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(dataReceived()));
}

Udpserver::~Udpserver()
{
    delete udpSocket;
    delete protocolObj;
}

void Udpserver::run()
{
    if (!bindPort()) {
        qDebug("Can't bind port!");

        // change to new port or exit
        exit(-2);
    }

    // broadcast entry
    sendcmdBrEntry();
}

bool Udpserver::bindPort()
{
    if (!udpSocket->bind(port)) {
        qDebug() << (QObject::tr("Bind UDP Port Error!"));

        // connect to the main windows and have a choice to
        // rebind a different port
        return false;
    }

    return true;
}

void Udpserver::dataReceived()
{
    while (udpSocket->hasPendingDatagrams())
     {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         //udpSocket->readDatagram(datagram.data(), datagram.size());
         QHostAddress senderAddress;
         udpSocket->readDatagram(datagram.data(), datagram.size(), &senderAddress, &port);
         qDebug () << "Recv:" << senderAddress << datagram.data();
         handleCmd (datagram);
     }
}

// the main function the handle different packet
bool Udpserver::handleCmd (const QByteArray &packet)
{
    QList<QByteArray> argumentList = packet.split (':');
    qDebug () << argumentList << argumentList.at(0) << argumentList.at(1)
              << argumentList.at(2) << argumentList.at(3) << argumentList.at(4)
              << argumentList.at(5);


    //QByteArray cmd(argumentList.at (4));
    quint32 cmd = argumentList.at(4).toInt();

    switch (cmd) {
        case IPMSG_BR_ENTRY:
            qDebug () << "hd-br-entry";
            break;
        case IPMSG_BR_EXIT:
            break;
        case IPMSG_ANSENTRY:
        break;
        case IPMSG_BR_ABSENCE:
        break;
        case IPMSG_BR_ISGETLIST:
        break;
        case IPMSG_OKGETLIST:
        break;
        case IPMSG_GETLIST:
        break;
        case IPMSG_ANSLIST:
        break;
        case IPMSG_BR_ISGETLIST2:
        break;
        case IPMSG_SENDMSG:
        break;
        case IPMSG_RECVMSG:
        break;
        case IPMSG_READMSG:
        break;
        case IPMSG_DELMSG:
        break;
        case IPMSG_ANSREADMSG:
        break;
        case IPMSG_GETINFO:
        break;
        case IPMSG_SENDINFO:
        break;
        case IPMSG_GETABSENCEINFO:
        break;
        case IPMSG_SENDABSENCEINFO:
        break;
        case IPMSG_GETFILEDATA:
        break;
        case IPMSG_RELEASEFILES:
        break;
        case IPMSG_GETDIRFILES:
        break;
        case IPMSG_GETPUBKEY:
        break;
        case IPMSG_ANSPUBKEY:
        break;
        case IPMSG_NOOPERATION:
        break;
        default:
        break;

    }
    return true;
}

bool Udpserver::sendcmdNooperation()
{
    qDebug() << "broad Nooperation";
    QByteArray datagram = protocolObj->buildcmdBrEntry();
    if (udpSocket->writeDatagram(datagram.data(),
                                 datagram.size(),
                                 QHostAddress::Broadcast,
                                 port) != datagram.size()) {
        qDebug() << "Broad Entry Error!";
    }

    return true;
}

bool Udpserver::sendcmdBrEntry()
{
    qDebug() << "broad entry";
    QByteArray datagram = protocolObj->buildcmdBrEntry();
    if (udpSocket->writeDatagram(datagram.data(),
                                 datagram.size(),
                                 QHostAddress::Broadcast,
                                 port) != datagram.size()) {
        qDebug() << "Broad Entry Error!";
    }

    return true;
}



bool Udpserver::sendcmdBrExit()
{
    QByteArray cmdBrExit;
    return true;
}

bool Udpserver::sendcmdAnsentry()
{
    QByteArray cmdAnsentry;
    return true;
}

bool Udpserver::sendcmdBrAbsence()
{
    QByteArray cmdAbsence;
    return true;
}

bool Udpserver::sendcmdBrIsgetlist()
{
    QByteArray cmdIsgetlist;
    return true;
}

bool Udpserver::sendcmdOkgetlist()
{
    QByteArray cmdOkgetlist;
    return true;
}
bool Udpserver::sendcmdGetlist()
{
    QByteArray cmdGetlist;
    return true;
}

bool Udpserver::sendcmdAnslist()
{
    QByteArray cmdAnslist;
    return true;
}

bool Udpserver::sendcmdBrIsgetlist2()
{
    QByteArray cmdIsgetlist2;
    return true;
}

bool Udpserver::sendcmdSendmsg()
{
    QByteArray cmdSendmsg;
    return true;
}

bool Udpserver::sendcmdRecvmsg()
{
    QByteArray cmdRecvmsg;
    return true;
}

bool Udpserver::sendcmdReadmsg()
{
    QByteArray cmdReadmsg;
    return true;
}

bool Udpserver::sendcmdDelmsg()
{
    QByteArray cmdDelmsg;
    return true;
}

bool Udpserver::sendcmdAnsreadmsg()
{
    QByteArray cmdAnsreadmsg;
    return true;
}

bool Udpserver::sendcmdGetinfo()
{
    QByteArray cmdGetinfo;
    return true;
}

bool Udpserver::sendcmdSendinfo()
{
    QByteArray cmdSendinfo;
    return true;
}

bool Udpserver::sendcmdGetabsenceinfo()
{
    QByteArray cmdGetabsenceinfo;
    return true;
}

bool Udpserver::sendcmdSendabsenceinfo()
{
    QByteArray cmdSendabsenceinfo;
    return true;
}

bool Udpserver::sendcmdGetfiledata()
{
    QByteArray cmdGetfiledata;
    return true;
}

bool Udpserver::sendcmdReleasefiles()
{
    QByteArray cmdReleasefiles;
    return true;
}

bool Udpserver::sendcmdGetdirfiles()
{
    QByteArray cmdGetdirfiles;
    return true;
}

bool Udpserver::sendcmdGetpubkey()
{
    QByteArray cmdGetpubkey;
    return true;
}

bool Udpserver::sendcmdAnspubkey()
{
    QByteArray cmdAspubkey();
    return true;
}


