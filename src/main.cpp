#include <QApplication>
#include <QMessageBox>

#include <iostream>

#include "main_window.h"
#include "systray.h"
#include "oipmsg.h"

using namespace std;

int main(int argc, char *argv[])
{
    //initial here



    //setup language here


    QApplication app(argc, argv);
    //MainWindow main_win;
    //main_win.show();


    //setup system tray
    //Systray system_tray;
    //system_tray.show();
    //if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    //    QMessageBox::critical(0, QObject::tr("Systray"),
    //                          QObject::tr("There's no system tray on this system!"));
    //    app.quit();
    //}


    Oipmsg oipmsg();

    return app.exec();
}
