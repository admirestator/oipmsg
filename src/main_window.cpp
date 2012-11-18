#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    stdModel = new QStandardItemModel();
    treeModelRow = 0;

    //stdModel->setHorizontalHeaderItem( 0, new QStandardItem( "Username" ) );
    //stdModel->setHorizontalHeaderItem( 1, new QStandardItem( "Bar-Baz" ) );
    ui->setupUi(this);

    ui->treeViewUser->setModel(stdModel);

}

MainWindow::~MainWindow()
{
    delete stdModel;
    delete ui;
}


void MainWindow::buildItems(const QHash <QString, User> &hostlist)
//void MainWindow::buildItems(QHash <QString, User> &hostlist)
{
    //QStandardItemModel stdModel
    QString key;
    foreach (key, hostlist.keys()) {
        treeModelRow++;
        QStandardItem *userItem = new QStandardItem((QString("%0").arg(hostlist[key].getNickName())));
        stdModel->setItem(treeModelRow, userItem);
    }

    //ui->treeViewUser->setModel(stdModel);
}


void MainWindow::addItem(const User &useritem)
{
    qDebug () << ">>>>>    add new user to treeview"
                 << useritem.getUserName ();
    // need to handle repeat item
    QStandardItem *userItem = new QStandardItem((QString("%0").arg(useritem.getNickName())));
    stdModel->setItem(treeModelRow, userItem);
}


void MainWindow::delItem(const User &useritem)
{
    treeModelRow--;
}
