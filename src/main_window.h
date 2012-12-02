#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>
#include <QHash>
#include <QString>

#include "host.h"
//#include "chatwin.h"
#include "user_dialog.h"
#include "setup_window.h"
#include "about_dialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buildItems(const QHash <QString, User> &hostlist);

signals:
    void sendMsgInfo(const QHostAddress&, const QString &msg);
    void sendFileInfo(const User &userinfo, const QString &msg);
    void refreshUser();
    void quitApp();

private slots:
    void userItemClicked(const QModelIndex &index);
    bool findUser(const QString &nickname, User &user);
    bool delWin(const QString &userid);

    // handle msg
    void sendMsg(const QHostAddress &hostip, const QString &msg);
    void recvMsg(const QByteArray &packet);

    void onToolButtonRefreshClicked();
    void onToolButtonSettingClicked();
    void onToolButtonAboutClicked();
    void onToolButtonQuitClicked();

private:
    Ui::MainWindow *ui;
    QHash <QString, UserDialog*> winList;
    UserDialog* singleton(const User &userinfo);

    // a copy of Hostlist
    QHash <QString, User> copyHostlist;

    // for qtreeview
    QStandardItemModel *stdModel;
    quint32 treeModelRow;

    bool buildConnection();
};

#endif // MAINWINDOW_H
