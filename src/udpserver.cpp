#include "udpserver.h"

Udpserver::Udpserver(quint16 &udpport)
{
    port = udpport;
    udpSocket = new QUdpSocket();
    protocolObj = new Protocol();

    buildConnection();
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


bool Udpserver::buildConnection()
{

    // socket ready to read
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    // no operation
    connect(this, SIGNAL(signalNooperation()), this, SLOT(processNooperation()));
    // broadcast new user online
    connect(this, SIGNAL(signalBrEntry(const QByteArray&)), this, SLOT(processBrEntry()));
    /*
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    connect(this, SIGNAL(), this, SLOT());
    */

    return true;
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
            emit signalBrEntry(packet);
            break;
        case IPMSG_BR_EXIT:
            emit signalBrExit();
            break;
        case IPMSG_ANSENTRY:
            emit signalAnsentry();
            break;
        case IPMSG_BR_ABSENCE:
            emit signalBrAbsence();
            break;
        case IPMSG_BR_ISGETLIST:
            emit signalBrIsgetlist();
            break;
        case IPMSG_OKGETLIST:
            emit signalOkgetlist();
            break;
        case IPMSG_GETLIST:
            emit signalGetlist();
            break;
        case IPMSG_ANSLIST:
            emit signalAnslist();
            break;
        case IPMSG_BR_ISGETLIST2:
            emit signalBrIsgetlist2();
            break;
        case IPMSG_SENDMSG:
            emit signalSendmsg();
            break;
        case IPMSG_RECVMSG:
            emit signalRecvmsg();
            break;
        case IPMSG_READMSG:
            emit signalReadmsg();
            break;
        case IPMSG_DELMSG:
            emit signalDelmsg();
            break;
        case IPMSG_ANSREADMSG:
            emit signalAnsreadmsg();
            break;
        case IPMSG_GETINFO:
            emit signalGetinfo();
            break;
        case IPMSG_SENDINFO:
            emit signalSendinfo();
            break;
        case IPMSG_GETABSENCEINFO:
            emit signalGetabsenceinfo();
            break;
        case IPMSG_SENDABSENCEINFO:
            emit signalSendinfo();
            break;
        case IPMSG_GETFILEDATA:
            emit signalGetfiledata();
            break;
        case IPMSG_RELEASEFILES:
            emit signalReleasefiles();
            break;
        case IPMSG_GETDIRFILES:
            emit signalGetdirfiles();
            break;
        case IPMSG_GETPUBKEY:
            emit signalGetpubkey();
            break;
        case IPMSG_ANSPUBKEY:
            emit signalAnspubkey();
            break;
        case IPMSG_NOOPERATION:
        default:
            emit signalNooperation();
            break;

    }
    return true;
}

//-------------------- process slots ------------------------
bool Udpserver::processBrEntry()
{

    return true;
}

bool Udpserver::processBrExit()
{

    return true;
}

bool Udpserver::processAnsentry()
{

    return true;
}

bool Udpserver::processBrAbsence()
{

    return true;

}

bool Udpserver::processBrIsgetlist()
{
    return true;
}

bool Udpserver::processOkgetlist()
{

    return true;
}

bool Udpserver::processGetlist()
{

    return true;
}

bool Udpserver::processAnslist()
{

    return true;
}

bool Udpserver::processBrIsgetlist2()
{

    return true;
}

bool Udpserver::processSendmsg()
{

    return true;
}

bool Udpserver::processRecvmsg()
{

    return true;
}

bool Udpserver::processReadmsg()
{

    return true;
}


bool Udpserver::processDelmsg()
{

    return true;
}

bool Udpserver::processAnsreadmsg()
{

    return true;
}

bool Udpserver::processGetinfo()
{

    return true;
}

bool Udpserver::processSendinfo()
{

    return true;
}

bool Udpserver::processGetabsenceinfo()
{

    return true;
}

bool Udpserver::processSendabsenceinfo()
{

    return true;
}

bool Udpserver::processGetfiledata()
{

    return true;
}

bool Udpserver::processReleasefiles()
{

    return true;
}

bool Udpserver::processGetdirfiles()
{

    return true;
}

bool Udpserver::processGetpubkey()
{

    return true;
}

bool Udpserver::processAnspubkey()
{

    return true;
}

bool Udpserver::processNooperation()
{

    return true;
}



//-------------------- sokcet communication ------------------------
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
