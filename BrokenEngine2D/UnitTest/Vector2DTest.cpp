#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector2D.hpp"
#include "Vector2D.cpp"	//TODO: Fix so its not needed to include .cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector2DTest
{

	TEST_CLASS(Vector2DTest)
	{
	public:

		TEST_METHOD(Vector2DConstructor)
		{
			be::Vector2D<int> v;
			Assert::AreEqual(v.x, 0);
			Assert::AreEqual(v.y, 0);
		}

		TEST_METHOD(Vector2DConstructor_params)
		{
			be::Vector2D<int> v(10, 20);
			Assert::AreEqual(v.x, 10);
			Assert::AreEqual(v.y, 20);

			be::Vector2D<float> v2(5.5f, 137.13f);
			Assert::AreEqual(v2.x, 5.5f);
			Assert::AreEqual(v2.y, 137.13f);
		}
	};
}