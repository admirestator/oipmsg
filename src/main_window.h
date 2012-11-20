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

private:
    Ui::MainWindow *ui;
    bool buildConnection();

    // for qtreeview
    QStandardItemModel *stdModel;
    quint32 treeModelRow;
    void clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
