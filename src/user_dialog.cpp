#include "user_dialog.h"
#include "ui_user_dialog.h"

UserDialog::UserDialog(const User &userinfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    userDataLocal = userinfo;
    ui->setupUi(this);
    ui->webViewChat->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webViewChat->settings()->setAttribute(QWebSettings::PluginsEnabled,true);

    ui->webViewChat->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webViewChat->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webViewChat->load (QUrl("chat.html"));

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
    QString formatedMsg = "displayMsg('<li class=\"wordbox1\"><div class=\"arrow_box\"><h1 class=\"logo\">"
        + msg
        + "</h1></div><span class=\"wordtime\">"
        + timeWatch->time().currentTime().toString()
        + "</span><div style=\"clear:both;\"></div></li>')";
    ui->webViewChat->page()->mainFrame()->evaluateJavaScript(formatedMsg);
}

void UserDialog::showSendMsg(const QString &msg)
{
    qDebug () << msg;
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
    emit winClosed();

}


void UserDialog::on_pushButtonSend_clicked()
{
    if (!ui->textEditUserEnter->toPlainText().isEmpty()) {
        //displaly msg
        emit sendMsg(ui->textEditUserEnter->toPlainText());

    }

    ui->textEditUserEnter->clear();
}
