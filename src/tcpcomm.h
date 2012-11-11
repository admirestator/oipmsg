//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

#include "protocol.h"

namespace tcpcomm{
    class Tcpcomm;
};

class Tcpcomm : public Protocol
{
public:
    Tcpcomm();
    ~Tcpcomm();
};

#endif // COMM_H
