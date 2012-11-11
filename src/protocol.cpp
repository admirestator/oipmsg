#include <QDebug>
#include <QStringList>
#include <QProcess>
#include <QHostInfo>
#include <iostream>
#include <QNetworkInterface>
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
    QString username;
    QString hostname;
    //QByteArray cmd_br_entry;

    QStringList envVariables;
    //将后面5个string存到envVariables环境变量中
    //envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
     //            << "HOSTNAME.*" << "DOMAINNAME.*";

    envVariables << "USER.*" << "HOSTNAME.*";


    //系统中关于环境变量的信息存在environment中
    // can use new code for QProcessEnvironment
    QStringList environment = QProcess::systemEnvironment();
    /*
    foreach (QString string, envVariables) {
        //indexOf为返回第一个匹配list的索引,QRegExp类是用规则表达式进行模式匹配的类
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            //stringList中存的是environment.at(index)中出现'='号前的字符串
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                qDebug() << stringList.at(1);
                //exit(1);
                //return stringList.at(1); //at(0)为文字"USERNAME."，at(1)为用户名
                //break;
            }
        }
    }
    */

    int index = environment.indexOf(QRegExp("USER.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            qDebug() << stringList.at(1);
            username = stringList.at(1);
        }
    }

    index = environment.indexOf(QRegExp("HOSTNAME.*"));
    if (index != -1) {
        QStringList stringList = environment.at(index).split('=');
        if (stringList.size() == 2) {
            qDebug() << stringList.at(1);
            hostname = stringList.at(1);
        }
    }

    /*
    QNetworkInterface networkInterface;
    QString hardwareAddress = networkInterface.hardwareAddress();
    qDebug() << hardwareAddress;
    */

    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
    //for(int i=0;i<list.count();i++)
    //{
        QNetworkInterface interface=list.at(1);
        QString hardwareAddress=interface.hardwareAddress();
        qDebug() << hardwareAddress;
    //}

/*
    cmd_br_entry << IPMSG_VERSION << ":"
                 << 271828 << ":"
                 << username << ":"
                 << hostname << ":"
                 << IPMSG_BR_ENTRY << ":"
                 << hardwareAddress;
*/
    QByteArray cmd_br_entry = "1:271828:admire:Fiona.Matrix:1:8C:89:A5:BE:1E:F5";
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
