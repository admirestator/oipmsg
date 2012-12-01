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

namespace Ui {
    class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();

    bool buildConnection();
    void setUserInfo(const QString &winTitle, const QString& info);

signals:
    void gotFile(const QString &filename);
    void sendMsg(const QString &content);
    void winClosed();

public slots:
    void showRecvMsg(const QString &nickname,
                     const QString &msg);
    void showSendMsg(const QString &msg);

private slots:
    void on_pushButtonFIle_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

private:
    Ui::UserDialog *ui;
    QWebView *webView;
    QFile *uiFile;
    QDateTime *timeWatch;

};

#endif // USER_DIALOG_H
