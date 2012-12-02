#include "setup_window.h"
#include "ui_setup_window.h"

SetupWindow::SetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetupWindow)
{
    //set initial position
    move((QApplication::desktop()->width()-width())/2,
         (QApplication::desktop()->width()-height())/2);

    ui->setupUi(this);
}

SetupWindow::~SetupWindow()
{
    delete ui;
}

void SetupWindow::winDisplay()
{
    show();
}

void SetupWindow::winClose()
{
    show();
}

void SetupWindow::on_buttonBox_clicked()
{
   close();
}
