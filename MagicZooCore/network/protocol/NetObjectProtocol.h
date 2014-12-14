#ifndef NETOBJECTPROTOCOL_H
#define NETOBJECTPROTOCOL_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "NetDefinedObject.h"

class NetObjectProtocol
{
public:
    NetObjectProtocol(std::string protocolXml);

    std::vector<NetDefinedObject*> definedObject;
	std::unordered_map<std::string, NetDefinedObject*> definedObjectMap;


    void fillDefaultValue(std::string name,std::map<std::string,std::string> object);

};

#endif // NETOBJECTPROTOCOL_H
