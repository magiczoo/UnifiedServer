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
	
	unsigned int freesize = _expandSize-_size;//剩余空间
	freesize == 0 ? freesize = minSize : freesize;//如果没有空间直接再扩展目标数据大小
	while (freesize  < minSize){ //一直扩展到可存放目标数据为止
		freesize = freesize << 1;
	}
	_expandSize = (freesize+_size);//扩展后的字节总数

	char *tmpdata = (char*)malloc(sizeof(char*)*_expandSize);//数据扩展后的空间
	memset(tmpdata, 0x00, _expandSize);
	memcpy(tmpdata, _bytes, _size);//复制数据

	free(_bytes);

	_bytes = (char*)malloc(sizeof(char*)*_expandSize);//扩展数组数据大小
	memset(_bytes, 0x00, _expandSize);
	memcpy(_bytes, tmpdata, _size);//复制数据
    
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
	_size = size;//数据长度
	_expandSize = size*2;//数组长度
	_bytes = (char*)malloc(sizeof(char*)*_expandSize);//分配新的指定大小空间(默认直接分配2倍)
	memset(_bytes, 0x00, _expandSize);
	memcpy(_bytes,bytes,size);
	_position = size;//指针位置应该是最后一个\0 -1
	}else{
		//判断模式 1修改 2追加
		if (_position == _size){ //2说明当前指针就在数组未尾的追加模式

			if (_size + size <= _expandSize){//如果数组可以容纳当前数据那么执行下面的逻辑

				memcpy(_bytes + _position, bytes, size);
				_size += size;//更新数据长度
				_position = _size;//更新指针位置

			}
			else{//如果数组不能容纳当前长度那么就需要扩展

				expandBytes(size);//扩展数据大小
				memcpy(_bytes + _position, bytes, size);

				_size += size;//更新数据长度
				_position = _size;//当前数据未尾位置
			}
		
		}else{//1修改模式

			memcpy(_bytes + _position, bytes, size);
			_position = _position + size;//更新指针位置
		
		}


	}
	

	
}

void ByteArray::readBytes( char *bytes, unsigned int size)
{
	if (_bytes){
		//先填充一下目标区域
		memset(bytes, 0x00, size);
		//从指定位置复制数据
		memcpy(bytes, _bytes+_position, size);
	}
     
}

const char* ByteArray::getBytes() const
{
	return _bytes;
}