// class for implementation of protocal for ipmsg and self defined one.

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>
#include <QString>
#include "ipmsg.h"

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
    QByteArray buildcmdBrAbsence(const QString &absencdStatus);
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

    // absence info
    QString absence_absence;
    QString absence_meal;
    QString absence_meeing;
    QString absence_visitor;
    QString absence_out;
    QString absence_home;
    QString absence_edo;
    QString absence_priest;

private:
    QString version;
    QString username;
    QString hostname;





};

#endif // PROTOCOL_H
