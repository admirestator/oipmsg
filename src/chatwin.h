#ifndef CHATWIN_H
#define CHATWIN_H

#include <QThread>
#include <QFileDialog>
#include <QDebug>

#include "user.h"
#include "user_dialog.h"
#include "tcpclient.h"

class ChatWin : public QThread
{
public:
    ChatWin(const User &userinfo);
    ~ChatWin();

    void run();

private:
    UserDialog *userDlg;


};

#endif // CHATWIN_H
