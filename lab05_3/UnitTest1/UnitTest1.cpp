#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include "../lab05_3/lab05_3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestLab053
{
    TEST_CLASS(UnitTestLab053)
    {
    public:

        // Тест 1: Перевірка гілки |x| >= 1
        TEST_METHOD(TestBranch1_GreaterOrEqualOne)
        {
            double x = 2.0;
            double expected = (sin(x) + 1.0) / (sin(x) + cos(x));
            double actual = f(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }

        // Тест 2: Перевірка гілки |x| < 1 (sinh(x))
        TEST_METHOD(TestBranch2_LessThanOne)
        {
            double x = 0.5;

            // Ряд зі знаками '+' дає гіперболічний синус sinh(x)
            double expected = sinh(x);
            double actual = f(x);

            Assert::AreEqual(expected, actual, 0.0001);
        }

        // Тест 3: Граничне значення x = 0
        TEST_METHOD(TestBranch2_ZeroValue)
        {
            double x = 0.0;
            double expected = 0.0;
            double actual = f(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }
    };
}