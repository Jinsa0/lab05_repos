// lab05_1.cpp
// Кіц Роман Романович
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз.
// Варіант 12

#include <iostream>
#include <cmath>

using namespace std;

double f(const double a, const double b, const double c);

int main()
{
    double s, t;

    cout << "s = "; cin >> s;
    cout << "t = "; cin >> t;

    double z = (f(1, t + s, s) + f(t, s * t, 1)) / (1 + pow(f(s, 1, t),2));
    cout << "z = " << z << endl;
    return 0;
}

double f(const double a, const double b, const double c)
{
    return a * sin(b) + b * sin(a) * c * c;
}