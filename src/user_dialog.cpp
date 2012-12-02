#include "user_dialog.h"
#include "ui_user_dialog.h"

UserDialog::UserDialog(const User &userinfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    userDataLocal = userinfo;
    timeWatch = new QDateTime();

    //Set initial position
    move((QApplication::desktop()->width()-width())/2,
         (QApplication::desktop()->width()-height())/2);

    ui->setupUi(this);
    ui->webViewChat->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webViewChat->settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    ui->webViewChat->load (QUrl("chat.html"));
    setUserInfo();
    show();
}

UserDialog::~UserDialog()
{
    delete timeWatch;
    delete ui;
}


void UserDialog::setUserInfo()
{
    //Window title
    setWindowTitle(userDataLocal.getNickName());
    ui->labelUserInfo->setText(QString("%0   [%1]")
                               .arg(userDataLocal.getHostName())
                               .arg(userDataLocal.getHostAddress().toString()));
}

void UserDialog::toSendMsg(const QString &msg)
{
    emit sendMsg(userDataLocal.getHostAddress(), msg);
}

void UserDialog::toRecvMsg(const QString &msg)
{
    showRecvMsg(msg);

}

void UserDialog::toSendFile(const QString &filename)
{
    Tcpclient tcpClient(userDataLocal,filename);

}

void UserDialog::toRecvFile()
{
    Tcpserver tcpServer;
}

void UserDialog::toSendDir(const QString &dirname)
{
    Tcpclient tcpClient(userDataLocal, dirname);

}

void UserDialog::toRecvDir()
{
    Tcpserver tcpServer;
}

void UserDialog::updateLocalUserData(const User &userinfo)
{
    userDataLocal = userinfo;
}

void UserDialog::showRecvMsg(const QString &msg)
{
    //qDebug () << msg;
    QString formatedMsg = "displayMsg('<li class=\"wordbox1\"><div class=\"arrow_box\"><h1 class=\"logo\">"
        + msg
        + "</h1></div><span class=\"wordtime\">"
        + timeWatch->time().currentTime().toString()
        + "</span><div style=\"clear:both;\"></div></li>')";
    ui->webViewChat->page()->mainFrame()->evaluateJavaScript(formatedMsg);
}

void UserDialog::showSendMsg(const QString &msg)
{
    //qDebug () << msg;
    QString formatedMsg = "displayMsg('<li class=\"wordbox2\"><div class=\"arrow_box\"><h1 class=\"logo\">"
        + msg
        + "</h1></div><span class=\"wordtime\">"
        + timeWatch->time().currentTime().toString()
        + "</span><div style=\"clear:both;\"></div></li>')";
    ui->webViewChat->page()->mainFrame()->evaluateJavaScript(formatedMsg);
}

void UserDialog::on_pushButtonFIle_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    fileDialog->setFileMode(QFileDialog::AnyFile);
    if(fileDialog->exec() == QDialog::Accepted) {
        QString file = fileDialog->selectedFiles()[0];
        emit sendFile(userDataLocal.getHostAddress(), file);

        //QMessageBox::information(NULL, tr("File"), tr("You selected ") + file);
    } else {
        QMessageBox::information(NULL, tr("File"), tr("You didn't select any files."));
    }
}

void UserDialog::on_pushButtonDir_clicked()
{

}


void UserDialog::on_pushButtonClose_clicked()
{
    close();
    emit winClosed(userDataLocal.getHostName());
}


void UserDialog::on_pushButtonSend_clicked()
{
    QString msg = ui->textEditUserEnter->toPlainText();
    if (!msg.isEmpty()) {
        toSendMsg(msg);
        showSendMsg(msg);
    }

    ui->textEditUserEnter->clear();
}
