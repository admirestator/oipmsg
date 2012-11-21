#include "chatwin.h"

ChatWin::ChatWin(const User &userinfo)
{
    userDataLocal = userinfo;
    userDlg = new UserDialog();
    buildConnection();

    run();

}

ChatWin::~ChatWin()
{

    delete userDlg;
}

void ChatWin::run()
{
    userDlg->show();
}

bool ChatWin::buildConnection()
{
    connect( userDlg, SIGNAL(gotFile(const QString&)),
            this, SLOT(sendfile(const QString&)) );

    return true;
}

void ChatWin::sendfile(const QString &filename)
{
    qDebug () << "SendFile++++";
    //QScopedPointer<Tcpclient> tcpSendFile(new Tcpclient(userDataLocal, filename));
    //Tcpclient tcpSendFile(userDataLocal, filename);
    //tcpSendFile = new Tcpclient(userDataLocal, filename);
    Tcpclient *tcpSendFile = new Tcpclient(userDataLocal, filename);

}


void ChatWin::senddir(const QString &filename)
{
    qDebug () << filename;
}
