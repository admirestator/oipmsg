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
    this->close();
}


void UserDialog::on_pushButtonSend_clicked()
{

}
