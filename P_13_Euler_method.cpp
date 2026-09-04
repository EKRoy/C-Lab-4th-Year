/* Program Title:
 Solution of First Order Ordinary Differential Equation
 using Euler's Method */
/*
Function defining the given differential equation
dy/dx = y - x
*/
#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return y - x;
}

int main()
{
    double x0, y0, x_final, h;
    cout << "\nEnter the initial value of x: ";
    cin >> x0;
    cout << "\nEnter the initial value of y: ";
    cin >> y0;
    cout << "\nEnter the step size h (must be positive): ";
    cin >> h;

    if (h <= 0)
    {
        cout << "\nStep size must be positive.\n";
        return 0;
    }

    cout << "\nEnter the value of x at which you want to find y: ";
    cin >> x_final;

    int n = (int)ceil((x_final - x0) / h);
    if (n <= 0 || x_final <= x0)
    {
        cout << "\nInvalid input values.\n";
        return 0;
    }

    vector<double> x(n + 1), y(n + 1);
    x[0] = x0;
    y[0] = y0;

    for (int i = 0; i < n; i++)
    {
        y[i + 1] = y[i] + h * f(x[i], y[i]);
        x[i + 1] = x[i] + h;
    }

    cout << "\nThe value of y at x = " << x_final << " is: " << y[n] << endl;

    double exact, pcerr;
    cout << "\nEnter the exact value of y at x = " << x_final << ": ";
    cin >> exact;

    if (exact != 0)
    {
        pcerr = fabs((exact - y[n]) / exact) * 100;
        cout << "\nPercentage error is: " << pcerr << " %.\n";
    }
    else
    {
        cout << "\nExact value is zero, percentage error undefined.\n";
    }

    return 0;
}