// lab05_4.cpp
// Кіц Роман Романович
// Лабораторна робота № 5.1
// Обчислення сум та добутків за допомогою рекурсії.
// Варіант 12

#include <iostream>
#include <cmath>

using namespace std;

// 0. Ітераційний спосіб
double S0(const int N)
{
    double s = 0;
    for (int i = N; i <= 22; i++)
        s += sqrt(i * i + N * N) / i;
    return s;
}

// 1. Рекурсивний підйом, параметр i зростає
double S1(const int N, const int i) 
{
    if (i > 22)
        return 0;
    else
        return sqrt(i * i + N * N) / i + S1(N, i + 1);
}

// 2. Рекурсивний підйом, параметр i спадає
double S2(const int N, const int i)
{
    if (i < N)
        return 0;
    else
        return sqrt(i * i + N * N) / i + S2(N, i - 1);
}

// 3. Рекурсивний спуск, параметр i зростає
double S3(const int N, const int i, double t)
{
    t += sqrt(i * i + N * N) / i;
    if (i >= 22)
        return t;
    else
        return S3(N, i + 1, t);
}

// 4. Рекурсивний спуск, параметр i спадає
double S4(const int N, const int i, double t)
{
    t += sqrt(i * i + N * N) / i;
    if (i <= N)
        return t;
    else
        return S4(N, i - 1, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, N) << endl;
    cout << "(rec up --) S2 = " << S2(N, 22) << endl;
    cout << "(rec down ++) S3 = " << S3(N, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, 22, 0) << endl;

    return 0;
}