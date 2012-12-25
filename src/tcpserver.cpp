#include "tcpserver.h"

Tcpserver::Tcpserver()
{
    protoobj = new Protocol();
    port = protoobj->port;
    tcpServer = new QTcpServer(this);

    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    bytesReceived =0;
    buildConnection();
}

Tcpserver::~Tcpserver()
{
    delete tcpServer;
}


void Tcpserver::run()
{
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


void Tcpserver::buildConnection()
{
    //connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
    //connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    //当发现新连接时发出newConnection()信号
}


void Tcpserver::recvFile()
{

}

void Tcpserver::recvDir()
{

}

void Tcpserver::acceptConnection()  //接受连接
{
    //tcpServerConnection = tcpServer.nextPendingConnection();
    //connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    //connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    tcpServer->close();
}

void Tcpserver::updateServerProgress()  //更新进度条，接收数据
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);

    if(bytesReceived <= sizeof(qint64)*2) {
        //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息
        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)
                && (fileNameSize == 0)) { //接收数据总大小信息和文件名大小信息
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }

        if((tcpServerConnection->bytesAvailable() >= fileNameSize)
                && (fileNameSize != 0)) {  //接收文件名，并建立文件
            in >> fileName;
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)) {
                qDebug() << "open file error!";
                return;
            }
        }
        else return;
    }

    if(bytesReceived < totalBytes) {  //如果接收的数据小于总数据，那么写入文件
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    //更新进度条
    if(bytesReceived == totalBytes) { //接收数据完成时
        tcpServerConnection->close();
        localFile->close();
    }
}

//错误处理
void Tcpserver::displayError(QAbstractSocket::SocketError)
{
    //qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    //ui->serverProgressBar->reset();
    //ui->serverStatusLabel->setText(tr("服务端就绪"));
    //ui->startButton->setEnabled(true);
}
