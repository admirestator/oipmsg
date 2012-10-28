#include "ipmsg.h"
#include "protocol.h"

Protocol::Protocol()
{

}

Protocol::~Protocol()
{

}

QByteArray Protocol::buildcmd_nooperation()
{
    QByteArray cmd_nooperation;

    return cmd_nooperation;
}


QByteArray Protocol::buildcmd_br_entry()
{
    QByteArray cmd_br_entry;

    return cmd_br_entry;
}


QByteArray Protocol::buildcmd_br_exit()
{
    QByteArray cmd_br_exit;

    return cmd_br_exit;
}

QByteArray Protocol::buildcmd_ansentry()
{
    QByteArray cmd_ansentry;

    return cmd_ansentry;
}

QByteArray Protocol::buildcmd_br_absence()
{
    QByteArray cmd_absence;

    return cmd_absence;
}

QByteArray Protocol::buildcmd_br_isgetlist()
{
    QByteArray cmd_isgetlist;

    return cmd_isgetlist;
}

QByteArray Protocol::buildcmd_okgetlist()
{
    QByteArray cmd_okgetlist;

    return cmd_okgetlist;
}

QByteArray Protocol::buildcmd_getlist()
{
    QByteArray cmd_getlist;

    return cmd_getlist;
}

QByteArray Protocol::buildcmd_anslist()
{
    QByteArray cmd_anslist;

    return cmd_anslist;
}

QByteArray Protocol::buildcmd_br_isgetlist2()
{
    QByteArray cmd_isgetlist2;

    return cmd_isgetlist2;
}

QByteArray Protocol::buildcmd_sendmsg()
{
    QByteArray cmd_sendmsg;

    return cmd_sendmsg;
}

QByteArray Protocol::buildcmd_recvmsg()
{
    QByteArray cmd_recvmsg;

    return cmd_recvmsg;
}

QByteArray Protocol::buildcmd_readmsg()
{
    QByteArray cmd_readmsg;

    return cmd_readmsg;
}

QByteArray Protocol::buildcmd_delmsg()
{
    QByteArray cmd_delmsg;

    return cmd_delmsg;
}

QByteArray Protocol::buildcmd_ansreadmsg()
{
    QByteArray cmd_ansreadmsg;

    return cmd_ansreadmsg;
}

QByteArray Protocol::buildcmd_getinfo()
{
    QByteArray cmd_getinfo;

    return cmd_getinfo;
}

QByteArray Protocol::buildcmd_sendinfo()
{
    QByteArray cmd_sendinfo;

    return cmd_sendinfo;
}

QByteArray Protocol::buildcmd_getabsenceinfo()
{
    QByteArray cmd_getabsenceinfo;

    return cmd_getabsenceinfo;
}

QByteArray Protocol::buildcmd_sendabsenceinfo()
{
    QByteArray cmd_sendabsenceinfo;

    return cmd_sendabsenceinfo;
}

QByteArray Protocol::buildcmd_getfiledata()
{
    QByteArray cmd_getfiledata;

    return cmd_getfiledata;
}

QByteArray Protocol::buildcmd_releasefiles()
{
    QByteArray cmd_realeasefiles;

    return cmd_realeasefiles;
}

QByteArray Protocol::buildcmd_getdirfiles()
{
    QByteArray cmd_getdirfiles;

    return cmd_getdirfiles;
}

QByteArray Protocol::buildcmd_getpubkey()
{
    QByteArray cmd_getpubkey;

    return cmd_getpubkey;
}

QByteArray Protocol::buildcmd_anspubkey()
{
    QByteArray cmd_anspubkey;

    return cmd_anspubkey;
}
