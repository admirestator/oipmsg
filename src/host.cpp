#include "host.h"

Host::Host()
{
    hostList.clear();
}


Host::~Host()
{

}

bool Host::addHost(const QByteArray &packet)
{
    QByteArray tmp = packet;
    return true;
}

bool Host::modifyHost(const HostInfo &hostInfo)
{
    const HostInfo tmp = hostInfo;
    return true;
}

bool Host::searchHost(const HostInfo &hostInfo)
{

    const HostInfo tmp = hostInfo;
    return true;
}


