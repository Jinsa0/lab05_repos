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

		// Тест для перевірки обчислення рекурентного доданку A
		TEST_METHOD(TestRecurrentFactor)
		{
			double x = -2.0;
			double a = -1.0 / x; // a0 = 0.5
			int n = 1;

			// Очікуємо a1 = 1 / (3 * (-2)^3) = -1 / 24 ≈ -0.0416667
			A(x, n, a);

			Assert::AreEqual(-1.0 / 24.0, a, 0.00001);
		}

		// Тест для перевірки суми ряду S проти atan(x) при x = -2.0
		TEST_METHOD(TestSumCalculation)
		{
			double x = -2.0;
			double eps = 0.0001;
			int n = 0;
			double s = 0.0;

			S(x, eps, n, s);

			// Перевіряємо, чи збігається обчислена сума з системною функцією atan(x)
			Assert::AreEqual(atan(x), s, eps);
		}
	};
}