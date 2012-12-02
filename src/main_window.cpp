#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set initial position
    move((QApplication::desktop()->width()-width())/2,
         (QApplication::desktop()->width()-height())/2);

    stdModel = new QStandardItemModel();
    winList.empty();

    buildConnection();
    show();
}

MainWindow::~MainWindow()
{
    delete stdModel;
    QString key;
    foreach (key, winList.keys()) {
        delete winList[key];
    }
    delete ui;


}

UserDialog *MainWindow::singleton(const User &userinfo)
{
    // regard hostname as the userid
    QString userid = userinfo.getHostName();
    if (winList.find(userid) != winList.end()) {
        //qDebug () << "HasWin" << userinfo.getHostName();
        return winList[userid];
    } else {
        //qDebug () << "NoWin"<< userinfo.getHostName();

        UserDialog *tmpWin = new UserDialog(userinfo);
        winList.insert(userid, tmpWin);

        connect(winList[userid], SIGNAL(sendMsg(const QHostAddress&, const QString&)),
                this, SLOT(sendMsg(const QHostAddress&, const QString&)));
        connect(winList[userid], SIGNAL(sendFile(const QHostAddress&, const QString&)),
                this, SLOT(sendMsg(const QHostAddress&, const QString&)));

        // on chat window closed
        connect(winList[userid], SIGNAL(winClosed(const QString&)),
                this, SLOT(delWin(const QString&)));
        return winList[userid];
    }
}

bool MainWindow::delWin(const QString &userid)
{
    if (winList.find(userid) != winList.end()) {
        qDebug () << "DelWin" << userid;
        winList.remove(userid);
        return true;
    }
    return false;
}

bool MainWindow::buildConnection()
{
    connect(ui->treeViewUser, SIGNAL(doubleClicked(const QModelIndex&)),
            this, SLOT(userItemClicked(const QModelIndex&)));

    //program quit
    connect(ui->toolButtonRefresh, SIGNAL(clicked()), this, SLOT(onToolButtonRefreshClicked()));
    connect(ui->toolButtonSetting, SIGNAL(clicked()), this, SLOT(onToolButtonSettingClicked()));
    connect(ui->toolButtonAbout, SIGNAL(clicked()), this, SLOT(onToolButtonAboutClicked()));
    connect(ui->toolButtonQuit, SIGNAL(clicked()), this, SLOT(onToolButtonQuitClicked()));

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
        QStandardItem *userItem = new QStandardItem((QString("-%0       %1").
                                                    arg(hostlist[key].getNickName())).
                                                    arg(hostlist[key].getHostName()));
        stdModel->setItem(treeModelRow, userItem);
        treeModelRow++;
    }

    stdModel->setHorizontalHeaderItem(0, new QStandardItem("Username         Hostname"));
    ui->treeViewUser->setModel(stdModel);
}

void MainWindow::userItemClicked(const QModelIndex &index)
 {
    QStringList infolist = index.data().toString().split(' ');
    User tmpuser;
    findUser(infolist.at(7), tmpuser);

    // new user windows...
    UserDialog *userDlg = singleton(tmpuser);
    userDlg->show();
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

void MainWindow::sendMsg(const QHostAddress &hostip, const QString &msg)
{
    emit sendMsgInfo(hostip, msg);
}

void MainWindow::recvMsg(const QByteArray &packet)
{
    QList<QByteArray> argumentList = packet.split (':');
    User tmpuser;
    findUser(argumentList.at(3), tmpuser);

    UserDialog *userDlg = singleton(tmpuser);
    userDlg->show();
    userDlg->toRecvMsg(argumentList.at(5));
}


void MainWindow::onToolButtonRefreshClicked()
{
    //emit fresh
    emit refreshUser();
}

void MainWindow::onToolButtonSettingClicked()
{
    //new setting windows
    SetupWindow *setupWin = new SetupWindow();
    setupWin->winDisplay();

}

void MainWindow::onToolButtonAboutClicked()
{
    //new about windows
    AboutDialog *aboutDlg = new AboutDialog();
    aboutDlg->dlgDisplay();
}

void MainWindow::onToolButtonQuitClicked()
{
    //quit program
    QApplication::quit();
    emit quitApp();
}
