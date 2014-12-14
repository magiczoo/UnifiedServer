#ifndef NETOBJECTVALUE_H
#define NETOBJECTVALUE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "../../Types.h"
#include "../../utils/ByteArray.h"
#include "../../utils/Date.h"
#include "../object/NetObjectBase.h"
#include "../NetType.h"

class NetObjectValue
{
public:
	static const NetObjectValue Null;

	NetObjectValue();
	explicit NetObjectValue(bool v);
	explicit NetObjectValue(int8 v);
	explicit NetObjectValue(uint8 v);
    explicit NetObjectValue(int16 v);
    explicit NetObjectValue(uint16 v);
    explicit NetObjectValue(int32 v);
	explicit NetObjectValue(uint32 v);
	explicit NetObjectValue(int64 v);
	explicit NetObjectValue(uint64 v);
	explicit NetObjectValue(float v);
	explicit NetObjectValue(double v);

	explicit NetObjectValue(const char* v);
    explicit NetObjectValue(const std::string& v);
	explicit NetObjectValue(const Date& v);
	explicit NetObjectValue(const std::vector<NetObjectValue>& v);
	explicit NetObjectValue(std::vector<NetObjectValue>&& v);
	explicit NetObjectValue(const ByteArray& v);
	explicit NetObjectValue(const NetObjectBase& v);


	NetObjectValue(const NetObjectValue& other);
	NetObjectValue(NetObjectValue&& other);
	~NetObjectValue();

	NetObjectValue& operator= (const NetObjectValue& other);
	NetObjectValue& operator= (NetObjectValue&& other);

	NetObjectValue& operator= (bool v);
	NetObjectValue& operator= (int8 v);
	NetObjectValue& operator= (uint8 v);
	NetObjectValue& operator= (int16 v);
	NetObjectValue& operator= (uint16 v);
	NetObjectValue& operator= (int32 v);
	NetObjectValue& operator= (uint32 v);
	NetObjectValue& operator= (int64 v);
	NetObjectValue& operator= (uint64 v);
	NetObjectValue& operator= (float v);
	NetObjectValue& operator= (double v);

	NetObjectValue& operator= (const char* v);
	NetObjectValue& operator= (const std::string& v);
	NetObjectValue& operator= (const Date& v);
	NetObjectValue& operator= (const std::vector<NetObjectValue>& v);
	NetObjectValue& operator= (std::vector<NetObjectValue>&& v);
	NetObjectValue& operator= (const ByteArray& v);
	NetObjectValue& operator= (const NetObjectBase& v);



	bool operator!= (const NetObjectValue& v);
	bool operator!= (const NetObjectValue& v) const;
	bool operator== (const NetObjectValue& v);
	bool operator== (const NetObjectValue& v) const;

	bool asBool() const;
	int8 asInt8() const;
	uint8 asUint8() const;
	int16 asInt16() const;
	uint16 asUint16() const;
	int32 asInt32() const;
	uint32 asUint32() const;
	int64 asInt64() const;
	uint64 asUint64() const;
	float asFloat() const;
	double asDouble() const;
	std::string asString() const;
	Date& asDate() const;

	std::vector<NetObjectValue>& asArray();
	const std::vector<NetObjectValue>& asArray() const;

	ByteArray& asBinary();

	NetObjectBase& asNetObject();


    inline bool isNull() const { return _type == Type::NONE; }

    enum class Type
    {
        NONE = 0,
        BOOL,
        INT8,
        UINT8,
        INT16,
        UINT16,
        INT32,
        UINT32,
        INT64,
        UINT64,
		FLOAT,
		DOUBLE,
		STRING,
		DATE,
		ARRAY,
		BINARY,
		NETOBJECT
    };

	inline std::string getType() const {
		switch (_type)
		{
		case NetObjectValue::Type::NONE:
			return "";
		case NetObjectValue::Type::BOOL:
			return NetType::BOOL;
		case NetObjectValue::Type::INT8:
			return NetType::INT8;
		case NetObjectValue::Type::UINT8:
			return NetType::UINT8;
		case NetObjectValue::Type::INT16:
			return NetType::INT16;
		case NetObjectValue::Type::UINT16:
			return NetType::UINT16;
		case NetObjectValue::Type::INT32:
			return NetType::INT32;
		case NetObjectValue::Type::UINT32:
			return NetType::UINT32;
		case NetObjectValue::Type::INT64:
			return NetType::INT64;
		case NetObjectValue::Type::UINT64:
			return NetType::UINT64;
		case NetObjectValue::Type::FLOAT:
			return NetType::FLOAT;
		case NetObjectValue::Type::DOUBLE:
			return NetType::DOUBLE;
		case NetObjectValue::Type::STRING:
			return NetType::STRING;
		case NetObjectValue::Type::DATE:
			return NetType::DATE;
		case NetObjectValue::Type::ARRAY:
			return NetType::ARRAY;
		case NetObjectValue::Type::BINARY:
			return NetType::BINARY;
		case NetObjectValue::Type::NETOBJECT:
			return "USER DEFINED TYPE";
		default:
			break;
		};
	};


private:
    void clear();
    void reset(Type type);

    union
    {
		bool boolVal;
		int8 int8Val;
		uint8 uint8Val;
		int16 int16Val;
		uint16 uint16Val;
		int32 int32Val;
		uint32 uint32Val;
		int64 int64Val;
		uint64 uint64Val;
		float floatVal;
		double doubleVal;

        std::string* strVal;
        Date* dateVal;
		std::vector<NetObjectValue>* arrayVal;
		ByteArray* bytesVal;
		NetObjectBase* netObjectVal;

    }_field;

    Type _type;
};



#endif //NETOBJECTVALUE_H
