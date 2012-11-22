#include "main_window.h"
#include "ui_main_window.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stdModel = new QStandardItemModel();

    winList.empty();
    buildConnection();
}

MainWindow::~MainWindow()
{

    delete stdModel;
    //delete all chatWin
    delete ui;
}

ChatWin *MainWindow::singleton(const User &userinfo)
//QScopedPointer<ChatWin>& MainWindow::singleton(const User &userinfo)
{
    //userinfo.displayHostInfo ();
    // regard hostname as the userid
    QString userid = userinfo.getHostName();
    if (winList.find(userid) != winList.end()) {
        qDebug () << "HasWin" << userinfo.getHostName();
        return winList[userid];
    } else {
        qDebug () << "NoWin"<< userinfo.getHostName();
        ChatWin *tmpWin = new ChatWin(userinfo);
        //QScopedPointer<ChatWin> tmpWin(new ChatWin(userinfo));

        winList.insert(userid, tmpWin);
        connect(winList[userid], SIGNAL(sendInfo(const User&, const QString&)),
                this, SLOT(sendMsg(const User&, const QString&)));
        return winList[userid];
    }
}

bool MainWindow::buildConnection()
{
    connect(ui->treeViewUser, SIGNAL(doubleClicked(const QModelIndex&)),
            this, SLOT(userItemClicked(const QModelIndex&)));

    // on chat window closed
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
        QStandardItem *userItem = new QStandardItem((QString("%0  %1  %2").
                                                    arg(hostlist[key].getNickName())).
                                                    arg(hostlist[key].getHostName()).
                                                    arg(hostlist[key].getHostAddress().toString ()));
        stdModel->setItem(treeModelRow, userItem);
        treeModelRow++;
    }

    stdModel->setHorizontalHeaderItem( 0, new QStandardItem("Username  Hostname    IP") );
    ui->treeViewUser->setModel(stdModel);
}

void MainWindow::userItemClicked(const QModelIndex &index)
 {
    QStringList infolist = index.data().toString().split(' ');
    qDebug () << infolist;
    User tmpuser;
    findUser(infolist.at(2), tmpuser);

    // new user windows...
    ChatWin *chatWin = singleton(tmpuser);
    chatWin->run();
}


bool MainWindow::findUser(const QString &hostname, User &user)
{
    QString key;
    foreach (key, copyHostlist.keys()) {
        if (!key.isEmpty() && hostname == copyHostlist[key].getHostName()) {
            user = copyHostlist[key];
            return true;
        }
    }
    return false;
}

void MainWindow::sendMsg(const User &userinfo, const QString &msg)
{
    emit sendInfo(userinfo.getHostAddress(), msg);
    User tmpuser;
    findUser(userinfo.getHostName(), tmpuser);

    ChatWin *chatWin = singleton(tmpuser);
    chatWin->userDlg->showMsg(msg);
}

void MainWindow::recvMsg(const QByteArray &packet)
{
    QList<QByteArray> argumentList = packet.split (':');
    User tmpuser;
    findUser(argumentList.at(3), tmpuser);

    ChatWin *chatWin = singleton(tmpuser);
    chatWin->userDlg->showMsg(argumentList.at(5));
    chatWin->run();
}
