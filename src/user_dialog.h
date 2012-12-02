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
    void toSendMsg(const QHostAddress &hostip, const QString &packet);
    void toRecvMsg(const User &userinfo, const QString &packet);
    void toSendFile(const QHostAddress &hostip, const QString &filename);
    void toRecvFile(const QString &filename, const QByteArray &packet);
    void toSendDir(const User &userinfo, const QString &dirname);
    void toRecvDir(const QString &dirname, const QByteArray &packet);
    void updateLocalUserData(const User &userinfo);

signals:
     //Signal for msg and file operation
     void sendMsg(const QHostAddress &hostip, const QString &msg);
     void sendFile(const QHostAddress &hostip, const QString &filename);
     void sendDir(const User &userinfo, const QString &dirname);
     void winClosed(const QString &hostname);

private:
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
    //For UI display
    void showRecvMsg(const QString &msg);
    void showSendMsg(const QString &msg);

    //On buttons clicked
    void on_pushButtonFIle_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

};

#endif // USER_DIALOG_H
