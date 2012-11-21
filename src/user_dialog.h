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

    bool buildConnection();

private slots:
    void on_pushButtonFIle_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

private:
    Ui::UserDialog *ui;
};

#endif // USER_DIALOG_H
