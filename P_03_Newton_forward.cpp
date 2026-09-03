/*Program Title:
 Interpolation using Newton’s Forward Difference Formula
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);
    int n;
    cout << "\nEnter the value of n:\n";
    cin >> n;
    double x[n], y[n][n];
    cout << "\nEnter the values of x:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "\nEnter the values of y:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i][0];

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    cout << "\nThe forward difference table is as follows:\n";
    cout << left << setw(12) << "x"
         << setw(15) << "y";

    for (int i = 1; i < n; i++)
    {
        cout << left << setw(15) << "d" + to_string(i) + "y";
    }
    cout << "\n"
         << string(15 * (n + 1), '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(12) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << left << setw(15) << y[i][j];
        }
        cout << "\n";
    }
    double p, h, xn, sum = y[0][0], temp = 1;
    h = x[1] - x[0];

    cout << "\nEnter the value at which y is to be calculated:\n";
    cin >> xn;
    p = (xn - x[0]) / h;
    for (int j = 1; j < n; j++)
    {
        temp = temp * (p - j + 1) / j;
        sum = sum + temp * y[0][j];
    }
    cout << "\nThe value of y at x = " << xn << " is  : " << sum << endl;

    return 0;
}
