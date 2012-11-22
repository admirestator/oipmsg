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
    userDlg->show();
}

void ChatWin::buildConnection()
{
    /*
    connect(userDlg, SIGNAL(gotFile(const User&, const QString&)),
            this, SLOT(sendFile(const User&, const QString&));
            */

    connect(userDlg, SIGNAL(gotFile(const QString&)),
            this, SLOT(sendFile(const QString&)));
}

void ChatWin::sendFile(const QString &filename)
{
    qDebug () << "send " << filename;
    Tcpclient *fileClient = new Tcpclient(userDataLocal, filename);

}
