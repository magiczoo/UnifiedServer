#ifndef NETWORKLOCALENDIANNESS_H
#define NETWORKLOCALENDIANNESS_H
#include "../Types.h"
class NetworkLocalEndianness
{
public:

	/*
	
	在网络环境中使用高字节，而在x86的环境中使用低字节。

	高低字节区别：

	字节 0x12345678h

			Big-Endian	Little-Endian

	0字节		12h			78h

	1字节		34h			56h

	2字节		56h			34h

	3字节		78h			12h

	*/

	//返回当前本地是否为高字节
	virtual bool isBigEndian();
	
	//将数据转换为网络字节（）
	int16 toNextwork(int16 value);

	int32 toNextwork(int32 value);

	int64 toNextwork(int64 value);
	
	uint16 toNextwork(uint16 value);

	uint32 toNextwork(uint32 value);

	uint64 toNextwork(uint64 value);

	float toNextwork(float value);

	double toNextwork(double value);

	//将数据转换为本地字节
	int16 toLocal(int16 value);

	int32 toLocal(int32 value);

	int64 toLocal(int64 value);

	uint16 toLocal(uint16 value);

	uint32 toLocal(uint32 value);

	uint64 toLocal(uint64 value);

	float toLocal(float value);

	double toLocal(double value);


};

#endif // NETWORKLOCALENDIANNESS_H
