// class for implementation of protocal for ipmsg and self defined one.

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QProcess>
#include <QNetworkInterface>
#include <QHostInfo>
#include <QTime>
#include <QDebug>

#include "ipmsg.h"

#define ABSENCEABSENCE 1
#define ABSENCEMEAL    2
#define ABSENCEMEETING 3
#define ABSENCEVISITOR 4
#define ABSENCEOUT     5
#define ABSENCEHOME    6
#define ABSENCEEDO     7
#define ABSENCEPRIEST  8

namespace protocol{
    class Protocal;
};

class Protocol
{
public:
    Protocol();
    virtual ~Protocol();

    quint16 port;

    //build 24 commands of ipmsg protocol version3
    QByteArray buildcmdNooperation();
    QByteArray buildcmdBrEntry(const bool &absence = false);
    QByteArray buildcmdBrExit();
    QByteArray buildcmdAnsentry(const bool &absence = false);
    QByteArray buildcmdBrAbsence();
    QByteArray buildcmdBrIsgetlist();
    QByteArray buildcmdOkgetlist();
    QByteArray buildcmdGetlist();
    QByteArray buildcmdAnslist();
    QByteArray buildcmdBrIsgetlist2();
    QByteArray buildcmdSendmsg(const QString &msg, const bool &seal = false);
    QByteArray buildcmdRecvmsg();
    QByteArray buildcmdReadmsg(const QString &packet);
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

private:
    QString version;
    QString username;
    QString hostname;

    // absence status flag
    quint32 absenceStatus;

    void setAbsenceStatus(const quint32 &status);

};

#endif // PROTOCOL_H
