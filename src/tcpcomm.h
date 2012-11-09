//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

#include "protocol.h"

namespace tcpcomm{
    class Tcpcomm;
};

class Tcpcomm : public Protocol
{
public:
    Tcpcomm();
    ~Tcpcomm();

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
};

#endif // COMM_H
