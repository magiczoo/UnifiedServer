
#include "NetObjectValue.h"
#include <sstream>
#include <iomanip>



NetObjectValue::NetObjectValue()
	: _type(Type::NONE)
{
    memset(&_field, 0, sizeof(_field));
}
NetObjectValue::NetObjectValue(bool v)
	: _type(Type::BOOL)
{
	_field.boolVal = v;
}
NetObjectValue::NetObjectValue(int8 v)
	: _type(Type::INT8)
{
	_field.int8Val = v;
}
NetObjectValue::NetObjectValue(uint8 v)
	: _type(Type::UINT8)
{
	_field.uint8Val = v;
}
NetObjectValue::NetObjectValue(int16 v)
	: _type(Type::INT16)
{
	_field.int16Val = v;
}
NetObjectValue::NetObjectValue(uint16 v)
	: _type(Type::UINT16)
{
	_field.uint16Val = v;
}
NetObjectValue::NetObjectValue(int32 v)
	: _type(Type::INT32)
{
	_field.int32Val = v;
}
NetObjectValue::NetObjectValue(uint32 v)
	: _type(Type::UINT32)
{
	_field.uint32Val = v;
}
NetObjectValue::NetObjectValue(int64 v)
	: _type(Type::INT64)
{
	_field.int64Val = v;
}
NetObjectValue::NetObjectValue(uint64 v)
	: _type(Type::UINT64)
{
	_field.uint64Val = v;
}
NetObjectValue::NetObjectValue(float v)
	: _type(Type::FLOAT)
{
	_field.floatVal = v;
}
NetObjectValue::NetObjectValue(double v)
	: _type(Type::DOUBLE)
{
	_field.doubleVal = v;
}

NetObjectValue::NetObjectValue(const char* v)
	: _type(Type::STRING)
{
	_field.strVal = new std::string();
	if (v)
	{
		*_field.strVal = v;
	}
}

NetObjectValue::NetObjectValue(const std::string& v)
	: _type(Type::STRING)
{
	*_field.strVal = v;
}
NetObjectValue::NetObjectValue(const Date& v)
	: _type(Type::DATE)
{
	*_field.dateVal = v;
}
NetObjectValue::NetObjectValue(const std::vector<NetObjectValue>& v)
	: _type(Type::ARRAY)
{
	_field.arrayVal = new (std::nothrow) std::vector<NetObjectValue>();
	*_field.arrayVal = v;

}
NetObjectValue::NetObjectValue(std::vector<NetObjectValue>&& v)
	: _type(Type::ARRAY)
{
	_field.arrayVal = new (std::nothrow) std::vector<NetObjectValue>();
	*_field.arrayVal = std::move(v);

}
NetObjectValue::NetObjectValue(const ByteArray& v)
	:_type(Type::BINARY)
{
	_field.bytesVal = new ByteArray();
	_field.bytesVal->writeBytes(v.getBytes(),v.getLength());
}

NetObjectValue::NetObjectValue(const NetObjectBase& v)
	:_type(Type::NETOBJECT)
{
	*_field.netObjectVal = v;
}


NetObjectValue::NetObjectValue(const NetObjectValue& other)
	:_type(Type::NONE)
{
	*this = other;
}

NetObjectValue::NetObjectValue(NetObjectValue&& other)
	: _type(Type::NONE)
{
	*this = std::move(other);
}



NetObjectValue::~NetObjectValue()
{
    clear();
}

NetObjectValue& NetObjectValue::operator = (const NetObjectValue& other)
{
	if (this != &other) {
		reset(other._type);

		switch (other._type)
		{
		case NetObjectValue::Type::BOOL:
			_field.boolVal = other._field.boolVal;
			break;
		case NetObjectValue::Type::INT8:
			_field.int8Val = other._field.int8Val;
			break;
		case NetObjectValue::Type::UINT8:
			_field.uint8Val = other._field.uint8Val;
			break;
		case NetObjectValue::Type::INT16:
			_field.int16Val = other._field.int16Val;
			break;
		case NetObjectValue::Type::UINT16:
			_field.uint16Val = other._field.uint16Val;
			break;
		case NetObjectValue::Type::INT32:
			_field.int32Val = other._field.int32Val;
			break;
		case NetObjectValue::Type::UINT32:
			_field.uint32Val = other._field.uint32Val;
			break;
		case NetObjectValue::Type::INT64:
			_field.int64Val = other._field.int64Val;
			break;
		case NetObjectValue::Type::UINT64:
			_field.uint64Val = other._field.uint64Val;
			break;
		case NetObjectValue::Type::FLOAT:
			_field.floatVal = other._field.floatVal;
			break;
		case NetObjectValue::Type::DOUBLE:
			_field.doubleVal = other._field.doubleVal;
			break;
		case NetObjectValue::Type::STRING:
			if (_field.strVal == nullptr)
			{
				_field.strVal = new std::string();
			}
			*_field.strVal = *other._field.strVal;

			break;
		case NetObjectValue::Type::DATE:
			if (_field.dateVal==nullptr)
			{
				_field.dateVal = new Date();
			}
			*_field.dateVal = *other._field.dateVal;
			break;
		case NetObjectValue::Type::ARRAY:
			if (_field.arrayVal == nullptr)
			{
				_field.arrayVal = new (std::nothrow) std::vector<NetObjectValue>();
			}
			*_field.arrayVal = *other._field.arrayVal;

			break;
		case NetObjectValue::Type::BINARY:
			
			if (_field.bytesVal!=nullptr)
			{
				delete _field.bytesVal;
			}
			_field.bytesVal = new ByteArray();

			_field.bytesVal->writeBytes(other._field.bytesVal->getBytes(),other._field.bytesVal->getLength());

			break;
		case NetObjectValue::Type::NETOBJECT:
			break;
		default:
			break;
		}

	}
	return *this;
}
NetObjectValue& NetObjectValue::operator= (NetObjectValue&& other)
{
	if (this != &other) {
		clear();

		switch (other._type)
		{
		case NetObjectValue::Type::BOOL:
			_field.boolVal = other._field.boolVal;
			break;
		case NetObjectValue::Type::INT8:
			_field.int8Val = other._field.int8Val;
			break;
		case NetObjectValue::Type::UINT8:
			_field.uint8Val = other._field.uint8Val;
			break;
		case NetObjectValue::Type::INT16:
			_field.int16Val = other._field.int16Val;
			break;
		case NetObjectValue::Type::UINT16:
			_field.uint16Val = other._field.uint16Val;
			break;
		case NetObjectValue::Type::INT32:
			_field.int32Val = other._field.int32Val;
			break;
		case NetObjectValue::Type::UINT32:
			_field.uint32Val = other._field.uint32Val;
			break;
		case NetObjectValue::Type::INT64:
			_field.int64Val = other._field.int64Val;
			break;
		case NetObjectValue::Type::UINT64:
			_field.uint64Val = other._field.uint64Val;
			break;
		case NetObjectValue::Type::FLOAT:
			_field.floatVal = other._field.floatVal;
			break;
		case NetObjectValue::Type::DOUBLE:
			_field.doubleVal = other._field.doubleVal;
			break;
		case NetObjectValue::Type::STRING:
			_field.strVal = other._field.strVal;
			break;
		case NetObjectValue::Type::DATE:
			_field.dateVal = other._field.dateVal;
			break;
		case NetObjectValue::Type::ARRAY:
			_field.arrayVal = other._field.arrayVal;
			break;
		case NetObjectValue::Type::BINARY:
			_field.bytesVal = other._field.bytesVal;
			break;
		case NetObjectValue::Type::NETOBJECT:
			break;
		default:
			break;
		}
		_type = other._type;

		memset(&other._field, 0, sizeof(other._field));
		other._type = Type::NONE;
	}
	return *this;

}

NetObjectValue& NetObjectValue::operator= (bool v)
{
	reset(Type::BOOL);
	_field.boolVal = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (int8 v)
{
	reset(Type::INT8);
	_field.int8Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (uint8 v)
{
	reset(Type::UINT8);
	_field.uint8Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (int16 v)
{
	reset(Type::INT16);
	_field.int16Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (uint16 v)
{
	reset(Type::UINT16);
	_field.uint16Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (int32 v)
{
	reset(Type::INT32);
	_field.int32Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (uint32 v)
{
	reset(Type::UINT32);
	_field.uint32Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (int64 v)
{
	reset(Type::INT64);
	_field.int16Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (uint64 v)
{
	reset(Type::UINT64);
	_field.uint64Val = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (float v)
{
	reset(Type::FLOAT);
	_field.floatVal = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (double v)
{
	reset(Type::DOUBLE);
	_field.doubleVal = v;
	return *this;
}

NetObjectValue& NetObjectValue::operator= (const char* v)
{
	reset(Type::STRING);
	*_field.strVal = v ? v : "";
	return *this;
}
NetObjectValue& NetObjectValue::operator= (const std::string& v)
{
	reset(Type::STRING);
	*_field.strVal = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (const Date& v)
{
	reset(Type::DATE);
	*_field.dateVal = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (const std::vector<NetObjectValue>& v)
{
	reset(Type::ARRAY);
	*_field.arrayVal = v;
	return *this;
}
NetObjectValue& NetObjectValue::operator= (std::vector<NetObjectValue>&& v)
{
	reset(Type::ARRAY);
	*_field.arrayVal = std::move(v);
	return *this;
}
NetObjectValue& NetObjectValue::operator= (const ByteArray& v)
{
	reset(Type::BINARY);
	_field.bytesVal->writeBytes(v.getBytes(), v.getLength());
	return *this;
}

NetObjectValue& NetObjectValue::operator= (const NetObjectBase& v)
{
	reset(Type::NETOBJECT);
	*_field.netObjectVal = v;
	return *this;
}




bool NetObjectValue::operator!= (const NetObjectValue& v)
{
	return !(*this == v);
}
bool NetObjectValue::operator!= (const NetObjectValue& v) const
{
	return !(*this == v);
}
bool NetObjectValue::operator== (const NetObjectValue& v)
{
	const auto &t = *this;
	return t == v;
}
bool NetObjectValue::operator== (const NetObjectValue& v) const
{
	if (this == &v) return true;
	if (v._type != this->_type) return false;
	if (this->isNull()) return true;

	switch (_type)
	{
	case NetObjectValue::Type::BOOL:
		return v._field.boolVal==this->_field.boolVal;
	case NetObjectValue::Type::INT8:
		return v._field.int8Val == this->_field.int8Val;
	case NetObjectValue::Type::UINT8:
		return v._field.uint8Val == this->_field.uint8Val;
	case NetObjectValue::Type::INT16:
		return v._field.int16Val == this->_field.int16Val;
	case NetObjectValue::Type::UINT16:
		return v._field.uint16Val == this->_field.uint16Val;
	case NetObjectValue::Type::INT32:
		return v._field.int32Val == this->_field.int32Val;
	case NetObjectValue::Type::UINT32:
		return v._field.uint32Val == this->_field.uint32Val;
	case NetObjectValue::Type::INT64:
		return v._field.int64Val == this->_field.int64Val;
	case NetObjectValue::Type::UINT64:
		return v._field.uint64Val == this->_field.uint64Val;
	case NetObjectValue::Type::FLOAT:
		return fabs(v._field.floatVal - this->_field.floatVal) <= FLT_EPSILON;
	case NetObjectValue::Type::DOUBLE:
		return fabs(v._field.doubleVal - this->_field.doubleVal) <= FLT_EPSILON;
	case NetObjectValue::Type::STRING:
		return *v._field.strVal == *this->_field.strVal;
	case NetObjectValue::Type::DATE:
		return v._field.dateVal->getTime() == this->_field.dateVal->getTime();
	case NetObjectValue::Type::ARRAY:
		/*const auto &v1 = *(this->_field.arrayVal);
		const auto &v2 = *(v._field.arrayVal);
		const auto size = v1.size();
		if (size == v2.size())
		{
			for (size_t i = 0; i < size; i++)
			{
				if (v1[i] != v2[i]) return false;
			}
		}*/
		return true;
	case NetObjectValue::Type::BINARY:
		return false;
	case NetObjectValue::Type::NETOBJECT:
		return false;
	default:
		break;
	}


	return false;
}

bool NetObjectValue::asBool() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return false;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal;
	case NetObjectValue::Type::INT8:
		return _field.int8Val == 0 ? false : true;
	case NetObjectValue::Type::UINT8:
		return _field.uint8Val == 0 ? false : true;
	case NetObjectValue::Type::INT16:
		return _field.int16Val == 0 ? false : true;
	case NetObjectValue::Type::UINT16:
		return _field.uint16Val == 0 ? false : true;
	case NetObjectValue::Type::INT32:
		return _field.int32Val == 0 ? false : true;
	case NetObjectValue::Type::UINT32:
		return _field.uint32Val == 0 ? false : true;
	case NetObjectValue::Type::INT64:
		return _field.int64Val == 0 ? false : true;
	case NetObjectValue::Type::UINT64:
		return _field.uint64Val == 0 ? false : true;
	case NetObjectValue::Type::FLOAT:
		return _field.floatVal == 0 ? false : true;
	case NetObjectValue::Type::DOUBLE:
		return _field.doubleVal == 0 ? false : true;
	case NetObjectValue::Type::STRING:
		return (*_field.strVal == "0" || *_field.strVal == "false") ? false : true;
	case NetObjectValue::Type::DATE:
		return _field.dateVal==nullptr?false:_field.dateVal->getTime() == 0 ? false : true;
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal==nullptr?false:_field.arrayVal->empty() ? false : true;
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal==nullptr?false:_field.bytesVal->getLength() == 0 ? false : true;
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal==nullptr?false:true;
	default:
		break;
	}
	return false;
}
int8 NetObjectValue::asInt8() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal?1:0;
	case NetObjectValue::Type::INT8:
		return _field.int8Val;
	case NetObjectValue::Type::UINT8:
		return static_cast<int8>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<int8>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<int8>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<int8>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<int8>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<int8>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<int8>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<int8>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<int8>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<int8>( _field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<int8>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<int8>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
uint8 NetObjectValue::asUint8() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<uint8>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return _field.uint8Val;
	case NetObjectValue::Type::INT16:
		return static_cast<uint8>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<uint8>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<uint8>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<uint8>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<uint8>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<uint8>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<uint8>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<uint8>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<uint8>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<uint8>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<uint8>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
int16 NetObjectValue::asInt16() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<int16>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<int16>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return _field.int16Val;
	case NetObjectValue::Type::UINT16:
		return static_cast<int16>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<int16>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<int16>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<int16>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<int16>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<int16>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<int16>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<int16>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<int16>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<int16>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
uint16 NetObjectValue::asUint16() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<uint16>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<uint16>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<uint16>(_field.int16Val);;
	case NetObjectValue::Type::UINT16:
		return _field.uint16Val;
	case NetObjectValue::Type::INT32:
		return static_cast<uint16>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<uint16>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<uint16>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<uint16>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<uint16>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<uint16>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<uint16>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<uint16>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<uint16>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
int32 NetObjectValue::asInt32() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<int32>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<int32>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<int32>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<int32>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return _field.int32Val;
	case NetObjectValue::Type::UINT32:
		return static_cast<int32>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<int32>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<int32>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<int32>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<int32>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<int32>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<int32>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<int32>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
uint32 NetObjectValue::asUint32() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<uint32>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<uint32>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<uint32>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<uint32>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<uint32>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return _field.uint32Val;
	case NetObjectValue::Type::INT64:
		return static_cast<uint32>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<uint32>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<uint32>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<uint32>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<uint32>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<uint32>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<uint32>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
int64 NetObjectValue::asInt64() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<int64>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<int64>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<int64>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<int64>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<int64>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<int64>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<int64>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return _field.uint64Val;
	case NetObjectValue::Type::FLOAT:
		return static_cast<int64>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<int64>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<int64>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<int64>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<int64>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
uint64 NetObjectValue::asUint64() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1 : 0;
	case NetObjectValue::Type::INT8:
		return static_cast<uint64>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<uint64>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<uint64>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<uint64>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<uint64>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<uint64>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<uint64>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return _field.uint64Val;
	case NetObjectValue::Type::FLOAT:
		return static_cast<uint64>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return static_cast<uint64>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atoi(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0 : static_cast<uint64>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0 : static_cast<uint64>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0 : static_cast<uint64>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0 : 1;
	default:
		break;
	}
	return 0;
}
float NetObjectValue::asFloat() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1.0f : 0.0f;
	case NetObjectValue::Type::INT8:
		return static_cast<float>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<float>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<float>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<float>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<float>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<float>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<float>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<float>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return _field.floatVal;
	case NetObjectValue::Type::DOUBLE:
		return static_cast<float>(_field.doubleVal);
	case NetObjectValue::Type::STRING:
		return atof(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0.0f : static_cast<float>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0.0f : static_cast<float>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0.0f : static_cast<float>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0.0f : 1.0f;
	default:
		break;
	}
	return 0.0f;
}
double NetObjectValue::asDouble() const
{
	switch (_type)
	{
	case NetObjectValue::Type::NONE:
		return 0;
	case NetObjectValue::Type::BOOL:
		return _field.boolVal ? 1.0 : 0.0;
	case NetObjectValue::Type::INT8:
		return static_cast<double>(_field.int8Val);
	case NetObjectValue::Type::UINT8:
		return static_cast<double>(_field.uint8Val);
	case NetObjectValue::Type::INT16:
		return static_cast<double>(_field.int16Val);
	case NetObjectValue::Type::UINT16:
		return static_cast<double>(_field.uint16Val);
	case NetObjectValue::Type::INT32:
		return static_cast<double>(_field.int32Val);
	case NetObjectValue::Type::UINT32:
		return static_cast<double>(_field.uint32Val);
	case NetObjectValue::Type::INT64:
		return static_cast<double>(_field.int64Val);
	case NetObjectValue::Type::UINT64:
		return static_cast<double>(_field.uint64Val);
	case NetObjectValue::Type::FLOAT:
		return static_cast<double>(_field.floatVal);
	case NetObjectValue::Type::DOUBLE:
		return _field.doubleVal;
	case NetObjectValue::Type::STRING:
		return atof(_field.strVal->c_str());
	case NetObjectValue::Type::DATE:
		return _field.dateVal == nullptr ? 0.0 : static_cast<double>(_field.dateVal->getTime());
	case NetObjectValue::Type::ARRAY:
		return _field.arrayVal == nullptr ? 0.0 : static_cast<double>(_field.arrayVal->size());
	case NetObjectValue::Type::BINARY:
		return _field.bytesVal == nullptr ? 0.0 : static_cast<double>(_field.bytesVal->getLength());
	case NetObjectValue::Type::NETOBJECT:
		return _field.netObjectVal == nullptr ? 0.0 : 1.0;
	default:
		break;
	}
	return 0.0;
}
std::string NetObjectValue::asString() const
{
	if (_type==Type::STRING)
	{
		return *_field.strVal;
	}

	std::stringstream ret;

	switch (_type)
	{
	case NetObjectValue::Type::BOOL:
		ret << (_field.boolVal ? "true" : "false");
	case NetObjectValue::Type::INT8:
		ret<<_field.int8Val;
	case NetObjectValue::Type::UINT8:
		ret << _field.uint8Val;
	case NetObjectValue::Type::INT16:
		ret << _field.int16Val;
	case NetObjectValue::Type::UINT16:
		ret << _field.uint16Val;
	case NetObjectValue::Type::INT32:
		ret << _field.int32Val;
	case NetObjectValue::Type::UINT32:
		ret << _field.uint32Val;
	case NetObjectValue::Type::INT64:
		ret << _field.int64Val;
	case NetObjectValue::Type::UINT64:
		ret << _field.uint64Val;
	case NetObjectValue::Type::FLOAT:
		ret << _field.floatVal;
	case NetObjectValue::Type::DOUBLE:
		ret << _field.doubleVal;
	case NetObjectValue::Type::DATE:
		ret << (_field.dateVal == nullptr ? 0 : static_cast<uint64>(_field.dateVal->getTime()));
	case NetObjectValue::Type::ARRAY:
		ret << (_field.arrayVal == nullptr ? 0 : static_cast<uint64>(_field.arrayVal->size()));
	case NetObjectValue::Type::BINARY:
		ret << _field.uint8Val;
	case NetObjectValue::Type::NETOBJECT:
		ret << (_field.netObjectVal == nullptr ? "nullptr" : "");
	default:
		break;
	}
	return ret.str();
}
Date& NetObjectValue::asDate() const
{
	if (_type!=Type::DATE || _field.dateVal==nullptr)
	{
		return Date();
	}

	return *_field.dateVal;
}

std::vector<NetObjectValue>& NetObjectValue::asArray()
{
	if (_type!= Type::ARRAY || _field.arrayVal == nullptr)
	{
		return std::vector<NetObjectValue>();
	}

	return *_field.arrayVal;
}
const std::vector<NetObjectValue>& NetObjectValue::asArray() const
{
	if (_type != Type::ARRAY || _field.arrayVal == nullptr)
	{
		return std::vector<NetObjectValue>();
	}

	return *_field.arrayVal;

}

ByteArray& NetObjectValue::asBinary()
{
	if (_type != Type::BINARY || _field.bytesVal == nullptr)
	{
		return ByteArray();
	}

	return *_field.bytesVal;

}

NetObjectBase& NetObjectValue::asNetObject()
{
	if (_type != Type::NETOBJECT || _field.netObjectVal == nullptr)
	{
		return NetObjectBase();
	}

	return *_field.netObjectVal;
}


void NetObjectValue::clear()
{
	switch (_type)
	{
	case NetObjectValue::Type::BOOL:
		_field.boolVal = false;
		break;
	case NetObjectValue::Type::INT8:
		_field.int8Val = 0;
		break;
	case NetObjectValue::Type::UINT8:
		_field.uint8Val = 0;
		break;
	case NetObjectValue::Type::INT16:
		_field.int16Val = 0;
		break;
	case NetObjectValue::Type::UINT16:
		_field.uint16Val = 0;
		break;
	case NetObjectValue::Type::INT32:
		_field.int32Val=0;
		break;
	case NetObjectValue::Type::UINT32:
		_field.uint32Val = 0;
		break;
	case NetObjectValue::Type::INT64:
		_field.int64Val = 0;
		break;
	case NetObjectValue::Type::UINT64:
		_field.uint64Val = 0;
		break;
	case NetObjectValue::Type::FLOAT:
		_field.floatVal = 0.0f;
		break;
	case NetObjectValue::Type::DOUBLE:
		_field.doubleVal = 0.0f;
		break;
	case NetObjectValue::Type::STRING:
		if (_field.strVal!=nullptr)
		{
			delete _field.strVal;
			_field.strVal = nullptr;
		}
		break;
	case NetObjectValue::Type::DATE:
		if (_field.dateVal!=nullptr)
		{
			delete _field.dateVal;
			_field.dateVal = nullptr;
		}
		break;
	case NetObjectValue::Type::ARRAY:
		if (_field.arrayVal!=nullptr)
		{
			delete _field.arrayVal;
			_field.arrayVal = nullptr;
		}
		break;
	case NetObjectValue::Type::BINARY:
		if (_field.bytesVal!=nullptr)
		{
			delete _field.bytesVal;
			_field.bytesVal = nullptr;
		}
		break;
	case NetObjectValue::Type::NETOBJECT:
		if (_field.netObjectVal!=nullptr)
		{
			delete _field.netObjectVal;
			_field.netObjectVal = nullptr;
		}
		break;
	default:
		break;
	}
    
    _type = Type::NONE;
}

void NetObjectValue::reset(Type type)
{
    if (_type == type)
        return;

    clear();

    // Allocate memory for the new value
    switch (type)
    {
        case Type::STRING:
            _field.strVal = new std::string();
            break;
        case Type::DATE:
            _field.dateVal = new (std::nothrow) Date();
            break;
        case Type::ARRAY:
			_field.arrayVal = new (std::nothrow) std::vector<NetObjectValue>();
            break;
        case Type::BINARY:
            _field.bytesVal = new (std::nothrow) ByteArray();
            break;
		case Type::NETOBJECT:
			_field.netObjectVal = new (std::nothrow) NetObjectBase();
        default:
            break;
    }

    _type = type;
}


