#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QThread>

#include "protocol.h"
#include "host.h"

namespace udpserver {
    class Udpserver;
};


class Udpserver : public QThread
{
    Q_OBJECT
public:
    Udpserver(quint16 &udpport);
    ~Udpserver();

    void run();

private:
    quint16 port;
    QUdpSocket *udpSocket;
    Protocol *protocolObj;

    bool bindPort();
    bool handleCmd(const QByteArray &packet);
    bool buildConnection();

    // send all cmd
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

private slots:
    void dataReceived();

    bool processNooperation();
    bool processBrEntry();
    bool processBrExit();
    bool processAnsentry();
    bool processBrAbsence();
    bool processBrIsgetlist();
    bool processOkgetlist();
    bool processGetlist();
    bool processAnslist();
    bool processBrIsgetlist2();
    bool processSendmsg();
    bool processRecvmsg();
    bool processReadmsg();
    bool processDelmsg();
    bool processAnsreadmsg();
    bool processGetinfo();
    bool processSendinfo();
    bool processGetabsenceinfo();
    bool processSendabsenceinfo();
    bool processGetfiledata();
    bool processReleasefiles();
    bool processGetdirfiles();
    bool processGetpubkey();
    bool processAnspubkey();

signals:
    void signalNooperation();
    void signalBrEntry(const QByteArray&);
    void signalBrExit();
    void signalAnsentry();
    void signalBrAbsence();
    void signalOkgetlist();
    void signalBrIsgetlist();
    void signalGetlist();
    void signalAnslist();
    void signalBrIsgetlist2();
    void signalSendmsg();
    void signalRecvmsg();
    void signalReadmsg();
    void signalDelmsg();
    void signalAnsreadmsg();
    void signalGetinfo();
    void signalSendinfo();
    void signalGetabsenceinfo();
    void signalSendabsenceinfo();
    void signalGetfiledata();
    void signalReleasefiles();
    void signalGetdirfiles();
    void signalGetpubkey();
    void signalAnspubkey();


};

#endif // UDPCOMM_H
