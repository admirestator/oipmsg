// class for implementation of protocal for ipmsg and self defined one.

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>
#include <QString>
#include "ipmsg.h"

#define ABSENCEABSENCE 1
#define ABSENCEMEAL    2
#define ABSENCEMEETING 3
#define ABSENCEVISITOR 4
#define ABSENCEOUT     5
#define ABSENCEHOME    6
#define ABSENCEEDO     7
#define ABSENCEPRIEST  8

namespace protocol{
    class Protocal;
};

class Protocol
{
public:
    Protocol();
    virtual ~Protocol();

 //QByteArray datagram
    //build 24 commands of ipmsg protocol version3
    QByteArray buildcmdNooperation();
    QByteArray buildcmdBrEntry();
    QByteArray buildcmdBrExit();
    QByteArray buildcmdAnsentry();
    QByteArray buildcmdBrAbsence(const quint32 &absenceStatus);
    QByteArray buildcmdBrIsgetlist();
    QByteArray buildcmdOkgetlist();
    QByteArray buildcmdGetlist();
    QByteArray buildcmdAnslist();
    QByteArray buildcmdBrIsgetlist2();
    QByteArray buildcmdSendmsg();
    QByteArray buildcmdRecvmsg();
    QByteArray buildcmdReadmsg();
    QByteArray buildcmdDelmsg();
    QByteArray buildcmdAnsreadmsg();
    QByteArray buildcmdGetinfo();
    QByteArray buildcmdSendinfo();
    QByteArray buildcmdGetabsenceinfo();
    QByteArray buildcmdSendabsenceinfo();
    QByteArray buildcmdGetfiledata();
    QByteArray buildcmdReleasefiles();
    QByteArray buildcmdGetdirfiles();
    QByteArray buildcmdGetpubkey();
    QByteArray buildcmdAnspubkey();

private:
    QString version;
    QString username;
    QString hostname;

    // absence status flag
    quint32 absenceStatus;

    void setAbsenceStatus(const quint32 &status);

};

#endif // PROTOCOL_H
