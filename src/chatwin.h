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
    UserDialog *userDlg;
    User userDataLocal;

    void buildConnection();

private slots:
    void sendFile(const QString &filename);

};

#endif // CHATWIN_H
