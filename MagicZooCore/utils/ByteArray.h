#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include "../Types.h"

class ByteArray
{
protected:
    uint _size;
	uint _expandSize;
	uint _position;
    byte* _bytes;
    void expandBytes(uint minSize);

 
public:
    ByteArray();
    virtual ~ByteArray();
    void writeBytes(const byte *bytes,uint size);
    void readBytes( byte *bytes,uint size);
    uint getLength() const;
    uint getPosition() const;
    void setPosition(uint value);
	const byte* getBytes() const;
};

#endif // BYTEARRAY_H
