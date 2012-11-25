#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QDataStream>
#include <QIODevice>

#include "protocol.h"
#include "user.h"

class Tcpclient : QThread
{
    Q_OBJECT
public:
    //Tcpclient(const QHostAddress &dstip, const QString &filename);
    Tcpclient(const User &userinfo, const QString &filename);
    virtual ~Tcpclient();

    void run();

private:
    bool buildConnection();
    bool startTransfer();

    Protocol *protoobj;
    QTcpSocket *tcpClient;
    QHostAddress destIP;
    quint16 port;
    QString fileName;
    User userDataLocal;
    QFile *localFile;

    QByteArray outBlock;
    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;


};

#endif // TCPCLIENT_H
