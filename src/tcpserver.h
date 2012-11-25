//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include "protocol.h"

namespace tcpserver{
    class Tcpserver;
};

class Tcpserver : public QThread
{
public:
    Tcpserver();
    virtual ~Tcpserver();

    void run();

private:
    quint16 port;
    QTcpServer *tcpServer;
    Protocol *protoobj;

    void buildConnection();

private slots:
    void recvFile();
    void recvDir();
};

#endif // COMM_H
