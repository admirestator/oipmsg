#include "setup_window.h"
#include "ui_setup_window.h"

SetupWindow::SetupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetupWindow)
{
    ui->setupUi(this);
}

SetupWindow::~SetupWindow()
{
    delete ui;
}
