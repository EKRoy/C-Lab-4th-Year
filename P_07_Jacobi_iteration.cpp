/*Program Title:
 Solution of System of Linear Equations using
 Jacobi Iterative Method
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int n;
    cout << "\nEnter number of n: ";
    cin >> n;
    double a[n][n + 1];
    double x[n];
    double x1[n];
    double eps;
    cout << "\nEnter augmented matrix (coefficients + RHS):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(a[i][i]) < fabs(a[k][i]))
            {
                for (int j = 0; j <= n; j++)
                {
                    double t = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = t;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                sum += fabs(a[i][j]);
        }

        if (fabs(a[i][i]) < sum)
        {
            cout << "\nThe system is NOT diagonally dominant.\n";
            cout << "Jacobi method may not converge.\n";
            return 0;
        }
    }

    cout << "\nThe diagonally dominant system is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << setw(15) << a[i][j];
        cout << endl;
    }
    cout << "\nEnter initial guess values:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = ";
        cin >> x[i];
    }
    cout << "\nEnter allowed error (tolerance): ";
    cin >> eps;
    int iter = 0;
    while (true)
    {
        iter++;
        for (int i = 0; i < n; i++)
        {
            double sum = a[i][n]; // RHS
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x1[i] = sum / a[i][i];
        }
        cout << "Iteration " << iter << ": ";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << x1[i] << "  ";
        cout << endl;

        bool stop = true;
        for (int i = 0; i < n; i++)
        {
            if (fabs(x1[i] - x[i]) > eps)
                stop = false;

            x[i] = x1[i];
        }
        if (stop)
            break;
    }
    cout << "\nFinal solution after " << iter << " iterations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}