/*Program Title:
 Newton's Divided Difference Interpolation
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout.precision(5);
    cout.setf(ios::fixed);

    int n;

    cout << "\nEnter the number of data points: ";
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
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    cout << "\nThe divided difference table is as follows:\n";
    cout << left << setw(12) << "x" << setw(15) << "y";
    for (int i = 1; i < n; i++)
        cout << setw(15) << "d" + to_string(i) + "y";

    cout << "\n"
         << string(15 * (n + 1), '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(12) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << left << setw(15) << y[i][j];
        }
        cout << endl;
    }

    double xn, sum = y[0][0], temp = 1;

    cout << "\nEnter the value of x at which y is to be calculated:\n";
    cin >> xn;

    if (xn >= x[0] && xn <= x[n - 1])
        cout << "\nThis is an INTERPOLATION point.\n";
    else
        cout << "\nThis is an EXTRAPOLATION point.\n";

    for (int j = 1; j < n; j++)
    {
        temp = temp * (xn - x[j - 1]);
        sum = sum + temp * y[0][j];
    }

    cout << "\nThe value of y at x = " << xn << " is: " << sum << endl;

    double exact;
    cout << "\nEnter the exact value:\n";
    cin >> exact;

    double pcerr = fabs((exact - sum) / exact) * 100;
    cout << "\nPercentage error: " << pcerr << " %\n";

    return 0;
}
