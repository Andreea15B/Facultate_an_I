#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Lab 10\Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab10UnitTestMS
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
			int test1 = 2, test2 = 24, test3 = 4;
			Array<int> a(10);
			a += test1; a += test2; a += test3;
			Assert::AreEqual(a[0], 20);
		}

		TEST_METHOD(ExceptionTestMethod) 
		{
			int test1 = 2, test2 = 24, test3 = 4;
			Array<int> a(10);
			a += test1; a += test2; a += test3;
			auto func = [&] {a[2]; };
			Assert::ExpectException<const char*>(func);
		}

	};
}