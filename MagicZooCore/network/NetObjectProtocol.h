#ifndef NETOBJECTPROTOCOL_H
#define NETOBJECTPROTOCOL_H

#include <string>
#include <vector>
#include <map>
#include "NetDefinedObject.h"

class NetObjectProtocol
{
public:
    NetObjectProtocol(std::string protocolXml);

    std::vector<NetDefinedObject> definedObject;

    void fillDefaultValue(std::string name,std::map<std::string,std::string> object);

};

#endif // NETOBJECTPROTOCOL_H
