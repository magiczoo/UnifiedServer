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

void ByteArray::expandBytes(uint minSize)
{
	uint freesize = _expandSize - _position;//指南后面的剩余空间
	freesize == 0 ? freesize = (minSize) : freesize;//如果没有空间直接再扩展目标数据大小
	while (freesize  < minSize){ //一直扩展到可存放目标数据为止
		freesize = freesize << 1;
	}
	_expandSize = (freesize+_position);//扩展后的字节总数
 
	byte *tmpdata = (byte*)malloc(_expandSize);//数据扩展后的空间
	memcpy(tmpdata, _bytes, _position);//复制数据
	free(_bytes);
	_bytes = (byte*)malloc(_expandSize);//扩展数组数据大小
	memcpy(_bytes, tmpdata, _position);//复制数据
	free(tmpdata);
	_size = _position;//变更指针

}

uint ByteArray::getLength() const
{
	return _size;

}

uint ByteArray::getPosition() const
{
	return _position;

}

void ByteArray::setPosition(uint value)
{
	if (value > _size){
	_position = _size;
	}
	else{
	_position = value;
	}
}

void ByteArray::writeBytes(const byte *bytes, uint size)
{
	

	if (!_bytes){//初次初始化
		_size = size;//数据长度
		_expandSize = (size << 1);//数组长度
		_bytes = (byte*)malloc(_expandSize);//分配新的指定大小空间(默认直接分配2倍)
		memcpy(_bytes, bytes, size);
		_position = size;//指针位置应该是最后一个\0 -1
	}else{//扩展、追加、修改
		if (_position + size > _expandSize){//如果指针位置+要写入的长度大于数组长度
			expandBytes(size);//扩展数据大小
		}
		memcpy(_bytes + _position, bytes, size);
		(_position + size) > _size ? _size = (_position + size) : _size;//更新数据长度
		(_position + size) > _size ? _position = _size : _position += size;//更新position
	}	
}

void ByteArray::readBytes( byte *bytes, uint size)
{
	if (_bytes){
		if (_position <= _size){
		//从指定位置复制数据
		memcpy(bytes, _bytes+_position, size);
		_position += size;
		}
	}
     
}

const byte* ByteArray::getBytes() const
{
	return _bytes;
}