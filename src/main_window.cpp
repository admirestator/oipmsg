#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stdModel = new QStandardItemModel();

    buildConnection();
}

MainWindow::~MainWindow()
{
    delete stdModel;
    delete ui;
}

bool MainWindow::buildConnection()
{
    connect(ui->treeViewUser, SIGNAL(doubleClicked(const QModelIndex&)),
            this, SLOT(userItemClicked(const QModelIndex&)));
    return true;
}


void MainWindow::buildItems(const QHash <QString, User> &hostlist)
{
    // reset treeview
    ui->treeViewUser->reset();

    // hold a copy of userlist
    copyHostlist.empty();
    copyHostlist = hostlist;

    treeModelRow = 0;
    stdModel->clear();
    QString key;
    foreach (key, hostlist.keys()) {
        QStandardItem *userItem = new QStandardItem((QString("%0     %1").arg(hostlist[key].getNickName())).arg (hostlist[key].getHostAddress().toString()));
        //QStandardItem *userItem = new QStandardItem((QString("%0").arg(hostlist[key].getNickName())));
        stdModel->setItem(treeModelRow, userItem);
        treeModelRow++;
    }

    stdModel->setHorizontalHeaderItem( 0, new QStandardItem("Username         IP") );
    ui->treeViewUser->setModel(stdModel);
}

void MainWindow::userItemClicked(const QModelIndex &index)
 {
    //QString itemInfo = itemindex.toString();
    QStringList infolist = index.data().toString().split(' ');

    User tmpuser;
    findUser(infolist.at(0), infolist.at(1), tmpuser);

    // new user windows...
    ChatWin *chatWin = new ChatWin(tmpuser);
    chatWin->run();
}


bool MainWindow::findUser(const QString &nickname,
                          const QString &ipaddr,
                          User &user)
{
    QString key;

    foreach (key, copyHostlist.keys()) {
        if ( nickname == copyHostlist[key].getNickName() &&
            ipaddr == copyHostlist[key].getHostAddress().toString() ) {
                user = copyHostlist[key];
                return true;
        }
    }

    return false;
}
