#include <QByteArray>
#include <QMessageBox>
#include "tcpserver.h"

Tcpserver::Tcpserver()
{
    port = IPMSG_DEFAULT_PORT;
    tcpServer = new QTcpServer(this);

    if (tcpServer->isListening()) {
        qDebug() << "port was listend!";
        exit(-4);
    }

    if (!tcpServer->listen(QHostAddress::Any, port)) {
        /*
          QMessageBox::critical(this,
                                tr("Unable to start the server: %1.").arg(tcpServer->errorString()));
       */
        qDebug () << "unable listen tcpserver";
        tcpServer->close();
        exit(-3);
    }
}

Tcpserver::~Tcpserver()
{
    delete tcpServer;
}


void Tcpserver::run()
{

}


void Tcpserver::buildConnection()
{
    //connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
}


void Tcpserver::recvFile()
{

}

void Tcpserver::recvDir()
{

}
