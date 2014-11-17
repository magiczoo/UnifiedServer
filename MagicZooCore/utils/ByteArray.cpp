#include "ByteArray.h"
#include "string"


ByteArray::ByteArray() :
_size(0),
_expandSize(0),
_position(0),
_bytes(nullptr)
{

	
}

ByteArray::~ByteArray()
{
	free(_bytes);
}

void ByteArray::expandBytes(unsigned int minSize)
{
	unsigned int freesize = _expandSize - _position;//ָ�Ϻ����ʣ��ռ�
	freesize == 0 ? freesize = (minSize) : freesize;//���û�пռ�ֱ������չĿ�����ݴ�С
	while (freesize  < minSize){ //һֱ��չ���ɴ��Ŀ������Ϊֹ
		freesize = freesize << 1;
	}
	_expandSize = (freesize+_position);//��չ����ֽ�����
 
	char *tmpdata = (char*)malloc(_expandSize);//������չ��Ŀռ�
	memcpy(tmpdata, _bytes, _position);//��������
	free(_bytes);
	_bytes = (char*)malloc(_expandSize);//��չ�������ݴ�С
	memcpy(_bytes, tmpdata, _position);//��������
	free(tmpdata);
	_size = _position;//���ָ��

}

unsigned int ByteArray::getLength() const
{
	return _size;

}

unsigned int ByteArray::getPosition() const
{
	return _position;

}

void ByteArray::setPosition(unsigned int value)
{
	if (value > _size){
	_position = _size;
	}
	else{
	_position = value;
	}
}

void ByteArray::writeBytes(const char *bytes, unsigned int size)
{
	

	if (!_bytes){//���γ�ʼ��
		_size = size;//���ݳ���
		_expandSize = (size << 1);//���鳤��
		_bytes = (char*)malloc(_expandSize);//�����µ�ָ����С�ռ�(Ĭ��ֱ�ӷ���2��)
		memcpy(_bytes, bytes, size);
		_position = size;//ָ��λ��Ӧ�������һ��\0 -1
	}else{//��չ��׷�ӡ��޸�
		if (_position + size > _expandSize){//���ָ��λ��+Ҫд��ĳ��ȴ������鳤��
			expandBytes(size);//��չ���ݴ�С
		}
		memcpy(_bytes + _position, bytes, size);
		(_position + size) > _size ? _size = (_position + size) : _size;//�������ݳ���
		(_position + size) > _size ? _position = _size : _position += size;//����position
	}	
}

void ByteArray::readBytes( char *bytes, unsigned int size)
{
	if (_bytes){
		if (_position <= _size){
		//��ָ��λ�ø�������
		memcpy(bytes, _bytes+_position, size);
		_position += size;
		}
	}
     
}

const char* ByteArray::getBytes() const
{
	return _bytes;
}