#include "chatwin.h"

ChatWin::ChatWin(const User &userinfo)
{
    userDlg = new UserDialog();

    run();
}

ChatWin::~ChatWin()
{

    delete userDlg;
}

void ChatWin::run()
{
    userDlg->show();
}

bool ChatWin::buildConnection()
{
    connect(userDlg->ui->pushButtonFIle, SIGNAL(clicked()), this, SLOT(on_pushButtonFIle_clicked()));
    connect(userDlg->ui->pushButtonDir, SIGNAL(clicked()), this, SLOT(on_pushButtonDir_clicked()));
    connect(userDlg->ui->pushButtonClose, SIGNAL(clicked()), this, SLOT(pushButtonClose_clicked()));
    connect(userDlg->ui->pushButtonSend, SIGNAL(clicked()), this, SLOT(on_pushButtonSend_clicked()));
}


void ChatWin::on_pushButtonFIle_clicked()
{
    //get file
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString fileName;

    if (dialog.exec())
        fileName = dialog.selectedFiles();
}

void ChatWin::on_pushButtonDir_clicked()
{
    //get dir
}

void ChatWin::on_pushButtonClose_clicked()
{
    this->close();
}

void ChatWin::on_pushButtonSend_clicked()
{
    // send info and build tcp client
}
