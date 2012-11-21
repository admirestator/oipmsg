#include "user_dialog.h"
#include "ui_user_dialog.h"

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
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


void UserDialog::on_pushButtonFIle_clicked()
{

}

void UserDialog::on_pushButtonDir_clicked()
{

}


void UserDialog::on_pushButtonClose_clicked()
{
    this->close();
}


void UserDialog::on_pushButtonSend_clicked()
{

}
