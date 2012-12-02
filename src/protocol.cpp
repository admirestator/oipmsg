#include "ipmsg.h"
#include "protocol.h"

Protocol::Protocol()
{
    port = IPMSG_DEFAULT_PORT;
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
            username = stringList.at(1);
        }
    }

    index = environment.indexOf(QRegExp("HOSTNAME.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            hostname = stringList.at(1);
        }
    }

    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
    QNetworkInterface interface=list.at(1);
    QString hardwareAddress=interface.hardwareAddress();

}

Protocol::~Protocol()
{

}

void Protocol::setAbsenceStatus(const quint32 &status)
{
    absenceStatus = status;
    //absenceStatus = status;
}

QByteArray Protocol::buildcmdNooperation()
{
    quint32 packetno;

    // Set seed value.
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    packetno = qrand() % 10240;

    quint64 cmd = 0;
    cmd = cmd | IPMSG_NOOPERATION;

    QByteArray cmd_nooperation;
    cmd_nooperation.append (QString::number(IPMSG_VERSION, 16));
    cmd_nooperation.append (":");
    cmd_nooperation.append (QString::number(packetno, 10));
    cmd_nooperation.append (":");
    cmd_nooperation.append (username);
    cmd_nooperation.append (":");
    cmd_nooperation.append (hostname);
    cmd_nooperation.append (":");
    cmd_nooperation.append (QString::number(cmd, 16));
    cmd_nooperation.append (":");
    cmd_nooperation.append ("8C:89:A5:BE:1E:F5");

    qDebug () << cmd_nooperation;
    return cmd_nooperation;
}


QByteArray Protocol::buildcmdBrEntry()
{

    // Set seed value.
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ENTRY;
    qDebug() << "bcmd: " << cmd;

    // set IPMSG_ABSENCEOPT option
    /*
    if (absenceStatus == ABSENCEABSENCE ||
        absenceStatus == ABSENCEMEAL ||
        absenceStatus == ABSENCEMEETING ||
        absenceStatus == ABSENCEVISITOR ||
        absenceStatus == ABSENCEOUT ||
        absenceStatus == ABSENCEHOME ||
        absenceStatus == ABSENCEEDO ||
        absenceStatus == ABSENCEPRIEST) {
        cmd = cmd | IPMSG_ABSENCEOPT;
    }
    */

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
    cmd_br_entry.append (username);

    return cmd_br_entry;
}


QByteArray Protocol::buildcmdBrExit()
{

    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_EXIT;

    QByteArray cmd_br_exit;
    cmd_br_exit.append (QString::number(IPMSG_VERSION, 16));
    cmd_br_exit.append (":");
    cmd_br_exit.append (QString::number(packetno, 10));
    cmd_br_exit.append (":");
    cmd_br_exit.append (username);
    cmd_br_exit.append (":");
    cmd_br_exit.append (hostname);
    cmd_br_exit.append (":");
    cmd_br_exit.append (QString::number(cmd, 16));
    cmd_br_exit.append (":");
    cmd_br_exit.append (username);

    qDebug () << cmd_br_exit;
    return cmd_br_exit;
}

QByteArray Protocol::buildcmdAnsentry()
{
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_ANSENTRY;
    // set IPMSG_ABSENCEOPT option
    if (absenceStatus == ABSENCEABSENCE ||
        absenceStatus == ABSENCEMEAL ||
        absenceStatus == ABSENCEMEETING ||
        absenceStatus == ABSENCEVISITOR ||
        absenceStatus == ABSENCEOUT ||
        absenceStatus == ABSENCEHOME ||
        absenceStatus == ABSENCEEDO ||
        absenceStatus == ABSENCEPRIEST) {
        cmd = cmd | IPMSG_ABSENCEOPT;
    }

    QByteArray cmd_ansentry;
    cmd_ansentry.append (QString::number(IPMSG_VERSION, 16));
    cmd_ansentry.append (":");
    cmd_ansentry.append (QString::number(packetno, 10));
    cmd_ansentry.append (":");
    cmd_ansentry.append (username);
    cmd_ansentry.append (":");
    cmd_ansentry.append (hostname);
    cmd_ansentry.append (":");
    cmd_ansentry.append (QString::number(cmd, 16));
    cmd_ansentry.append (":");
    cmd_ansentry.append (username);

    qDebug () << "Ansentry" << cmd_ansentry;
    return cmd_ansentry;
}

QByteArray Protocol::buildcmdBrAbsence(const quint32 &absenceStatus)
{
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ABSENCE;

    QByteArray cmd_absence;
    cmd_absence.append (QString::number(IPMSG_VERSION, 16));
    cmd_absence.append (":");
    cmd_absence.append (QString::number(packetno, 10));
    cmd_absence.append (":");
    cmd_absence.append (username);
    cmd_absence.append (":");
    cmd_absence.append (hostname);
    cmd_absence.append (":");
    cmd_absence.append (QString::number(cmd, 16));
    cmd_absence.append (":");
    cmd_absence.append (username);

    switch (absenceStatus) {
        case ABSENCEMEAL:
            cmd_absence.append("[meal]");
            break;
        case ABSENCEMEETING:
            cmd_absence.append("[meeting]");
            break;
        case ABSENCEVISITOR:
            cmd_absence.append("[visitor]");
            break;
        case ABSENCEOUT:
            cmd_absence.append("[out]");
            break;
        case ABSENCEHOME:
            cmd_absence.append("[home]");
            break;
        case ABSENCEEDO:
            cmd_absence.append("[edo]");
            break;
        case ABSENCEPRIEST:
            cmd_absence.append("[priest]");
            break;
        default:
            cmd_absence.append("[absence]");
            break;
    }
    qDebug () << cmd_absence;
    return cmd_absence;
}

QByteArray Protocol::buildcmdBrIsgetlist()
{
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
}

QByteArray Protocol::buildcmdOkgetlist()
{

    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_OKGETLIST;

    QByteArray cmd_okgetlist;
    cmd_okgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_okgetlist.append (":");
    cmd_okgetlist.append (QString::number(packetno, 10));
    cmd_okgetlist.append (":");
    cmd_okgetlist.append (username);
    cmd_okgetlist.append (":");
    cmd_okgetlist.append (hostname);
    cmd_okgetlist.append (":");
    cmd_okgetlist.append (QString::number(cmd, 16));
    cmd_okgetlist.append (":");
    cmd_okgetlist.append (username);

    qDebug () << cmd_okgetlist;
    return cmd_okgetlist;
}

QByteArray Protocol::buildcmdGetlist()
{
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_GETLIST;

    QByteArray cmd_getlist;
     cmd_getlist.append (QString::number(IPMSG_VERSION, 16));
     cmd_getlist.append (":");
     cmd_getlist.append (QString::number(packetno, 10));
     cmd_getlist.append (":");
     cmd_getlist.append (username);
     cmd_getlist.append (":");
     cmd_getlist.append (hostname);
     cmd_getlist.append (":");
     cmd_getlist.append (QString::number(cmd, 16));
     cmd_getlist.append (":");
     cmd_getlist.append (username);

    qDebug () << cmd_getlist;
    return cmd_getlist;
}

QByteArray Protocol::buildcmdAnslist()
{
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_ANSLIST;

    QByteArray cmd_anslist;
     cmd_anslist.append (QString::number(IPMSG_VERSION, 16));
     cmd_anslist.append (":");
     cmd_anslist.append (QString::number(packetno, 10));
     cmd_anslist.append (":");
     cmd_anslist.append (username);
     cmd_anslist.append (":");
     cmd_anslist.append (hostname);
     cmd_anslist.append (":");
     cmd_anslist.append (QString::number(cmd, 16));
     cmd_anslist.append (":");
     cmd_anslist.append (username);

    qDebug () <<  cmd_anslist;
    return cmd_anslist;
}

QByteArray Protocol::buildcmdBrIsgetlist2()
{
    QByteArray cmd_isgetlist2;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_isgetlist2;
}

QByteArray Protocol::buildcmdSendmsg(const QString &msg)
{
    QByteArray cmd_sendmsg;
    // Set init package number as random.
    quint64 packetno;
    //packetno = qrand() % 10240;
    packetno = qrand();

    quint32 cmd = 0;
    cmd = cmd | IPMSG_SENDMSG;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (msg);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_sendmsg;
}

QByteArray Protocol::buildcmdRecvmsg(const QString &packetno)
{
    // Set init package number as random.
    quint64 pktno;
    pktno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_RECVMSG;

    QByteArray cmd_recvmsg;
    cmd_recvmsg.append (QString::number(IPMSG_VERSION, 16));
    cmd_recvmsg.append (":");
    cmd_recvmsg.append (QString::number(pktno, 10));
    cmd_recvmsg.append (":");
    cmd_recvmsg.append (username);
    cmd_recvmsg.append (":");
    cmd_recvmsg.append (hostname);
    cmd_recvmsg.append (":");
    cmd_recvmsg.append (QString::number(cmd, 10));
    cmd_recvmsg.append (":");
    cmd_recvmsg.append (packetno);

    qDebug () << cmd_recvmsg;
    return cmd_recvmsg;
}

QByteArray Protocol::buildcmdReadmsg()
{
    QByteArray cmd_readmsg;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_readmsg;
}

QByteArray Protocol::buildcmdDelmsg()
{
    QByteArray cmd_delmsg;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_delmsg;
}

QByteArray Protocol::buildcmdAnsreadmsg()
{
    QByteArray cmd_ansreadmsg;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_ansreadmsg;
}

QByteArray Protocol::buildcmdGetinfo()
{
    QByteArray cmd_getinfo;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_getinfo;
}

QByteArray Protocol::buildcmdSendinfo()
{
    QByteArray cmd_sendinfo;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_sendinfo;
}

QByteArray Protocol::buildcmdGetabsenceinfo()
{
    QByteArray cmd_getabsenceinfo;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_getabsenceinfo;
}

QByteArray Protocol::buildcmdSendabsenceinfo()
{
    QByteArray cmd_sendabsenceinfo;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_sendabsenceinfo;
}

QByteArray Protocol::buildcmdGetfiledata()
{
    QByteArray cmd_getfiledata;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_getfiledata;
}

QByteArray Protocol::buildcmdReleasefiles()
{
    QByteArray cmd_realeasefiles;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_realeasefiles;
}

QByteArray Protocol::buildcmdGetdirfiles()
{
    QByteArray cmd_getdirfiles;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_getdirfiles;
}

QByteArray Protocol::buildcmdGetpubkey()
{
    QByteArray cmd_getpubkey;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_getpubkey;
}

QByteArray Protocol::buildcmdAnspubkey()
{
    QByteArray cmd_anspubkey;
    // Set init package number as random.
    quint64 packetno;
    packetno = qrand() % 10240;

    quint32 cmd = 0;
    cmd = cmd | IPMSG_BR_ISGETLIST;

    QByteArray cmd_isgetlist;
    cmd_isgetlist.append (QString::number(IPMSG_VERSION, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(packetno, 10));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (hostname);
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (QString::number(cmd, 16));
    cmd_isgetlist.append (":");
    cmd_isgetlist.append (username);

    qDebug () << cmd_isgetlist;
    return cmd_isgetlist;
    return cmd_anspubkey;
}
