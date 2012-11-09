// class for implementation of protocal for ipmsg and self defined one.

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>
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
    QByteArray buildcmdBrAbsence();
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

};

#endif // PROTOCOL_H
