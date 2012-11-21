#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    
private:
    Ui::UserDialog *ui;
};

#endif // USER_DIALOG_H
