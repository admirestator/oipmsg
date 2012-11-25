#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QDesktopWidget>

namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

    void dlgDisplay();
    void dlgClose();
private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
