#include "setup_window.h"
#include "ui_setup_window.h"

SetupWindow::SetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetupWindow)
{

    //set initial position
    QDesktopWidget *desk=QApplication::desktop();
    move((desk->width()-width())/2,(desk->height()-height())/2);
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

void SetupWindow::on_buttonBox_clicked(QAbstractButton *button)
{
   close();
}
