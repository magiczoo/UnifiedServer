#ifndef NETWORKLOCALENDIANNESS_H
#define NETWORKLOCALENDIANNESS_H
#include "../Types.h"
class NetworkLocalEndianness
{
public:

	/*
	
	�����绷����ʹ�ø��ֽڣ�����x86�Ļ�����ʹ�õ��ֽڡ�

	�ߵ��ֽ�����

	�ֽ� 0x12345678h

			Big-Endian	Little-Endian

	0�ֽ�		12h			78h

	1�ֽ�		34h			56h

	2�ֽ�		56h			34h

	3�ֽ�		78h			12h

	*/

	//���ص�ǰ�����Ƿ�Ϊ���ֽ�
	virtual bool isBigEndian();
	
	//������ת��Ϊ�����ֽڣ���
	int16 toNextwork(int16 value);

	int32 toNextwork(int32 value);

	int64 toNextwork(int64 value);
	
	uint16 toNextwork(uint16 value);

	uint32 toNextwork(uint32 value);

	uint64 toNextwork(uint64 value);

	float toNextwork(float value);

	double toNextwork(double value);

	//������ת��Ϊ�����ֽ�
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
