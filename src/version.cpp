#include"version.h"

Version::Version()
{
    version = "0.01";
	author = "@admirestator";
    copyright = "Copyright (C) admirestator 2012\n";
    versionInfo = copyright + "\tVersion\t" + version;
}

Version::~Version()
{

}

QString Version::getVersion () const
{
    return version;
}


QString Version::getAuthor () const
{
    return author;
}

QString Version::getCopyright() const
{
    return copyright;
}


QString Version::getVersionInfo() const
{
    return versionInfo;
}

