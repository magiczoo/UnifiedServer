#ifndef BYTEARRAY_H
#define BYTEARRAY_H

class ByteArray
{
protected:
    unsigned int _size;
    unsigned int _position;
    char *_bytes;

    void expandBytes(unsigned int minSize=0);

public:
    ByteArray();
    ~ByteArray();
    void writeBytes(const char *bytes,unsigned int size);
    void readBytes(const char *bytes,unsigned int size);
    unsigned int getLength();
    unsigned int getPosition();
    void setPosition(unsigned int value);
};

#endif // BYTEARRAY_H
