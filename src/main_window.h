#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QModelIndex>
#include <QHash>
#include <QString>

#include "host.h"
#include "chatwin.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
//class MainWindow : public MainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buildItems(const QHash <QString, User> &hostlist);

private slots:
    void userItemClicked(const QModelIndex &index);
    bool findUser(const QString &nickname,
                  const QString &ipaddr,
                  User &user);

private:
    Ui::MainWindow *ui;

    // a copy of Hostlist
    QHash <QString, User> copyHostlist;

    // for qtreeview
    QStandardItemModel *stdModel;
    quint32 treeModelRow;

    bool buildConnection();
};

#endif // MAINWINDOW_H
