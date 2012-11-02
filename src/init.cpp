#include "init.h"

Init::Init()
{

#ifdef Q_WS_WIN
   cout << "Win32 Platform"  << endl;
#endif
#ifdef Q_WS_X11
   cout << "Linux/Unix Platform"  << endl;
#endif
#ifdef  Q_WS_MAC
   cout << "Mac OS Platform"  << endl;
#endif
}

Init::~Init()
{

}
