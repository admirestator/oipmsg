// class for implementation of protocal for ipmsg and self defined one.

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>

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
    QByteArray buildcmd_nooperation();
    QByteArray buildcmd_br_entry();
    QByteArray buildcmd_br_exit();
    QByteArray buildcmd_ansentry();
    QByteArray buildcmd_br_absence();
    QByteArray buildcmd_br_isgetlist();
    QByteArray buildcmd_okgetlist();
    QByteArray buildcmd_getlist();
    QByteArray buildcmd_anslist();
    QByteArray buildcmd_br_isgetlist2();
    QByteArray buildcmd_sendmsg();
    QByteArray buildcmd_recvmsg();
    QByteArray buildcmd_readmsg();
    QByteArray buildcmd_delmsg();
    QByteArray buildcmd_ansreadmsg();
    QByteArray buildcmd_getinfo();
    QByteArray buildcmd_sendinfo();
    QByteArray buildcmd_getabsenceinfo();
    QByteArray buildcmd_sendabsenceinfo();
    QByteArray buildcmd_getfiledata();
    QByteArray buildcmd_releasefiles();
    QByteArray buildcmd_getdirfiles();
    QByteArray buildcmd_getpubkey();
    QByteArray buildcmd_anspubkey();

};

#endif // PROTOCOL_H
