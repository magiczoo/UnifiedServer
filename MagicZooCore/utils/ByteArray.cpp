#include "ByteArray.h"



ByteArray::ByteArray():
    _size(0),
	_expandSize(0),
    _position(0),
    _bytes(nullptr)
{
}

ByteArray::~ByteArray()
{

}

void ByteArray::expandBytes(unsigned int minSize)
{

}

unsigned int ByteArray::getLength() const
{
    return 0;
}

unsigned int ByteArray::getPosition() const
{
	return 0;
}

void ByteArray::writeBytes(const char *bytes,unsigned int size)
{

}

void ByteArray::readBytes(const char *bytes, unsigned int size)
{

}

const char* ByteArray::getBytes() const
{
	return _bytes;
}