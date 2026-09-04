/* Program Title:
 Numerical Solution of Parabolic Type PDE
 du/dt = c^2 * d^2u/dx^2
 using Explicit Finite Difference Method (FTCS Scheme) */
/*
Example (Heat Equation):
du/dt = d^2u/dx^2
Subject to:
u(x,0) = sin(pi*x)
u(0,t) = u(1,t) = 0
*/
#include <bits/stdc++.h>
using namespace std;

#define pi 3.14159265

double f(double x)
{
    return sin(pi * x);
}

double exactf(double x, double t)
{
    return exp(-(pi * pi) * t) * sin(pi * x);
}

int main()
{
    cout << fixed << setprecision(6);

    double cc, x1, x2, t2, h, k;

    cout << "\nEnter the value of c^2: ";
    cin >> cc;

    cout << "\nEnter the initial value of x: ";
    cin >> x1;
    cout << "Enter the final value of x: ";
    cin >> x2;

    cout << "\nEnter the final simulation time: ";
    cin >> t2;

    cout << "\nEnter the value of h (space step) and k (time step): ";
    cin >> h >> k;

    double L = x2 - x1;
    double alpha = (cc * k) / (h * h);

    if (alpha < 0 || alpha > 0.5)
    {
        cout << "\nStability condition violated (0 <= alpha <= 0.5 required). Exiting.\n";
        return 0;
    }

    int m = (int)round(L / h);
    int n = (int)round(t2 / k);

    vector<vector<double>> u(n + 1, vector<double>(m + 1, 0.0));

    for (int j = 0; j <= m; j++)
        u[0][j] = f(x1 + j * h);

    for (int i = 0; i <= n; i++)
    {
        u[i][0] = 0.0;
        u[i][m] = 0.0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            u[i + 1][j] = u[i][j] + alpha * (u[i][j + 1] - 2 * u[i][j] + u[i][j - 1]);
        }
    }

    cout << "\nSolution table u(x,t):\n\n";
    for (int i = 0; i <= n; i++)
    {
        double t = i * k;
        for (int j = 0; j <= m; j++)
        {
            double x = x1 + j * h;
            cout << "u(" << x << ", " << t << ") = " << u[i][j] << endl;
        }
    }

    double x, t;
    cout << "\nEnter a specific x to check against the exact solution: ";
    cin >> x;
    cout << "Enter a specific t to check against the exact solution: ";
    cin >> t;

    int i = (int)round(t / k);
    int j = (int)round((x - x1) / h);

    if (i < 0 || i > n || j < 0 || j > m)
    {
        cout << "\nInvalid (x,t) value!\n";
    }
    else
    {
        double numerical = u[i][j];
        double exact = exactf(x, t);
        double err = fabs(exact - numerical);

        cout << "\nNumerical value : u(" << x << ", " << t << ") = " << numerical << endl;
        cout << "Exact value     : " << exact << endl;
        cout << "Absolute error  : " << err << endl;
    }

    return 0;
}