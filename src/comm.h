//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

#include "protocol.h"

namespace comm{
    class Comm;
};

class Comm : public Protocol
{
public:
    Comm();
    ~Comm();

    bool sendcmd_nooperation();
    bool sendcmd_br_entry();
    bool sendcmd_br_exit();
    bool sendcmd_ansentry();
    bool sendcmd_br_absence();
    bool sendcmd_br_isgetlist();
    bool sendcmd_okgetlist();
    bool sendcmd_getlist();
    bool sendcmd_anslist();
    bool sendcmd_br_isgetlist2();
    bool sendcmd_sendmsg();
    bool sendcmd_recvmsg();
    bool sendcmd_readmsg();
    bool sendcmd_delmsg();
    bool sendcmd_ansreadmsg();
    bool sendcmd_getinfo();
    bool sendcmd_sendinfo();
    bool sendcmd_getabsenceinfo();
    bool sendcmd_sendabsenceinfo();
    bool sendcmd_getfiledata();
    bool sendcmd_releasefiles();
    bool sendcmd_getdirfiles();
    bool sendcmd_getpubkey();
    bool sendcmd_anspubkey();
};

#endif // COMM_H
