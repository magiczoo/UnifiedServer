#ifndef NETOBJECTXMLEXPORT_H
#define NETOBJECTXMLEXPORT_H

#include "INetObjectCodeExport.h"

class NetObjectXmlExport : public INetObjectCodeExport
{
public:
    NetObjectXmlExport();


    virtual void init(NetObjectProtocol protocol);

    virtual std::string exportCode();

};

#endif // NETOBJECTXMLEXPORT_H
