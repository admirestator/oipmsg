

#include "init.h"

Init::Init()
{

#ifdef Q_WS_WIN
   qDebug() << "Win32";
#endif
#ifdef Q_WS_X11
   qDebug() << "Linux/Unix";
#endif
#ifdef  Q_WS_MAC
   qDebug() << "Mac OS X";;
#endif
}

Init::~Init()
{

}
