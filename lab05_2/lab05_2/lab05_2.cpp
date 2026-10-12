// lab05_2.cpp
// Кіц Роман Романович
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Обчислює суму ряду Тейлора для arctg x (x < -1) з точністю eps:
// x – аргумент, n – кількість обчислених доданків, s – сума ряду
void S(const double x, const double eps, int& n, double& s);

// Обчислює наступний доданок ряду a за рекурентним співвідношенням:
// x – аргумент, n – номер доданку, a – попередній доданок (стає поточним)
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;    // початок інтервалу, має бути < -1
    cout << "xk = "; cin >> xk;    // кінець інтервалу, має бути < -1
    cout << "dx = "; cin >> dx;    // крок
    cout << "eps = "; cin >> eps;  // точність

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "atan(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << atan(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = -1.0 / x;         // перший доданок (n = 0)
    s = -acos(-1.0) / 2 + a;     // -pi/2 + a0
    do {
        n++;
        A(x, n, a);              // наступний доданок
        s += a;
    } while (fabs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    // коефіцієнт рекурентності: a(n) / a(n-1)
    double R = -(2.0 * n - 1) / ((2.0 * n + 1) * x * x);
    a *= R;
}
