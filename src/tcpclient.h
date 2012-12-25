#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QDataStream>
#include <QIODevice>
#include <QFileDialog>
#include "protocol.h"
#include "user.h"

namespace tcpclient {
    class Tcpclient;
};

class Tcpclient : QThread
{
    Q_OBJECT
public:
    Tcpclient(const User &userinfo, const QString &filename);
    virtual ~Tcpclient();

    void run();

private:
    User userDataLocal;
    Protocol *protoobj;
    QTcpSocket *tcpClient;
    QHostAddress destIP;
    quint16 port;

    QString fileName;  //保存文件路径
    QFile *localFile;  //要发送的文件
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

    bool buildConnection();

private slots:
    void send();
    //void tcpConnect();  //连接服务器
    void startTransfer();  //发送文件大小等信息
    void updateProgress(qint64); //发送数据，更新进度条
    void displayError(QAbstractSocket::SocketError); //显示错误
    void openFile();  //打开文件
};

#endif // TCPCLIENT_H
