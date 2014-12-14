#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "utils/ByteArray.h"

namespace MagicZooCoreUnitTest
{
	class TByteArray :public ByteArray
	{
	public:
		TByteArray();
		virtual ~TByteArray();

		void expandBytesPublic(unsigned int minSize);
		unsigned int getExpandSize();
	};

	TByteArray::TByteArray()
	{
	}

	TByteArray::~TByteArray()
	{
	}

	void TByteArray::expandBytesPublic(unsigned int minSize)
	{
		this->expandBytes(minSize);
	}

	unsigned int TByteArray::getExpandSize()
	{
		return this->_expandSize;
	}




	TEST_CLASS(ByteArrayUnitTest)
	{
	public:
		
	 
	
	 
		TEST_METHOD(writeBytesTest)
		{
			TByteArray bytes;

		

		 
			char* text = "test data test data test data test data";
			bytes.writeBytes((byte*)text,strlen(text)+1);

			Assert::AreEqual(strlen(text)+1,bytes.getLength(),L"写入数据长度错误");

			Assert::AreEqual(text,bytes.getBytes(),L"写入数据内如错误");
	 

		}
	 


	
		TEST_METHOD(readBytesTest)
		{
			TByteArray bytes;

			char* text = "test data test data test data test data";
			char charResult[100];

			bytes.writeBytes(text, strlen(text)+1);

			bytes.setPosition(0);
			bytes.readBytes(charResult,strlen(text)+1);

			Assert::AreEqual(text, charResult,L"数据读取后与写入时不匹配");
		}

		TEST_METHOD(getLengthTest)
		{
			TByteArray bytes;

			char* text = "test data test data test data test data";
			bytes.writeBytes(text, strlen(text) + 1);

			Assert::AreEqual(strlen(text) + 1, bytes.getLength(),L"写入的数据长度异常");

		}

		TEST_METHOD(getPositionTest)
		{
			TByteArray bytes;

			Assert::AreEqual(bytes.getPosition(), (unsigned int)0,L"初始值的配置必须为0");

			bytes.setPosition(100);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)0,L"位置不可超出最大长度");

			char* text = "test data test data test data test data";
			bytes.writeBytes(text, strlen(text) + 1);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)(strlen(text) + 1), L"当有数据后 位置必须在最后+1，如写入一个int形（4字节），position的值则为4");

		}


	 
	
		TEST_METHOD(setPositionTest)
		{
			TByteArray bytes;

			bytes.setPosition(100);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)0, L"位置不可超出最大长度");
			
			int value = 0xFFCCAADD;
			bytes.writeBytes((char*)&value,sizeof(int));
			bytes.writeBytes((char*)&value, sizeof(int));


			int changeValue = 0x11223344;
			bytes.setPosition(2);
			bytes.writeBytes((char *)&changeValue, sizeof(int));
<<<<<<< HEAD

			//DD AA CC FF DD AA CC FF
			//DD AA 44 33 22 11 CC FF

			int newValue1 = 0x3344AADD;
			int newValue2 = 0xFFCC1122;
=======
		   

			int newValue1 = 0xFFCC1122;
		    int newValue2 = 0x3344AADD;
>>>>>>> FETCH_HEAD
			int newValue1Result;
			int newValue2Result;
			bytes.setPosition(0);
			bytes.readBytes((char*)&newValue1Result, sizeof(int));
			bytes.readBytes((char*)&newValue2Result, sizeof(int));

			 
			Assert::AreEqual(newValue1,newValue2Result,L"数据结果值错误");
			Assert::AreEqual(newValue2, newValue1Result, L"数据结果值错误");
		}
	 
		TEST_METHOD(expandBytesTest)
		{
			TByteArray bytes;
			bytes.expandBytesPublic(100);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)100, L"数据扩展的结果与预期不符");

			bytes.expandBytesPublic(50);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)100, L"数据只能往大的扩");

			bytes.expandBytesPublic(200);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)200, L"数据扩展的结果与预期不符");

		}
   
	};
}