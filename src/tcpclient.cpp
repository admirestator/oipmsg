#include "tcpclient.h"

Tcpclient::Tcpclient(const User &userinfo, const QString &filename)
{
    userDataLocal = userinfo;

    protoobj = new Protocol();
    destIP = userDataLocal.getHostAddress();
    port = protoobj->port;

    tcpClient = new QTcpSocket();
    localFile = new QFile(filename);

    loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    tcpClient = new QTcpSocket(this);
    buildConnection();
}

Tcpclient::~Tcpclient()
{
    delete protoobj;
    delete tcpClient;
    delete localFile;
}

void Tcpclient::run()
{
    tcpClient->connectToHost(destIP, port);
}

bool Tcpclient::buildConnection()
{
    //connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    //当连接服务器成功时，发出connected()信号，我们开始传送文件
    //connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    //当有数据发送成功时，我们更新进度条
    //connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    return true;
}

void Tcpclient::openFile()   //打开文件
{
    //fileName = QFileDialog::getOpenFileName(this);
    //if(!fileName.isEmpty()) {}
}

void Tcpclient::send()   //连接到服务器，执行发送
{
    //初始化已发送字节为0
    bytesWritten = 0;
    //tcpClient->connectToHost(QHostAddress(destIP, port));
}

void Tcpclient::startTransfer()  //实现文件大小等信息的发送
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly)) {
        qDebug() << "open file error!";
        return;
    }

    //文件总大小
    totalBytes = localFile->size();

    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    sendOut << qint64(0) << qint64(0) << currentFileName;
    //依次写入总大小信息空间，文件名大小信息空间，文件名---仅是文件名不含路径，没必要含路径

    //这里的总大小是文件名大小等信息和实际文件大小的总和
    totalBytes += outBlock.size();

    //totalBytes是文件总大小，即两个quint64的大小+文件名+文件实际内容的大小
    //qint64((outBlock.size() - sizeof(qint64)*2))得到的是文件名大小
    sendOut.device()->seek(0);
    sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));

    //发送完头数据后剩余数据的大小，即文件实际内容的大小
    bytesToWrite = totalBytes - tcpClient->write(outBlock);
    outBlock.resize(0);
}

void Tcpclient::updateProgress(qint64 numBytes) //更新进度条，实现文件的传送
{
    //已经发送数据的大小
    bytesWritten += (int)numBytes;

    if(bytesToWrite > 0) {
       //如果已经发送了数据
       outBlock = localFile->read(qMin(bytesToWrite,loadSize));
       //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
       //就发送剩余数据的大小
       bytesToWrite -= (int)tcpClient->write(outBlock);
       //发送完一次数据后还剩余数据的大小
       outBlock.resize(0);
       //清空发送缓冲区
    } else {
        localFile->close(); //如果没有发送任何数据，则关闭文件
    }

    //更新进度条
    //发送完毕
    if(bytesWritten == totalBytes) {
        localFile->close();
        tcpClient->close();
    }
}

void Tcpclient::displayError(QAbstractSocket::SocketError) //显示错误
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
}
