//class for tcp/ip communication

#ifndef TCPSERVER_h
#define TCPSERVER_h

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>

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
    Protocol *protoobj;
    QTcpServer *tcpServer;
    QTcpSocket *tcpServerConnection;
    quint16 port;

    qint64 totalBytes;  //存放总大小信息
    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName;   //存放文件名
    QFile *localFile;   //本地文件
    QByteArray inBlock;   //数据缓冲区

    void buildConnection();

private slots:
    void recvFile();
    void recvDir();

    //void start();   //开始监听
    void acceptConnection();  //建立连接
    void updateServerProgress();  //更新进度条，接收数据
    void displayError(QAbstractSocket::SocketError socketError);
};

#endif //TCPSERVER_h
