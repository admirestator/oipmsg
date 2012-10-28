//class for tcp/ip communication

#ifndef COMM_H
#define COMM_H

#include "protocol.h"

namespace comm{
    class Comm;
};

class Comm : public Protocol
{
public:
    Comm();
};

#endif // COMM_H
