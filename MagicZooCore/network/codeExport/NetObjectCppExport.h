#ifndef NETOBJECTCPPEXPORT_H
#define NETOBJECTCPPEXPORT_H

#include "INetObjectCodeExport.h"

class NetObjectCppExport : public INetObjectCodeExport
{
public:
    NetObjectCppExport();

    // INetObjectCodeExport interface
public:
    void init(NetObjectProtocol protocol);
    std::string exportCode();
};

#endif // NETOBJECTCPPEXPORT_H
