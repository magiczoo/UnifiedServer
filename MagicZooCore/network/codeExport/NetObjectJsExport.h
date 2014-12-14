#ifndef NETOBJECTJSEXPORT_H
#define NETOBJECTJSEXPORT_H

#include "INetObjectCodeExport.h"

class NetObjectJsExport : public INetObjectCodeExport
{
public:
    NetObjectJsExport();

    // INetObjectCodeExport interface
public:
    void init(NetObjectProtocol protocol);
    std::string exportCode();
};

#endif // NETOBJECTJSEXPORT_H
