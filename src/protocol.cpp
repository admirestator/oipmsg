#include <QDebug>
#include <QStringList>
#include <QProcess>
#include <QHostInfo>
#include <QTime>
#include <QNetworkInterface>

#include <iostream>
#include <string>
#include <sstream>
#include "ipmsg.h"
#include "protocol.h"



Protocol::Protocol()
{
    //QString version;
    //QString username;
    //QString hostname;

    version = QString::number(IPMSG_VERSION, 10);

    QStringList envVariables;

    envVariables << "USER.*" << "HOSTNAME.*";

    //系统中关于环境变量的信息存在environment中
    // can use new code for QProcessEnvironment
    QStringList environment = QProcess::systemEnvironment();

    int index = environment.indexOf(QRegExp("USER.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            //qDebug() << stringList.at(1);
            username = stringList.at(1);
        }
    }

    index = environment.indexOf(QRegExp("HOSTNAME.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            //qDebug() << stringList.at(1);
            hostname = stringList.at(1);
        }
    }

    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
    //for(int i=0;i<list.count();i++)
    //{
        QNetworkInterface interface=list.at(1);
        QString hardwareAddress=interface.hardwareAddress();
        //qDebug() << hardwareAddress;
    //}

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

    // Set seed value.
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    // Set init package number as random.
    quint32 packetno;
    packetno = qrand() % 1024;
    //qDebug () << packetno;

    quint64 cmd = 0;
    cmd = cmd | IPMSG_BR_ENTRY;
    //QString cmd = QString::number()

    QByteArray cmd_br_entry;
    cmd_br_entry.append (QString::number(IPMSG_VERSION, 16));
    cmd_br_entry.append (":");
    cmd_br_entry.append (QString::number(packetno, 10));
    cmd_br_entry.append (":");
    cmd_br_entry.append (username);
    cmd_br_entry.append (":");
    cmd_br_entry.append (hostname);
    cmd_br_entry.append (":");
    cmd_br_entry.append (QString::number(cmd, 16));
    cmd_br_entry.append (":");
    cmd_br_entry.append ("8C:89:A5:BE:1E:F5");
    //qDebug () << cmd_br_entry;
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
