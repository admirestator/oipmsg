#include<QString>
#include"version.h"

QString GetVersionStr()
{
    QString version = "0.01";
    QString copy = "Copyright (C) admirestator 2012\n";
    QString version_info = copy + "\tVersion\t" + version;
    return version_info;
}


