#include <QApplication>
#include <QMessageBox>
#include <QObject>

#include "systray.h"
#include "oipmsg.h"

int main(int argc, char *argv[])
{
    //initial here

    QApplication *app = new QApplication(argc, argv);

    //setup system tray
    Systray *systemTray = new Systray();
    systemTray->show();
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("There's no system tray on this system!"));
        app->quit();
    }

    Oipmsg *oipmsg = new Oipmsg();
    oipmsg->run();

    return app->exec();
}
