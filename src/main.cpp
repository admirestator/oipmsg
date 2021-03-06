#include <QApplication>
#include <QMessageBox>
#include <QObject>

#include <iostream>

#include "main_window.h"
//#include "screenshot.h"
#include "systray.h"
#include "oipmsg.h"

using namespace std;

bool buildConnection(const Oipmsg *oipmsgobj, const MainWindow *mainwinobj);


int main(int argc, char *argv[])
{
    //initial here



    //setup language here


    QApplication *app = new QApplication(argc, argv);
    MainWindow *mainWin = new MainWindow();
    mainWin->show();


    //setup system tray
    Systray *system_tray = new Systray();
    system_tray->show();
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("There's no system tray on this system!"));
        app->quit();
    }


    /*
    Screenshot screenshot;
    screenshot.show();
    */

    Oipmsg *oipmsg = new Oipmsg();
    oipmsg->run();

    buildConnection (oipmsg, mainWin);
    QObject::connect(mainWin, SIGNAL(quitApp()),
                     app, SLOT(quit()));
    return app->exec();

    delete oipmsg;
    delete mainWin;
}


//bool buildConnection(const MainWindow &mainwinobj, const Oipmsg &oipmsgobj)
bool buildConnection(const Oipmsg *oipmsgobj, const MainWindow *mainwinobj)
{
    //QObject::connect (mainwinobj, SIGNAL(), oipmsgobj, SLOT());
    //QObject::connect (oipmsgobj, SIGNAL(), mainwinobj, SLOT());

    /*
    QObject::connect (oipmsgobj, SIGNAL(newuser(const User&)),
                      mainwinobj, SLOT(addItem(const User&)));
                      */
    QObject::connect (oipmsgobj,
                      SIGNAL(alluser(const QHash <QString, User> &)),
                      mainwinobj,
                      SLOT(buildItems(const QHash <QString,User> &)));

    // send user info
    QObject::connect(mainwinobj,
                     SIGNAL(sendInfo(const QHostAddress&, const QString&)),
                     oipmsgobj->udpServer,
                     SLOT(sendcmdSendmsg(const QHostAddress&, const QString&)));

    // recv user info
    QObject::connect(oipmsgobj->udpServer,
                     SIGNAL(gotMsg(const QByteArray&)),
                     mainwinobj,
                     SLOT(recvMsg(const QByteArray&)));
    /*emit recvMsg (ipaddr, packet);
    QObject::connect(mainwinobj, SIGNAL(sendInfo(const User&, const QString&)),
                     oipmsgobj->udpServer, SLOT(processSendmsg(const User&, const QString&)));
                      */

    // emit refresh
    QObject::connect(mainwinobj,
                     SIGNAL(refreshUser()),
                     oipmsgobj->udpServer,
                     SLOT(sendcmdBrEntry()));

    return true;
}
