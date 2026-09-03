/*Program Title:
 Solution of System of Linear Equations using
 Gauss–Seidel Iterative Method
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout.precision(5);
    cout.setf(ios::fixed);
    int n;
    cout << "\nEnter the number of variables:\n";
    cin >> n;

    double a[n][n + 1], x[n], oldx[n], eps;

    cout << "\nEnter the augmented matrix (row-wise):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
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
            if (j != i)
                sum += fabs(a[i][j]); 
        }

        if (fabs(a[i][i]) < sum)
        {
            cout << "\nThe system is NOT diagonally dominant.\n";
            cout << "Gauss-Seidel method may not converge.\n";
            cout << "Try again with a different system or by interchanging the equations.\n";
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

    cout << "\nEnter the allowed error (tolerance): \n";
    cin >> eps;

    int iter = 0;
    while (true)
    {
        iter++;

        for (int i = 0; i < n; i++)
            oldx[i] = x[i];

        for (int i = 0; i < n; i++)
        {
            double sum = a[i][n]; // RHS
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x[i] = sum / a[i][i];
        }

        cout << "\nIteration " << iter << ": ";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << setw(15) << x[i];
        cout << endl;

        bool stop = true;
        for (int i = 0; i < n; i++)
        {
            if (fabs(x[i] - oldx[i]) > eps)
                stop = false;
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