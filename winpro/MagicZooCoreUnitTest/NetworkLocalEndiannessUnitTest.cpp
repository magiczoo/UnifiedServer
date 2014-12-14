#include "stdafx.h"
#include "CppUnitTest.h"
#include "utils/NetworkLocalEndianness.h"
#include "Types.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MagicZooCoreUnitTest
{

	class NetworkLocalEndiannessBig: public NetworkLocalEndianness {
		virtual bool isBigEndian()
		{
			return true;
		}
	};

	class NetworkLocalEndiannessLittle : public NetworkLocalEndianness {
		virtual bool isBigEndian()
		{
			return false;
		}
	};


	TEST_CLASS(NetworkLocalEndiannessUnitTest)
	{
	public:
		
		TEST_METHOD(isBigEndianTest)
		{
			int n = 0x12345678;
			
			auto isBig= *((char*)&n) == 0x12 ? true : false;

			NetworkLocalEndianness e;

			Assert::AreEqual(e.isBigEndian(), isBig,L"高低字节计算错误");
		}

		TEST_METHOD(toNextworkTest)
		{
			int16 i16 = 0x1234;
			int32 i32 = 0x12345678;
			int64 i64 = 0x1234567890abcdef;
			uint16 u16 = 0x1234;
			uint32 u32 = 0x12345678;
			uint64 u64 = 0x1234567890abcdef;
			float f32 = *((float*)(&i32));
			double f64 = *((double*)(&i64));

			int16 _i16 = 0x3412;
			int32 _i32 = 0x78563412;
			int64 _i64 = 0xefcdab9078563412;
			uint16 _u16 = 0x3412;
			uint32 _u32 = 0x78563412;
			uint64 _u64 = 0xefcdab9078563412;
			float _f32 = *((float*)(&_i32));;
			double _f64 = *((double*)(&_i64));;


			NetworkLocalEndiannessBig big;
			NetworkLocalEndiannessLittle little;

			//本地高字节 转换为网络
			Assert::IsTrue(big.toNextwork(i16)==i16, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(i32)==i32, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(i64)==i64, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(u16)==u16, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(u32)==u32, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(u64)==u64, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(f32)==f32, L"字节转换错误");
			Assert::IsTrue(big.toNextwork(f64)==f64, L"字节转换错误");

			
			//本地低字节 转换为网络
			Assert::IsTrue(little.toNextwork(i16)==_i16, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(i32)==_i32, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(i64)==_i64, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(u16)==_u16, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(u32)==_u32, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(u64)==_u64, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(f32)==_f32, L"字节转换错误");
			Assert::IsTrue(little.toNextwork(f64)==_f64, L"字节转换错误");

			

		}

		TEST_METHOD(toLocalTest)
		{
			int16 i16 = 0x1234;
			int32 i32 = 0x12345678;
			int64 i64 = 0x1234567890abcdef;
			uint16 u16 = 0x1234;
			uint32 u32 = 0x12345678;
			uint64 u64 = 0x1234567890abcdef;
			float f32 = *((float*)(&i32));
			double f64 = *((double*)(&i64));

			int16 _i16 = 0x3412;
			int32 _i32 = 0x78563412;
			int64 _i64 = 0xefcdab9078563412;
			uint16 _u16 = 0x3412;
			uint32 _u32 = 0x78563412;
			uint64 _u64 = 0xefcdab9078563412;
			float _f32 = *((float*)(&_i32));;
			double _f64 = *((double*)(&_i64));;

			NetworkLocalEndiannessBig big;
			NetworkLocalEndiannessLittle little;

			//本地高字节 转换为本地
			Assert::IsTrue(big.toLocal(i16)==i16, L"字节转换错误");
			Assert::IsTrue(big.toLocal(i32)==i32, L"字节转换错误");
			Assert::IsTrue(big.toLocal(i64)==i64, L"字节转换错误");
			Assert::IsTrue(big.toLocal(u16)==u16, L"字节转换错误");
			Assert::IsTrue(big.toLocal(u32)==u32, L"字节转换错误");
			Assert::IsTrue(big.toLocal(u64)==u64, L"字节转换错误");
			Assert::IsTrue(big.toLocal(f32)==f32, L"字节转换错误");
			Assert::IsTrue(big.toLocal(f64)==f64, L"字节转换错误");


			////本地低字节 转换为本地
			Assert::IsTrue(little.toLocal(i16)==_i16, L"字节转换错误");
			Assert::IsTrue(little.toLocal(i32)==_i32, L"字节转换错误");
			Assert::IsTrue(little.toLocal(i64)==_i64, L"字节转换错误");
			Assert::IsTrue(little.toLocal(u16)==_u16, L"字节转换错误");
			Assert::IsTrue(little.toLocal(u32)==_u32, L"字节转换错误");
			Assert::IsTrue(little.toLocal(u64)==_u64, L"字节转换错误");
			Assert::IsTrue(little.toLocal(f32)==_f32, L"字节转换错误");
			Assert::IsTrue(little.toLocal(f64)==_f64, L"字节转换错误");

		}


	};
}