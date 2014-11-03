#ifndef NETSCRIPTOBJECTBASE_H
#define NETSCRIPTOBJECTBASE_H

#include <string>
#include <map>
#include "NetObjectBase.h"

class NetScriptObjectBase : public NetObjectBase
{
protected:
    std::map<std::string,std::string> _object;

public:
    NetScriptObjectBase();
};

#endif // NETSCRIPTOBJECTBASE_H
