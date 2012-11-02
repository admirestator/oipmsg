#include <QApplication>

#include <iostream>

#include "main_window.h"
#include "systray.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Systray system_tray;
    system_tray.show();

#ifdef Q_WS_WIN
   cout << "Win32 Platform"  << endl;
#endif
#ifdef Q_WS_X11
   cout << "Linux/Unix Platform"  << endl;
#endif
#ifdef  Q_WS_MAC
   cout << "Mac OS Platform"  << endl;
#endif
    return a.exec();
}
