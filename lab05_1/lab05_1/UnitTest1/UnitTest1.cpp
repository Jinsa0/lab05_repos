#include "pch.h"
#include "CppUnitTest.h"
#include "../lab05_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestF_Zeros)
        {
            Assert::AreEqual(0.0, f(0, 0, 0), 1e-9);
        }
        TEST_METHOD(TestF_SimpleValue)
        {
            Assert::AreEqual(25.0, f(2, 0, 5), 1e-9);
        }
        TEST_METHOD(TestF_Pi)
        {
            double pi = atan(1.0) * 4;
            double expected = 2.0 + (pi / 2) * sin(1.0);
            Assert::AreEqual(expected, f(1, pi / 2, 1), 1e-9);
        }
        TEST_METHOD(TestF_NegativeValues)
        {
            double expected = -sin(2.0) + 2 * sin(-1.0) + 9.0;
            Assert::AreEqual(expected, f(-1, 2, 3), 1e-9);
        }

        TEST_METHOD(TestF_EqualArguments)
        {
            double expected = 2 * sin(1.0) + 1.0;
            Assert::AreEqual(expected, f(1, 1, 1), 1e-9);
        }

    };
}