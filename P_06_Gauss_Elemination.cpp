/*Program to solve a system of 𝑛 linear equations by using Gauss’s
Elimination method. */
#include <bits/stdc++.h>
using namespace std;
void printMatrix(double a[][101], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
void pivotisation(double a[][101], int n)
{
    for (int i = 0; i < n; i++)
    {
        int pivot_row = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(a[k][i]) > fabs(a[pivot_row][i]))
                pivot_row = k;

        if (fabs(a[pivot_row][i]) < 1e-12)
        {
            cout << "\nThe system is inconsistent\n";
            exit(0);
        }

        if (pivot_row != i)
        {
            for (int j = 0; j < n + 1; j++)
                swap(a[i][j], a[pivot_row][j]);
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n + 1; j++)
                a[k][j] -= factor * a[i][j];
        }
    }
}

void backSubstitution(double a[][101], double x[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (fabs(a[i][i]) < 1e-12)
        {
            cout << "\nThe system is inconsistent\n";
            exit(0);
        }
        else
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i] / a[i][i];
        }
    }
}

int main()
{
    cout << fixed << setprecision(3);
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;
    double a[100][101], x[100];

    cout << "\nEnter the elements of the augmented matrix row-wise:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    pivotisation(a, n);
    cout << "\nMatrix after Gauss Elimination:\n";
    printMatrix(a, n);
    backSubstitution(a, x, n);
    cout << "\nThe values of the variables are:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << "\n";
    }

    return 0;
}