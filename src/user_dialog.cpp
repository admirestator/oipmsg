#include "user_dialog.h"
#include "ui_user_dialog.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    /*
    QFile qss("chatstyle.qss");
    qss.open(QFile::ReadOnly);
    ui->setStyleSheet(qss.readAll());
    qss.close();
    */
    ui->setupUi(this);
}

UserDialog::~UserDialog()
{
    delete ui;
}


bool UserDialog::buildConnection()
{
    connect(ui->pushButtonFIle, SIGNAL(), this, SLOT(on_pushButtonFIle_clicked()));
    connect(ui->pushButtonDir, SIGNAL(), this, SLOT(on_pushButtonDir_clicked()));
    connect(ui->pushButtonClose, SIGNAL(), this, SLOT(on_pushButtonClose_clicked()));
    connect(ui->pushButtonSend, SIGNAL(), this, SLOT(on_pushButtonSend_clicked()));
    return true;
}

void UserDialog::setUserInfo(const QString &winTitle,
                             const QString &info)
{
    /*
    move((QApplication::desktop()->width() - ui->width())/2,
          QApplication::desktop()->height());
          */
    QDesktopWidget *desk=QApplication::desktop();
     int wd=desk->width();
     int ht=desk->height();
     move((wd-width())/2,(ht-height())/2);
    //ui->setWindowTitle(winTitle);
    setWindowTitle(winTitle);
    ui->labelUserInfo->setText(info);
}

void UserDialog::showMsg(const QString &msg)
//void UserDialog::showMsg(const QByteArray &packet)
{
    //QList<QByteArray> argumentList = packet.split (':');
    //ui->textBrowserUserGot->setPlainText(argumentList.at(5));
    ui->textBrowserUserGot->setPlainText(msg);
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
    emit sendMsg(ui->textEditUserEnter->toPlainText());
    ui->textEditUserEnter->clear();
}
