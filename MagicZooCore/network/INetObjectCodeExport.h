#ifndef INETOBJECTCODEEXPORT_H
#define INETOBJECTCODEEXPORT_H

#include <string>
#include "NetObjectProtocol.h"

class INetObjectCodeExport
{
public:
    virtual INetObjectCodeExport(){}
    virtual ~INetObjectCodeExport()=0;

    virtual void init(NetObjectProtocol protocol)=0;

    virtual std::string exportCode()=0;


};

#endif // INETOBJECTCODEEXPORT_H
