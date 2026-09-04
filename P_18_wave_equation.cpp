/* Program Title:
 Numerical Solution of Hyperbolic Type PDE
 u_tt = c^2 * u_xx
 using Explicit Finite Difference (Central Difference) Method */
/*
Example (Wave Equation):
u_tt = c^2 * u_xx
Subject to:
u(x,0)   = sin(pi*x)
u_t(x,0) = 0
u(x_i,t) = u_i, u(x_f,t) = u_f
Exact solution (c=1, zero boundaries): u(x,t) = cos(pi*t) * sin(pi*x)
*/
#include <bits/stdc++.h>
using namespace std;

#define pi 3.14159

double f(double x)
{
    return sin(pi * x);
}

double exactf(double x, double t)
{
    return cos(pi * t) * sin(pi * x);
}

int main()
{
    cout << fixed << setprecision(6);

    double c, h, k, x_i, x_f, t_f, u_i, u_f;
    double t_i = 0.0;

    cout << "\nEnter value of c: ";
    cin >> c;

    cout << "\nEnter initial x and corresponding u (left boundary): ";
    cin >> x_i >> u_i;

    cout << "Enter final x and corresponding u (right boundary): ";
    cin >> x_f >> u_f;

    cout << "\nEnter the final simulation time: ";
    cin >> t_f;

    cout << "\nEnter the value of h (space step) and k (time step): ";
    cin >> h >> k;

    double alpha = (c * k) / h;

    if (alpha > 1.0)
    {
        cout << "\nCFL condition violated (alpha > 1). Exiting.\n";
        return 0;
    }

    int m = (int)ceil((x_f - x_i) / h);
    int n = (int)ceil((t_f - t_i) / k);

    vector<vector<double>> u(n + 1, vector<double>(m + 1, 0.0));

    for (int i = 0; i <= n; i++)
    {
        u[i][0] = u_i;
        u[i][m] = u_f;
    }

    for (int j = 1; j < m; j++)
        u[0][j] = f(x_i + j * h);

    for (int j = 1; j < m; j++)
    {
        u[1][j] = u[0][j] + 0.5 * alpha * alpha *
                                (u[0][j + 1] - 2 * u[0][j] + u[0][j - 1]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            u[i + 1][j] = 2 * u[i][j] - u[i - 1][j] +
                          alpha * alpha * (u[i][j + 1] - 2 * u[i][j] + u[i][j - 1]);
        }
    }

    cout << "\nSolution table u(x,t):\n\n";
    for (int i = 0; i <= n; i++)
    {
        double t = t_i + i * k;
        for (int j = 0; j <= m; j++)
        {
            double x = x_i + j * h;
            cout << "u(" << x << ", " << t << ") = " << u[i][j] << endl;
        }
    }

    double x, t;
    cout << "\nEnter a specific x to check against the exact solution: ";
    cin >> x;
    cout << "Enter a specific t to check against the exact solution: ";
    cin >> t;

    int i = (int)round((t - t_i) / k);
    int j = (int)round((x - x_i) / h);

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