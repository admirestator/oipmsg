#include"version.h"

Version::Version()
{
    QString version = "0.01";
    QString copyright = "Copyright (C) admirestator 2012\n";
    QString versionInfo = copyright + "\tVersion\t" + version;
}

Version::~Version()
{

}

QString Version::getVersion () const
{
    return version;
}


QString Version::getCopyright() const
{
    return copyright;
}


QString Version::getVersionInfo() const
{
    return versionInfo;
}

