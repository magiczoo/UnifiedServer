#ifndef NETOBJECTPROTOCOL_H
#define NETOBJECTPROTOCOL_H

#include <string>
#include <vector>
#include <map>

class NetObjectProtocol
{
public:
    NetObjectProtocol(std::string protocolXml);

    std::vector<NetDefinedObject> definedObject;

    void fillDefaultValue(string name,std::map<std::string,std::string> object);

};

#endif // NETOBJECTPROTOCOL_H
