#include "ipmsg.h"
#include "protocol.h"

Protocol::Protocol()
{

}

Protocol::~Protocol()
{

}

QByteArray Protocol::buildcmdNooperation()
{
    QByteArray cmd_nooperation;

    return cmd_nooperation;
}


QByteArray Protocol::buildcmdBrEntry()
{
    QByteArray cmd_br_entry;

    return cmd_br_entry;
}


QByteArray Protocol::buildcmdBrExit()
{
    QByteArray cmd_br_exit;

    return cmd_br_exit;
}

QByteArray Protocol::buildcmdAnsentry()
{
    QByteArray cmd_ansentry;

    return cmd_ansentry;
}

QByteArray Protocol::buildcmdBrAbsence()
{
    QByteArray cmd_absence;

    return cmd_absence;
}

QByteArray Protocol::buildcmdBrIsgetlist()
{
    QByteArray cmd_isgetlist;

    return cmd_isgetlist;
}

QByteArray Protocol::buildcmdOkgetlist()
{
    QByteArray cmd_okgetlist;

    return cmd_okgetlist;
}

QByteArray Protocol::buildcmdGetlist()
{
    QByteArray cmd_getlist;

    return cmd_getlist;
}

QByteArray Protocol::buildcmdAnslist()
{
    QByteArray cmd_anslist;

    return cmd_anslist;
}

QByteArray Protocol::buildcmdBrIsgetlist2()
{
    QByteArray cmd_isgetlist2;

    return cmd_isgetlist2;
}

QByteArray Protocol::buildcmdSendmsg()
{
    QByteArray cmd_sendmsg;

    return cmd_sendmsg;
}

QByteArray Protocol::buildcmdRecvmsg()
{
    QByteArray cmd_recvmsg;

    return cmd_recvmsg;
}

QByteArray Protocol::buildcmdReadmsg()
{
    QByteArray cmd_readmsg;

    return cmd_readmsg;
}

QByteArray Protocol::buildcmdDelmsg()
{
    QByteArray cmd_delmsg;

    return cmd_delmsg;
}

QByteArray Protocol::buildcmdAnsreadmsg()
{
    QByteArray cmd_ansreadmsg;

    return cmd_ansreadmsg;
}

QByteArray Protocol::buildcmdGetinfo()
{
    QByteArray cmd_getinfo;

    return cmd_getinfo;
}

QByteArray Protocol::buildcmdSendinfo()
{
    QByteArray cmd_sendinfo;

    return cmd_sendinfo;
}

QByteArray Protocol::buildcmdGetabsenceinfo()
{
    QByteArray cmd_getabsenceinfo;

    return cmd_getabsenceinfo;
}

QByteArray Protocol::buildcmdSendabsenceinfo()
{
    QByteArray cmd_sendabsenceinfo;

    return cmd_sendabsenceinfo;
}

QByteArray Protocol::buildcmdGetfiledata()
{
    QByteArray cmd_getfiledata;

    return cmd_getfiledata;
}

QByteArray Protocol::buildcmdReleasefiles()
{
    QByteArray cmd_realeasefiles;

    return cmd_realeasefiles;
}

QByteArray Protocol::buildcmdGetdirfiles()
{
    QByteArray cmd_getdirfiles;

    return cmd_getdirfiles;
}

QByteArray Protocol::buildcmdGetpubkey()
{
    QByteArray cmd_getpubkey;

    return cmd_getpubkey;
}

QByteArray Protocol::buildcmdAnspubkey()
{
    QByteArray cmd_anspubkey;

    return cmd_anspubkey;
}
