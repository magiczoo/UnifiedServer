#include "NetworkLocalEndianness.h"

 bool NetworkLocalEndianness::isBigEndian()
{
	int n = 0x12345678;
	return *((char*)&n)==0x12 ? true : false;;
}

int16 NetworkLocalEndianness::toNextwork(int16 value)
{
	return value;
}

int32 NetworkLocalEndianness::toNextwork(int32 value)
{
	return value;
}

int64 NetworkLocalEndianness::toNextwork(int64 value)
{
	return value;
}

uint16 NetworkLocalEndianness::toNextwork(uint16 value)
{
	return value;
}

uint32 NetworkLocalEndianness::toNextwork(uint32 value)
{
	return value;
}

uint64 NetworkLocalEndianness::toNextwork(uint64 value)
{
	return value;
}

float NetworkLocalEndianness::toNextwork(float value)
{
	return value;
}

double NetworkLocalEndianness::toNextwork(double value)
{
	return value;
}

int16 NetworkLocalEndianness::toLocal(int16 value)
{
	return value;
}

int32 NetworkLocalEndianness::toLocal(int32 value)
{
	return value;
}

int64 NetworkLocalEndianness::toLocal(int64 value)
{
	return value;
}

uint16 NetworkLocalEndianness::toLocal(uint16 value)
{
	return value;
}

uint32 NetworkLocalEndianness::toLocal(uint32 value)
{
	return value;
}

uint64 NetworkLocalEndianness::toLocal(uint64 value)
{
	return value;
}

float NetworkLocalEndianness::toLocal(float value)
{
	return value;
}

double NetworkLocalEndianness::toLocal(double value)
{
	return value;
}