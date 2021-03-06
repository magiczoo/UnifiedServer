#ifndef NETOBJECTBASE_H
#define NETOBJECTBASE_H

#include "../../utils/ByteArray.h"
#include "../protocol/NetDefinedObject.h"
#include "../protocol/NetObjectProtocol.h"

class NetObjectBase
{

protected:
    NetDefinedObject *_type;
    NetObjectProtocol *_protocol;

public:
    NetObjectBase();
    virtual ~NetObjectBase();
    virtual void init(NetDefinedObject *type,NetObjectProtocol *protocol);
    virtual void load(ByteArray *bytes);
    virtual void save(ByteArray *bytes);
};

#endif // NETOBJECTBASE_H
