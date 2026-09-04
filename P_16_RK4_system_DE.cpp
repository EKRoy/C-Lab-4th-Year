/* Program Title:
 Solution of Second Order ODE (d²y/dx² + y = 0)
 converted to a system of first-order ODEs,
 solved by Runge-Kutta 4th Order Method */
/*
Let y1 = y, y2 = dy/dx
dy1/dx = y2
dy2/dx = -y1
*/
#include <bits/stdc++.h>
using namespace std;

double f1(double x, double y1, double y2)
{
    return y2; // dy1/dx = y2
}

double f2(double x, double y1, double y2)
{
    return -y1; // dy2/dx = -y1
}
int main()
{
    double x0, y1_0, y2_0, x_final, h;

    cout << "\nEnter the initial value of x: ";
    cin >> x0;
    cout << "\nEnter the initial value of y (y1_0): ";
    cin >> y1_0;
    cout << "\nEnter the initial value of dy/dx (y2_0): ";
    cin >> y2_0;
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

    vector<double> x(n + 1), y1(n + 1), y2(n + 1);
    x[0] = x0;
    y1[0] = y1_0;
    y2[0] = y2_0;

    for (int i = 0; i < n; i++)
    {
        double k1a = h * f1(x[i], y1[i], y2[i]);
        double k1b = h * f2(x[i], y1[i], y2[i]);

        double k2a = h * f1(x[i] + h / 2.0, y1[i] + k1a / 2.0, y2[i] + k1b / 2.0);
        double k2b = h * f2(x[i] + h / 2.0, y1[i] + k1a / 2.0, y2[i] + k1b / 2.0);

        double k3a = h * f1(x[i] + h / 2.0, y1[i] + k2a / 2.0, y2[i] + k2b / 2.0);
        double k3b = h * f2(x[i] + h / 2.0, y1[i] + k2a / 2.0, y2[i] + k2b / 2.0);

        double k4a = h * f1(x[i] + h, y1[i] + k3a, y2[i] + k3b);
        double k4b = h * f2(x[i] + h, y1[i] + k3a, y2[i] + k3b);

        y1[i + 1] = y1[i] + (k1a + 2 * k2a + 2 * k3a + k4a) / 6.0;
        y2[i + 1] = y2[i] + (k1b + 2 * k2b + 2 * k3b + k4b) / 6.0;
        x[i + 1] = x[i] + h;
    }

    cout << fixed << setprecision(6);
    cout << "\n  x\t\ty (y1)\t\tdy/dx (y2)\n";
    for (int i = 0; i <= n; i++)
        cout << "  " << x[i] << "\t" << y1[i] << "\t" << y2[i] << endl;

    cout << "\nThe value of y at x = " << x_final << " is: " << y1[n] << endl;

    double exact, pcerr;
    cout << "\nEnter the exact value of y at x = " << x_final << ": ";
    cin >> exact;

    if (exact != 0)
    {
        pcerr = fabs((exact - y1[n]) / exact) * 100;
        cout << "\nPercentage error is: " << pcerr << " %.\n";
    }
    else
    {
        cout << "\nExact value is zero, percentage error undefined.\n";
    }

    return 0;
}