#ifndef UDPCOMM_H
#define UDPCOMM_H

#include <QUdpSocket>
#include <QThread>
#include <QObject>

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
    virtual ~Udpserver();


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

//private slots:
public slots:
    void dataReceived();

private slots:
    bool process_br_entry();
    bool process_br_exit();
    bool process_ansentry();
    bool process_br_absence();
    bool process_okgetlist();
    bool process_getlist();
    bool process_anslist();
    bool process_br_isgetlist2();
    bool process_sendmsg();
    bool process_recvmsg();
    bool process_readmsg();
    bool process_delmsg();
    bool process_ansreadmsg();
    bool process_getinfo();
    bool process_sendinfo();
    bool process_getabsenceinfo();
    bool process_sendabsenceinfo();
    bool process_getfiledata();
    bool process_releasefiles();
    bool process_getdirfiles();
    bool process_getpubkey();
    bool process_anspubkey();
    bool process_nooperation();

signals:
    void br_entry(const QByteArray &packet);
    void br_entry();


};

#endif // UDPCOMM_H
