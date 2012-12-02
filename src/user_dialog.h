#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDateTime>
#include <QWebView>
#include <QWebFrame>
#include <QFile>
#include <QThread>
#include <QDebug>

#include "user.h"

namespace Ui {
    class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserDialog(const User &userinfo, QWidget *parent = 0);
    ~UserDialog();

public slots:
    //Slots for msg and file operation
    void toSendMsg(const QByteArray &packet);
    void toSendFile(const QString &filename);
    void toRecvFile(const QString &filename, const QByteArray &packet);

    //For UI display
    void showRecvMsg(const QString &nickname, const QString &msg);
    void showSendMsg(const QString &msg);

signals:
    //Signal for msg and file operation
    void sendMsg(const User &userinfo, const QString &msg);
    void sendFile(const QString &filename);
    void winClosed();

private:
    //Userinfo in local
    User userDataLocal;

    //UI Widget
    Ui::UserDialog *ui;
    QWebView *webView;
    QFile *uiFile;
    QDateTime *timeWatch;

    //Build self signals and slots
    bool buildConnection();
    void setUserInfo(const QString &winTitle, const QString& info);

private slots:
    void on_pushButtonFIle_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

};

#endif // USER_DIALOG_H
