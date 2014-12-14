#ifndef NETOBJECTLUAEXPORT_H
#define NETOBJECTLUAEXPORT_H

#include "INetObjectCodeExport.h"

class NetObjectLuaExport : public INetObjectCodeExport
{
public:
    NetObjectLuaExport();

    // INetObjectCodeExport interface
public:
    void init(NetObjectProtocol protocol);
    std::string exportCode();
};

#endif // NETOBJECTLUAEXPORT_H
