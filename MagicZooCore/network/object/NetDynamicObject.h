#ifndef NETDYNAMICOBJECT_H
#define NETDYNAMICOBJECT_H

#include <string>
#include <map>
#include "NetObjectBase.h"

class NetDynamicObject : public NetObjectBase
{
protected:
    std::map<std::string,std::string> _object;

public:
	NetDynamicObject();
};

#endif // NETDYNAMICOBJECT_H
