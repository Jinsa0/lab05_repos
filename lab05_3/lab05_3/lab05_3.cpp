// lab05_3.cpp
// Кіц Роман Романович
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);

int main()
{
    double tp, tk;
    int n;
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = ";  cin >> n;

    double dt = (tk - tp) / n;
    cout << "-------------------------" << endl;
    cout << "|" << setw(8) << "t" << " |" << setw(12) << "z" << " |" << endl;
    cout << "-------------------------" << endl;

    double t = tp;
    while (t <= tk + dt / 2.0)
    {
        double z = f(t * t) + 2 * f(2 * t + 1);
        cout << "|" << setw(8) << setprecision(3) << fixed << t << " |"
            << setw(12) << setprecision(5) << fixed << z << " |" << endl;
        t += dt;
    }
    cout << "-------------------------" << endl;
    return 0;
}

double f(const double x)
{
    if (fabs(x) >= 1.0)
    {
        return (sin(x) + 1.0) / (sin(x) + cos(x));
    }
    else
    {
        double a = x; 
        double S = a;
        for (int i = 1; i <= 8; ++i)
        {
            double R = x * x / (2.0 * i * (2.0 * i + 1.0));
            a *= R;
            S += a;
        }
        return S;
    }
}