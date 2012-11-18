#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHash>
#include <QString>

#include "host.h"

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
    //void buildItems(QHash <QString, User> &hostlist);
    void addItem(const User &useritem);
    void delItem(const User &useritem);

private:
    Ui::MainWindow *ui;

    // for qtreeview
    QStandardItemModel *stdModel;
    quint32 treeModelRow;

};

#endif // MAINWINDOW_H
