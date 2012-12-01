#include "chatwin.h"

ChatWin::ChatWin(const User &userinfo)
{
    userDlg = new UserDialog();
    userDataLocal = userinfo;

    buildConnection();
    run();
}

ChatWin::~ChatWin()
{

    delete userDlg;
}

void ChatWin::run()
{
    QString userinfo = userDataLocal.getHostName ()
            + "   ["
            + userDataLocal.getHostAddress ().toString ()
            + "]";
    QString title = userDataLocal.getNickName ();
    userDlg->setUserInfo(title, userinfo);
    userDlg->show();
}

void ChatWin::buildConnection()
{
    connect(userDlg, SIGNAL(gotFile(const QString&)),
            this, SLOT(sendFile(const QString&)));

    connect(userDlg, SIGNAL(sendMsg(const QString&)),
            this, SLOT(sendMsg(const QString&)));

    // win closed
    connect(userDlg, SIGNAL(winClosed()),
            this, SLOT(chatWinClosed()));
}

void ChatWin::sendFile(const QString &filename)
{
    // sendfil-------------------------------e
    Tcpclient fileClient(userDataLocal, filename);
}


void ChatWin::sendMsg(const QString &msg)
{
    emit sendInfo(userDataLocal, msg);
}

void ChatWin::recvMsg(const QByteArray &packet)
{

}

void ChatWin::chatWinClosed()
{
    qDebug () << "closed";
    emit windowClosed (userDataLocal.getHostName());
}
