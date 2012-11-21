#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

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
signals:
    void gotFile(const QString &filename);

private slots:
    void on_pushButtonFile_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

private:
    Ui::UserDialog *ui;
};

#endif // USER_DIALOG_H
