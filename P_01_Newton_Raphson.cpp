/*Program to solve a system of nonlinear equations(two variables only)
with example using the Newton - Raphson method.*/
/* Given system :
   f(x, y) = 9x^2 + 4y^2 - 36 = 0
   g(x, y) = x^2 + y^2 - 6 = 0 */
#include <bits/stdc++.h>
using namespace std;
double f(double x, double y)
{
    return 9*x * x +4* y * y - 36;
}
double g(double x, double y)
{
    return x * x + y * y - 6;
}
double fx(double x, double y)
{
    return 18 * x;
}
double fy(double x, double y)
{
    return 8 * y;
}
double gx(double x, double y)
{
    return 2 * x;
}
double gy(double x, double y)
{
    return 2 * y;
}
void newtonRaphson(double x, double y, double tol)
{
    double h, k, d;
    int iteration = 0;
    while (true)
    {
        d = fx(x, y) * gy(x, y) - fy(x, y) * gx(x, y);
        if (fabs(d) < 1e-9)
        {
            cout << "Jacobian determinant is nearly zero. " << endl;
            cout << "Method fails for the chosen initital values . " << endl;
            return;
        }
        h = (-f(x, y) * gy(x, y) + fy(x, y) * g(x, y)) / d;
        k = (-fx(x, y) * g(x, y) + f(x, y) * gx(x, y)) / d;
        x = x + h;
        y = y + k;
        iteration = iteration + 1;
        if (fabs(f(x, y)) < tol && fabs(g(x, y)) < tol)
        {
            cout << "Convergence achieved  succesfully." << endl;
            cout << "Approximate solution: " << endl;
            cout << "x= " << x << '\n'
                 << "y =" << y << endl;
            return;
        }
    }
}
int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);
    double x, y, tol;
    cout << "Enter the value of initital appriximaitons for x and y: " << endl;
    cin >> x >> y;
    cout << "Enter the required accuracy: " << endl;
    cin >> tol;
    newtonRaphson(x, y, tol);
    return 0;
}