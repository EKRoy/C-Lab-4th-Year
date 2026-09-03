
/*Program Title:
 Lagrange Interpolation and Extrapolation
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);
    int n;
    cout << "\nEnter number of n: ";
    cin >> n;
    double x[n], y[n];
    cout << "\nEnter values of x:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << "\nEnter corresponding values of y:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i];

    double xn;
    cout << "\nEnter the value of x:\n";
    cin >> xn;

    double fx = 0;
    for (int j = 0; j < n; j++)
    {
        double term = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != j)
            {
                term = term * ((xn - x[i]) / (x[j] - x[i]));
            }
        }
        fx = fx + term * y[j];
    }

    cout << "\nThe value of f(" << xn << ") = " << fx << endl;

    if (xn >= x[0] && xn <= x[n - 1])
        cout << "\nThis is an INTERPOLATION point.\n";
    else
        cout << "\nThis is an EXTRAPOLATION point.\n";

    double exact;
    cout << "\nEnter exact value: ";
    cin >> exact;

    double error = fabs((exact - fx) / exact) * 100;
    cout << "\nPercentage Error = " << error << " %\n";

    return 0;
}
