//function to display version info
#ifndef VERSION_H
#define VERSION_H

#include<QString>

namespace version {
    class Version;
};

class Version
{
private:
    QString version;
	QString author;
    QString copyright;
    QString versionInfo;

public:
    Version();
    virtual ~Version();

    QString getVersion() const;
    QString getAuthor() const;
    QString getCopyright() const;
    QString getVersionInfo() const;
};

#endif

