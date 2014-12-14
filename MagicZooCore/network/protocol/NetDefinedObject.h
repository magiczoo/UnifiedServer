#ifndef NETDEFINEDOBJECT_H
#define NETDEFINEDOBJECT_H
#include <string>
#include <vector>
#include <unordered_map>
#include "NetDefinedObjectProperty.h"
class NetDefinedObject
{
public:
    NetDefinedObject();

    int id;
    std::string name;
    std::vector<NetDefinedObjectProperty*> property;
	std::unordered_map<std::string, NetDefinedObjectProperty*> propertyMap;

};

#endif // NETDEFINEDOBJECT_H
