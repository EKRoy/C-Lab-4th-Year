/*
 Program Title:
 Numerical Integration using Simpson's 1/3 Rule
*/

#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1 / (1 + x);
}
int main()
{

    int n;
    double a, b;
    cout << "\nEnter the lower and upper limits of the integral:\n";
    cin >> a >> b;

    cout << "\nEnter the number of divisions:\n";
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "\nThe number of divisions must be even for this method.\n";
        return 0;
    }
    double h = (b - a) / n;
    double x[n + 1], y[n + 1];
    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }

    double sum = y[0] + y[n];

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum += 2 * y[i];
        else
            sum += 4 * y[i];
    }

    double result = sum * (h / 3);
    cout << "\nThe value of the integral is: " << result << endl;
    double exact;
    cout << "\nEnter the exact value:\n";
    cin >> exact;
    double pcerr = fabs((exact - result) / exact) * 100;
    cout << "\nPercentage error: " << pcerr << " %\n";
}
