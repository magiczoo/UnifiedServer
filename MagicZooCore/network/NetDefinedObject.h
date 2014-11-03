#ifndef NETDEFINEDOBJECT_H
#define NETDEFINEDOBJECT_H
#include <string>
#include <vector>
#include "NetDefinedObjectProperty.h"
class NetDefinedObject
{
public:
    NetDefinedObject();

    int id;
    std::string name;
    std::vector<NetDefinedObjectProperty> property;

};

#endif // NETDEFINEDOBJECT_H
