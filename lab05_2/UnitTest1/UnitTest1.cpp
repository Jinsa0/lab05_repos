#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab05_2/lab05_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Перевірка функції A: перехід від доданку a0 до a1 при x = -2
        TEST_METHOD(TestRecurrentFactor)
        {
            double x = -2.0;
            double a = -1.0 / x;   // a0 = 0.5
            int n = 1;
            // Очікуємо a1 = 1 / (3 * x^3) = 1 / (3 * (-8)) = -1 / 24
            A(x, n, a);
            Assert::AreEqual(-1.0 / 24.0, a, 1e-9);
        }

        // Перевірка функції S: сума ряду порівнюється з atan(x) при x = -2
        TEST_METHOD(TestSumCalculation)
        {
            double x = -2.0;
            double eps = 0.0001;
            int n = 0;
            double s = 0.0;
            S(x, eps, n, s);
            Assert::AreEqual(atan(x), s, eps);
            Assert::IsTrue(n > 0);
        }

        // Перевірка функції S з меншим eps при x = -5
        TEST_METHOD(TestSumSmallEps)
        {
            double x = -5.0;
            double eps = 0.000001;
            int n = 0;
            double s = 0.0;
            S(x, eps, n, s);
            Assert::AreEqual(atan(x), s, eps);
        }
    };
}
