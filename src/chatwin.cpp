#include "chatwin.h"

ChatWin::ChatWin(const User &userinfo)
{
    userDlg = new UserDialog();

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
