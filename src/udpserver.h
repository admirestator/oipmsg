#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QMessageBox>
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
    bool handleCmd(const QHostAddress& ipaddr, const QByteArray &newPacket);
    bool buildConnection();

private slots:
    // send all cmd
    bool sendcmdNooperation(const QHostAddress &ipaddr);
    bool sendcmdBrEntry();
    bool sendcmdBrExit();
    bool sendcmdAnsentry(const QHostAddress &ipaddr);
    bool sendcmdBrAbsence();
    bool sendcmdBrIsgetlist();
    bool sendcmdOkgetlist();
    bool sendcmdGetlist();
    bool sendcmdAnslist();
    bool sendcmdBrIsgetlist2();
    bool sendcmdSendmsg(const QHostAddress &ipaddr, const QString &msg);
    bool sendcmdRecvmsg(const QHostAddress &ipaddr, const QString &packet);
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
//public slots:
    void dataReceived();

    bool processNooperation(const QHostAddress &ipaddr);
    bool processBrEntry(const QHostAddress &ipaddr,
                        const QByteArray &packet);
    bool processBrExit(const QString &username);
    bool processAnsentry(const QHostAddress &ipaddr,
                         const QByteArray &packet);
    bool processBrAbsence();
    bool processBrIsgetlist();
    bool processOkgetlist();
    bool processGetlist();
    bool processAnslist();
    bool processBrIsgetlist2();
    //bool processSendmsg(const QHostAddress& ipaddr,
    bool processSendmsg(const QHostAddress &ipaddr,
                        const QByteArray &packet);
    bool processRecvmsg(const QHostAddress &ipaddr,
                        const QByteArray &packet);
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
    void signalNooperation(const QHostAddress &ipaddr);
    void signalBrEntry(const QHostAddress &ipaddr,
                       const QByteArray &packet);
    void signalBrExit(const QString &username);
    void signalAnsentry(const QHostAddress &ipaddr,
                        const QByteArray &packet);
    void signalBrAbsence();
    void signalOkgetlist();
    void signalBrIsgetlist();
    void signalGetlist();
    void signalAnslist();
    void signalBrIsgetlist2();
    void signalSendmsg(const QHostAddress &ipaddr,
                       const QByteArray &packet);
    void signalRecvmsg(const QHostAddress &ipaddr,
                       const QByteArray &packet);
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

    void gotMsg(const QByteArray &packet);
};

#endif // UDPCOMM_H
