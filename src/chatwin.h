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
    Q_OBJECT
public:
    ChatWin(const User &userinfo);
    ~ChatWin();

    void run();

private:
    User userDataLocal;
    UserDialog *userDlg;
    //Tcpclient *tcpSendFile;

    bool buildConnection();

private slots:
    void sendfile(const QString &fliename);
    void senddir(const QString &filename);


};

#endif // CHATWIN_H
