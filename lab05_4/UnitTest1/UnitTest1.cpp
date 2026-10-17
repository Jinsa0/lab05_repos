#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include "../lab05_4/lab05_4.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestLab054
{
    TEST_CLASS(UnitTestLab054)
    {
    public:

        // Тест 1: Перевірка гілки N = 10
        TEST_METHOD(TestBranch1_NormalN_10)
        {
            int N = 10;

            double expected = S0(N);
            double tolerance = 0.00001;

            Assert::AreEqual(expected, S1(N, N), tolerance);
            Assert::AreEqual(expected, S2(N, 22), tolerance);
            Assert::AreEqual(expected, S3(N, N, 0), tolerance);
            Assert::AreEqual(expected, S4(N, 22, 0), tolerance);
        }

        // Тест 2: Перевірка гілки N = 22
        TEST_METHOD(TestBranch2_NormalN_22)
        {
            int N = 22;

            double expected = S0(N);
            double tolerance = 0.00001;

            Assert::AreEqual(expected, S1(N, N), tolerance);
            Assert::AreEqual(expected, S2(N, 22), tolerance);
            Assert::AreEqual(expected, S3(N, N, 0), tolerance);
            Assert::AreEqual(expected, S4(N, 22, 0), tolerance);
        }

        // Тест 3: Граничне значення N = 1
        TEST_METHOD(TestBranch2_MinValue)
        {
            int N = 1;

            double expected = S0(N);
            double tolerance = 0.00001;

            Assert::AreEqual(expected, S1(N, N), tolerance);
            Assert::AreEqual(expected, S2(N, 22), tolerance);
            Assert::AreEqual(expected, S3(N, N, 0), tolerance);
            Assert::AreEqual(expected, S4(N, 22, 0), tolerance);
        }
    };
}
