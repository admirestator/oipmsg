#ifndef OIPMSG_H
#define OIPMSG_H

#include "udpserver.h"
#include "udpclient.h"

class Oipmsg
{
public:
    Oipmsg();
    virtual ~Oipmsg();

    Udpclient *udpClient;
    Udpserver *udpServer;

};

#endif // OIPMSG_H
