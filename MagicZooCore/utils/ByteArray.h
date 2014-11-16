#ifndef BYTEARRAY_H
#define BYTEARRAY_H

class ByteArray
{
protected:
    unsigned int _size;
	unsigned int _expandSize;
    unsigned int _position;
    char* _bytes;
    void expandBytes(unsigned int minSize);
 
public:
    ByteArray();
    virtual ~ByteArray();
    void writeBytes(const char *bytes,unsigned int size);
    void readBytes( char *bytes,unsigned int size);
    unsigned int getLength() const;
    unsigned int getPosition() const;
    void setPosition(unsigned int value);
	const char* getBytes() const;
};

#endif // BYTEARRAY_H
