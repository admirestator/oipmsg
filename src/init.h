// class for oipmsg initial
#ifndef INIT_H
#define INIT_H

#include <QString>

namespace init{
    class Init;
};

class Init
{
public:
    Init();
    virtual ~Init();


private:
    QString language;
};

#endif // INIT_H
