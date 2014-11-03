#ifndef NETDEFINEDOBJECTPROPERTY_H
#define NETDEFINEDOBJECTPROPERTY_H

#include <string>

class NetDefinedObjectProperty
{
public:
    NetDefinedObjectProperty();

    int id;
    std::string name;
    std::string type;
    std::string defaultValue;
    int inTypeId;
    std::string inType;
};

#endif // NETDEFINEDOBJECTPROPERTY_H
