#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    stdModel = new QStandardItemModel();
    //treeModelRow = 0;

    //stdModel->setHorizontalHeaderItem( 0, new QStandardItem( "Username" ) );
    //stdModel->setHorizontalHeaderItem( 1, new QStandardItem( "Mac" ) );
    ui->setupUi(this);

    //ui->treeViewUser->setModel(stdModel);

}

MainWindow::~MainWindow()
{
    delete stdModel;
    delete ui;
}

bool MainWindow::buildConnection()
{
    connect(ui->treeViewUser, SIGNAL(clicked(QModelIndex)),
            this, SLOT(clicked(QModelIndex)));
    return true;
}


void MainWindow::buildItems(const QHash <QString, User> &hostlist)
//void MainWindow::buildItems(QHash <QString, User> &hostlist)
{
    // reset treeview
    ui->treeViewUser->reset();

    treeModelRow = 0;
    stdModel->clear();
    QString key;
    foreach (key, hostlist.keys()) {
        QStandardItem *userItem = new QStandardItem((QString("%0").arg(hostlist[key].getNickName())));
        stdModel->setItem(treeModelRow, userItem);
        treeModelRow++;
    }

    stdModel->setHorizontalHeaderItem( 0, new QStandardItem( "Username" ) );
    //stdModel->setHorizontalHeaderItem( 1, new QStandardItem( "Mac" ) );
    ui->treeViewUser->setModel(stdModel);
}

void MainWindow::clicked(const QModelIndex &index)
 {
    qDebug() << "________clicked!";
    QStandardItem *item = stdModel->itemFromIndex(index);
    // Do stuff with the item ...
 }
