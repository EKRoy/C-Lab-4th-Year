//  Program Name : Least Squares Polynomial Curve Fitting with Derivatives
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << fixed << setprecision(3);
    int N;
    cout << "Enter the value of n : ";
    cin >> N;
    vector<double> x(N), y(N);

    cout << "Enter the x-axis values: ";
    for (int i = 0; i < N; i++)
        cin >> x[i];

    cout << "Enter the y-axis values: ";
    for (int i = 0; i < N; i++)
        cin >> y[i];

    
    int degree; 
    cout << "Enter the degree of the polynomial to fit: ";
    cin >> degree;
    int n = degree + 1;

    vector<double> a(n), C(n), X(2 * degree + 1, 0.0);

    vector<vector<double>> B(n, vector<double>(n + 1, 0.0));

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < N; j++)
            X[i] += pow(x[j], i);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = X[i + j];

    for (int i = 0; i < n; i++)
    {
        C[i] = 0.0;
        for (int k = 0; k < N; k++)
            C[i] += pow(x[k], i) * y[k];

        B[i][n] = C[i];
    }

    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (abs(B[i][i]) < abs(B[k][i]))
                swap(B[i], B[k]);

    for (int i = 0; i < n - 1; i++)
        for (int k = i + 1; k < n; k++)
        {
            double t = B[k][i] / B[i][i];
            for (int j = i; j <= n; j++)
                B[k][j] -= t * B[i][j];
        }

    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = B[i][n];
        for (int j = i + 1; j < n; j++)
            a[i] -= B[i][j] * a[j];
        a[i] /= B[i][i];
    }

    cout << "\nCoefficients:\n";
    for (int i = 0; i < n; i++)
        cout << "a" << i << " = " << a[i] << endl;

    cout << "\nFitted Polynomial: y = ";
    for (int i = 0; i < n; i++)
        cout << "(" << a[i] << ")x^" << i
             << (i < n - 1 ? " + " : "");
    cout << "\n";

    double t;
    cout << "\nEnter the value of x to compute function and derivatives: ";
    cin >> t;

    double fv = 0.0;
    for (int i = 0; i < n; i++)
        fv += a[i] * pow(t, i);
    cout << "Functional Value y(" << t << ") = " << fv << endl;

    double d1 = 0.0;
    for (int i = 1; i < n; i++)
        d1 += i * a[i] * pow(t, i - 1);
    cout << "1st Derivative y'(" << t << ") = " << d1 << endl;

    double d2 = 0.0;
    for (int i = 2; i < n; i++)
        d2 += i * (i - 1) * a[i] * pow(t, i - 2);
    cout << "2nd Derivative y''(" << t << ") = " << d2 << endl;

    double d3 = 0.0;
    for (int i = 3; i < n; i++)
        d3 += i * (i - 1) * (i - 2) * a[i] * pow(t, i - 3);
    cout << "3rd Derivative y'''(" << t << ") = " << d3 << endl;

    return 0;
}