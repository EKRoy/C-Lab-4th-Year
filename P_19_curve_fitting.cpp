/* Program Title:
 Curve Fitting of the form y = a + bx + cx^2 + dx^3
 using Least Squares Method (solving normal equations) */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << fixed << setprecision(5);
    int N;
    cout << "\nEnter the number of data points: ";
    cin >> N;
    vector<double> x(N), y(N);
    cout << "\nEnter the x values:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    cout << "\nEnter the y values:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> y[i];
    }
    int degree;
    cout << "\nEnter the degree of polynomial to fit: ";
    cin >> degree;
    int n = degree + 1;
    vector<double> a(n), X(2 * degree + 1, 0.0);
    vector<vector<double>> B(n, vector<double>(n + 1, 0.0));

    // Calculate sum of powers of x: \sum x^i
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            X[i] += (i == 0) ? 1.0 : pow(x[j], i);
        }
    }
    // Construct Augmented Matrix B
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = X[i + j];
        }
    }
    // Calculate \sum (x^i * y) and assign to last column
    for (int i = 0; i < n; i++)
    {
        double sum = 0.0;
        for (int k = 0; k < N; k++)
        {
            sum += ((i == 0) ? 1.0 : pow(x[k], i)) * y[k];
        }
        B[i][n] = sum;
    }
    // Gaussian Elimination with dynamic Partial Pivoting
    for (int i = 0; i < n; i++)
    {
        // Find pivot element
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(B[k][i]) > fabs(B[maxRow][i]))
            {
                maxRow = k;
            }
        }
        // Swap maximum row with current row
        for (int j = 0; j <= n; j++)
        {
            swap(B[i][j], B[maxRow][j]);
        }

        // Forward elimination
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(B[i][i]) < 1e-12)
                continue; // Avoid division by near-zero
            double t = B[k][i] / B[i][i];
            for (int j = i; j <= n; j++)
            {
                B[k][j] -= t * B[i][j];
            }
        }
    }
    // Back Substitution
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = B[i][n];
        for (int j = i + 1; j < n; j++)
        {
            a[i] -= B[i][j] * a[j];
        }
        a[i] /= B[i][i];
    }

    // Output Coefficients
    cout << "\nCoefficients:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "a" << i << " = " << a[i] << endl;
    }

    // Print polynomial expression matching image format: y = a + bx + cx^2 + ...
    cout << "\nFitted polynomial y = ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << a[i] << ")" << (i > 0 ? "x^" + to_string(i) : "") << (i < n - 1 ? " + " : "");
    }
    cout << "\n";

    return 0;
}