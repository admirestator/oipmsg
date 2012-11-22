#include "tcpclient.h"

//Tcpclient::Tcpclient(const QHostAddress &dstip, const QString &filename)
Tcpclient::Tcpclient(const User &userinfo, const QString &filename)
{
    port = IPMSG_DEFAULT_PORT;
    fileName = filename;
    destIP = userinfo.getHostAddress();
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

}

Tcpclient::~Tcpclient()
{
    delete tcpClient;
    delete localFile;
}

void Tcpclient::run()
{
    tcpClient->connectToHost(destIP, port);
}

bool Tcpclient::buildConnection()
{
    return true;
}

bool Tcpclient::startTransfer()
{
    if (!localFile->open(QFile::ReadOnly )) {
        /*
        QMessageBox::warning(this, tr("Ó¦ÓÃ³ÌÐò"),
                             tr("ÎÞ err %1:\n%2.")
                             .arg(fileName)
                             .arg(localFile->errorString()));
       */

        return false;
    }

    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);

    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    TotalBytes +=  outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = TotalBytes - tcpClient->write(outBlock);
    qDebug()<<currentFile<<TotalBytes;
    outBlock.resize(0);

    return true;
}
