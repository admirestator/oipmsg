#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QThread>
#include <QObject>

#include "protocol.h"

namespace udpserver {
    class Udpserver;
};


class Udpserver : public QThread
{
    Q_OBJECT
public:
    Udpserver(quint16 &udpport);
    virtual ~Udpserver();

    QUdpSocket *udpSocket;
    Protocol *protocolObj;

    void run();

private:
    quint16 port;
    bool bindPort();

    bool sendcmdNooperation();
    bool sendcmdBrEntry();
    bool sendcmdBrExit();
    bool sendcmdAnsentry();
    bool sendcmdBrAbsence();
    bool sendcmdBrIsgetlist();
    bool sendcmdOkgetlist();
    bool sendcmdGetlist();
    bool sendcmdAnslist();
    bool sendcmdBrIsgetlist2();
    bool sendcmdSendmsg();
    bool sendcmdRecvmsg();
    bool sendcmdReadmsg();
    bool sendcmdDelmsg();
    bool sendcmdAnsreadmsg();
    bool sendcmdGetinfo();
    bool sendcmdSendinfo();
    bool sendcmdGetabsenceinfo();
    bool sendcmdSendabsenceinfo();
    bool sendcmdGetfiledata();
    bool sendcmdReleasefiles();
    bool sendcmdGetdirfiles();
    bool sendcmdGetpubkey();
    bool sendcmdAnspubkey();

//private slots:
public slots:
    void dataReceived();
};

#endif // UDPCOMM_H
