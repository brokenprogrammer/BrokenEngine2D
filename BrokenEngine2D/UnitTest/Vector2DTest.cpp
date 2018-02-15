#include "stdafx.h"
#include "CppUnitTest.h"
//#include "Vector2D.hpp"
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

		TEST_METHOD(Vector2D_Add_Vector2D)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);
			be::Vector2D<float> v2(3.0f, -2.5f);

			v1.add(v2);

			Assert::AreEqual(v1.x, 4.0f);
			Assert::AreEqual(v1.y, -5.0f);
		}

		TEST_METHOD(Vector2D_Subtract_Vector2D)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);
			be::Vector2D<float> v2(3.0f, -2.5f);

			v1.subtract(v2);

			Assert::AreEqual(v1.x, -2.0f);
			Assert::AreEqual(v1.y, 0.0f);
		}

		TEST_METHOD(Vector2D_Multiply_Vector2D)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);
			be::Vector2D<float> v2(3.0f, -2.5f);

			v1.multiply(v2);

			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 6.25f);
		}

		TEST_METHOD(Vector2D_Divide_Vector2D)
		{
			be::Vector2D<float> v1(15.0f, 10.0f);
			be::Vector2D<float> v2(3.0f, 2.5f);

			v1.divide(v2);

			Assert::AreEqual(v1.x, 5.0f);
			Assert::AreEqual(v1.y, 4.0f);
		}

		TEST_METHOD(Vector2D_Add_T)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);

			v1.add(3.0f);

			Assert::AreEqual(v1.x, 4.0f);
			Assert::AreEqual(v1.y, 0.5f);
		}

		TEST_METHOD(Vector2D_Subtract_T)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);

			v1.subtract(7.5f);

			Assert::AreEqual(v1.x, -6.5f);
			Assert::AreEqual(v1.y, -10.0f);
		}

		TEST_METHOD(Vector2D_Multiply_T)
		{
			be::Vector2D<float> v1(1.0f, -2.5f);

			v1.multiply(2.0f);

			Assert::AreEqual(v1.x, 2.0f);
			Assert::AreEqual(v1.y, -5.0f);
		}

		TEST_METHOD(Vector2D_Divide_T)
		{
			be::Vector2D<float> v1(15.0f, 10.0f);

			v1.divide(5);

			Assert::AreEqual(v1.x, 3.0f);
			Assert::AreEqual(v1.y, 2.0f);
		}

		TEST_METHOD(Vector2D_CmpndAdd_Vector2D)
		{
			be::Vector2D<float> v1(15.0f, 10.0f);
			be::Vector2D<float> v2(5.0f, 12.0f);

			v1 += v2;

			Assert::AreEqual(v1.x, 20.0f);
			Assert::AreEqual(v1.y, 22.0f);
		}

		TEST_METHOD(Vector2D_Negate)
		{
			be::Vector2D<int> v(15, 20);
			be::Vector2D<int> v2 = -v;

			Assert::AreEqual(v2.x, -15);
			Assert::AreEqual(v2.y, -20);

			be::Vector2D<int> v3(1, 1);
			v3 += v;

			Assert::AreEqual(v3.x, 16);
			Assert::AreEqual(v3.y, 21);
		}
	};
}