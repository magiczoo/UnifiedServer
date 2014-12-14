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

			Assert::AreEqual(strlen(text)+1,bytes.getLength(),L"д�����ݳ��ȴ���");

			Assert::AreEqual(text,bytes.getBytes(),L"д�������������");
	 

		}
	 


	
		TEST_METHOD(readBytesTest)
		{
			TByteArray bytes;

			char* text = "test data test data test data test data";
			char charResult[100];

			bytes.writeBytes(text, strlen(text)+1);

			bytes.setPosition(0);
			bytes.readBytes(charResult,strlen(text)+1);

			Assert::AreEqual(text, charResult,L"���ݶ�ȡ����д��ʱ��ƥ��");
		}

		TEST_METHOD(getLengthTest)
		{
			TByteArray bytes;

			char* text = "test data test data test data test data";
			bytes.writeBytes(text, strlen(text) + 1);

			Assert::AreEqual(strlen(text) + 1, bytes.getLength(),L"д������ݳ����쳣");

		}

		TEST_METHOD(getPositionTest)
		{
			TByteArray bytes;

			Assert::AreEqual(bytes.getPosition(), (unsigned int)0,L"��ʼֵ�����ñ���Ϊ0");

			bytes.setPosition(100);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)0,L"λ�ò��ɳ�����󳤶�");

			char* text = "test data test data test data test data";
			bytes.writeBytes(text, strlen(text) + 1);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)(strlen(text) + 1), L"�������ݺ� λ�ñ��������+1����д��һ��int�Σ�4�ֽڣ���position��ֵ��Ϊ4");

		}


	 
	
		TEST_METHOD(setPositionTest)
		{
			TByteArray bytes;

			bytes.setPosition(100);
			Assert::AreEqual(bytes.getPosition(), (unsigned int)0, L"λ�ò��ɳ�����󳤶�");
			
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

			 
			Assert::AreEqual(newValue1,newValue2Result,L"���ݽ��ֵ����");
			Assert::AreEqual(newValue2, newValue1Result, L"���ݽ��ֵ����");
		}
	 
		TEST_METHOD(expandBytesTest)
		{
			TByteArray bytes;
			bytes.expandBytesPublic(100);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)100, L"������չ�Ľ����Ԥ�ڲ���");

			bytes.expandBytesPublic(50);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)100, L"����ֻ���������");

			bytes.expandBytesPublic(200);
			Assert::AreEqual(bytes.getExpandSize(), (unsigned int)200, L"������չ�Ľ����Ԥ�ڲ���");

		}
   
	};
}