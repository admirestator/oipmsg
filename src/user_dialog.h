#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

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
    void sendMsg(const QString &content);

public slots:
    //void showMsg(const QByteArray &packet);
    void showMsg(const QString &msg);

private slots:
    void on_pushButtonFIle_clicked();
    void on_pushButtonDir_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonSend_clicked();

private:
    Ui::UserDialog *ui;
};

#endif // USER_DIALOG_H
