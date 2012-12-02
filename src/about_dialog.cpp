#include "about_dialog.h"
#include "ui_about_dialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    //set initial position
    move((QApplication::desktop()->width()-width())/2,
         (QApplication::desktop()->width()-height())/2);

    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::dlgDisplay()
{
    show();
}

void AboutDialog::dlgClose()
{
    close();
}

//void AboutDialog::on_buttonBoxOk_clicked(QAbstractButton *button)
void AboutDialog::on_buttonBoxOk_clicked()
{
   close();
}
