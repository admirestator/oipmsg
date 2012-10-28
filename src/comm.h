//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

//#include <QByteArray>
#include "protocol.h"

namespace comm{
    class Comm;
};

class Comm : public Protocol
{
public:
    Comm();
    ~Comm();

    int sendcmd_nooperation();
    int sendcmd_br_entry();
    int sendcmd_br_exit();
    int sendcmd_ansentry();
    int sendcmd_br_absence();
    int sendcmd_br_isgetlist();
    int sendcmd_okgetlist();
    int sendcmd_getlist();
    int sendcmd_anslist();
    int sendcmd_br_isgetlist2();
    int sendcmd_sendmsg();
    int sendcmd_recvmsg();
    int sendcmd_readmsg();
    int sendcmd_delmsg();
    int sendcmd_ansreadmsg();
    int sendcmd_getinfo();
    int sendcmd_sendinfo();
    int sendcmd_getabsenceinfo();
    int sendcmd_sendabsenceinfo();
    int sendcmd_getfiledata();
    int sendcmd_releasefiles();
    int sendcmd_getdirfiles();
    int sendcmd_getpubkey();
    int sendcmd_anspubkey();
};

#endif // COMM_H
