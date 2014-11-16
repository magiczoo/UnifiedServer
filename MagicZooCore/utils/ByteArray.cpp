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
	
	unsigned int freesize = _expandSize-_size;//ʣ��ռ�
	freesize == 0 ? freesize = minSize : freesize;//���û�пռ�ֱ������չĿ�����ݴ�С
	while (freesize  < minSize){ //һֱ��չ���ɴ��Ŀ������Ϊֹ
		freesize = freesize << 1;
	}
	_expandSize = (freesize+_size);//��չ����ֽ�����

	char *tmpdata = (char*)malloc(sizeof(char*)*_expandSize);//������չ��Ŀռ�
	memset(tmpdata, 0x00, _expandSize);
	memcpy(tmpdata, _bytes, _size);//��������

	free(_bytes);

	_bytes = (char*)malloc(sizeof(char*)*_expandSize);//��չ�������ݴ�С
	memset(_bytes, 0x00, _expandSize);
	memcpy(_bytes, tmpdata, _size);//��������
    
	free(tmpdata);
	
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
	if (!_bytes){
	_size = size;//���ݳ���
	_expandSize = size*2;//���鳤��
	_bytes = (char*)malloc(sizeof(char*)*_expandSize);//�����µ�ָ����С�ռ�(Ĭ��ֱ�ӷ���2��)
	memset(_bytes, 0x00, _expandSize);
	memcpy(_bytes,bytes,size);
	_position = size;//ָ��λ��Ӧ�������һ��\0 -1
	}else{
		//�ж�ģʽ 1�޸� 2׷��
		if (_position == _size){ //2˵����ǰָ���������δβ��׷��ģʽ

			if (_size + size <= _expandSize){//�������������ɵ�ǰ������ôִ��������߼�

				memcpy(_bytes + _position, bytes, size);
				_size += size;//�������ݳ���
				_position = _size;//����ָ��λ��

			}
			else{//������鲻�����ɵ�ǰ������ô����Ҫ��չ

				expandBytes(size);//��չ���ݴ�С
				memcpy(_bytes + _position, bytes, size);

				_size += size;//�������ݳ���
				_position = _size;//��ǰ����δβλ��
			}
		
		}else{//1�޸�ģʽ

			memcpy(_bytes + _position, bytes, size);
			_position = _position + size;//����ָ��λ��
		
		}


	}
	

	
}

void ByteArray::readBytes( char *bytes, unsigned int size)
{
	if (_bytes){
		//�����һ��Ŀ������
		memset(bytes, 0x00, size);
		//��ָ��λ�ø�������
		memcpy(bytes, _bytes+_position, size);
	}
     
}

const char* ByteArray::getBytes() const
{
	return _bytes;
}