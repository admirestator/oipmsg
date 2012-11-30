#include "user_dialog.h"
#include "ui_user_dialog.h"


#include <unistd.h>

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    uiFile = new QFile("chat.html");
    if (!uiFile->open(QIODevice::ReadOnly)) {
        exit(1);
    }
    ui->webViewChat->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webViewChat->settings()->setAttribute(QWebSettings::PluginsEnabled,true);

    ui->webViewChat->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webViewChat->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QByteArray html = uiFile->readAll();
    ui->webViewChat->setHtml(html);
    uiFile->close();

    ui->webViewChat->show();
    timeWatch = new QDateTime();
}

UserDialog::~UserDialog()
{
    delete timeWatch;
    delete ui;
}


void UserDialog::setUserInfo(const QString &winTitle,
                             const QString &info)
{
    QDesktopWidget *desk=QApplication::desktop();
     int wd=desk->width();
     int ht=desk->height();
     move((wd-width())/2,(ht-height())/2);
    //ui->setWindowTitle(winTitle);
    setWindowTitle(winTitle);
    ui->labelUserInfo->setText(info);
}

void UserDialog::showRecvMsg(const QString &nickname, const QString &msg)
{
    qDebug () << msg;
    QString formatedMsg = "\"displayMsg('<li class=\"wordbox1\"><div class=\"arrow_box\"><h1 class=\"logo\">"
        + msg
        + "</h1></div><span class=\"wordtime\">"
        + timeWatch->time().currentTime().toString()
        + "</span><div style=\"clear:both;\"></div></li>')\"";
    qDebug () << ui->webViewChat->page()->mainFrame()->evaluateJavaScript(formatedMsg);

}

void UserDialog::showSendMsg(const QString &msg)
{
}

void UserDialog::on_pushButtonFIle_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    fileDialog->setFileMode(QFileDialog::AnyFile);
    if(fileDialog->exec() == QDialog::Accepted) {
        QString file = fileDialog->selectedFiles()[0];
        emit gotFile(file);

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
   qDebug () << "close event:" << this->close();

}


void UserDialog::on_pushButtonSend_clicked()
{
    if (!ui->textEditUserEnter->toPlainText().isEmpty()) {
        emit sendMsg(ui->textEditUserEnter->toPlainText());
    }

    ui->textEditUserEnter->clear();
}
