// This file is part of QIpMsg.
//
// QIpMsg is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QIpMsg is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QIpMsg.  If not, see <http://www.gnu.org/licenses/>.
//


/*
#include "window_manager.h"
#include "global.h"
#include "preferences.h"
#include "user_manager.h"
#include "helper.h"
#include "transfer_file_window.h"

*/

#include "systray.h"
#include "main_window.h"
#include "setup_window.h"
#include "about_dialog.h"

#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QStandardItemModel>
#include <QtDebug>


Systray::Systray(QObject *parent)
    : QObject(parent)
{
    trayIcon = new QSystemTrayIcon;

    createActions();
    createMenus();

    createConnections();

    startTimer(500);

    m_iconKey = "normal";
    //trayIcon->setIcon(*Global::iconSet.value(m_iconKey));
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setToolTip(tr("IP Messenger(%1)").arg(0));
}

Systray::~Systray()
{
    delete trayIcon;
    trayIcon = 0;
}

//void Systray::updateToolTip(int i)
void Systray::updateToolTip()
{
    //trayIcon->setToolTip(tr("IP Messenger (%1)").arg(i));
    trayIcon->setToolTip(tr("Open IP Messenger"));
}

void Systray::createActions()
{
    topWindowAction = new QAction(tr("Top all windows"), 0);
    setupAction = new QAction(tr("Setup"), 0);
    aboutQtAction = new QAction(tr("About Qt"), 0);
    aboutAction = new QAction(tr("About"), 0);
    readMsgLogAction = new QAction(tr("Log"), 0);
    quitAction = new QAction(tr("Quit"), 0);
}

void Systray::createMenus()
{
    trayIconMenu = new QMenu;

    //trayIconMenu->addAction(showTransferFileAction);

    trayIconMenu->addSeparator();
    //trayIconMenu->addAction(delAckWindowAction);
    trayIconMenu->addAction(topWindowAction);

    trayIconMenu->addSeparator();
    trayIconMenu->addAction(setupAction);
    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addAction(readMsgLogAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(aboutQtAction);

    trayIconMenu->addSeparator();
    leaveMenu = new QMenu(tr("Leave"));
    leaveMenu->setEnabled(false);
    createLeaveMenu();
    trayIconMenu->addMenu(leaveMenu);

    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
}

void Systray::createLeaveMenu()
{
    // XXX TODO: not finished yet.
}

void Systray::show()
{
    trayIcon->show();
}

void Systray::createConnections()
{
    //connect(showTransferFileAction, SIGNAL(triggered()),
    //        this, SLOT(showTransferFile()));

    connect(setupAction, SIGNAL(triggered()), this, SLOT(setup()));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    //connect(topWindowAction, SIGNAL(triggered()),
    //        this, SLOT(setAllWindowVisible()));
    //connect(readMsgLogAction, SIGNAL(triggered()),
    //        this, SLOT(readLog()));

}

void Systray::setup()
{
    SetupWindow *setupWindow = new SetupWindow();
    setupWindow->show();
}

void Systray::about()
{
    AboutDialog *about = new AboutDialog;
    about->setWindowFlags(Qt::Widget);
    about->show();
}

void Systray::quit()
{
    //destroyMainWindowList();

    qApp->quit();
}

void Systray::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        break;

    default:
        break;
    }
}

void Systray::createMainWindow()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();

    // prepend mainWindow to the list
    //mainWindowList.insert(0, mainWindow);
}
