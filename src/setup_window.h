#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QDesktopWidget>
#include <QThread>
#include "user.h"

namespace Ui {
    class SetupWindow;
}

class SetupWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SetupWindow(QWidget *parent = 0);
    ~SetupWindow();

    void winDisplay();
    void winClose();

    void userInfoUpdated(const User &userDataLocal);
private slots:
    //void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_clicked();

private:
    Ui::SetupWindow *ui;
    QDesktopWidget *desk;
};

#endif // SETUPWINDOW_H
