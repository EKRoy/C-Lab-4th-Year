
//  Program Title:
//  Numerical Integration using Trapezoidal Rule

#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x;
}
int main()
{
    int n;
    double a, b;
    cout << "\nEnter the lower and upper limits of the integral:\n";
    cin >> a >> b;
    cout << "\nEnter the number of divisions:\n";
    cin >> n;
    double h = (b - a) / n;
    double x[n + 1], y[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    double sum = y[0] + y[n];
    for (int i = 1; i < n; i++)
    {
        sum = sum + 2 * y[i];
    }
    double result = (h / 2.0) * sum;
    cout << "\nThe value of the integral is: " << result << endl;
    double exact;
    cout << "\nEnter the exact value:\n";
    cin >> exact;
    double pcerr = fabs((exact - result) / exact) * 100;
    cout << "\nPercentage error: " << pcerr << " %\n";

    return 0;
}
