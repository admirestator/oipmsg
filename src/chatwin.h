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

    UserDialog *userDlg;

signals:
    void sendInfo(const User &userinfo, const QString &msg);

private slots:
    void sendMsg(const QString &msg);

private:
    User userDataLocal;

    void buildConnection();

private slots:
    void sendFile(const QString &filename);
    void recvMsg (const QByteArray &packet);
};

#endif // CHATWIN_H
