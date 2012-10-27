#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QMainWindow>

namespace Ui {
class SetupWindow;
}

class SetupWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SetupWindow(QWidget *parent = 0);
    ~SetupWindow();
    
private:
    Ui::SetupWindow *ui;
};

#endif // SETUPWINDOW_H
