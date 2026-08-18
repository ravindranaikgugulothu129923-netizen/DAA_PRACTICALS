#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(const vector<int>& p, int n)
{
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    for (int length = 2; length <= n; length++)
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }

    return m[1][n];
}

int main()
{
    int n;

    cout << "========================================\n";
    cout << "      MATRIX CHAIN MULTIPLICATION\n";
    cout << "        DYNAMIC PROGRAMMING\n";
    cout << "========================================\n";

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions:\n";
    for (int i = 0; i <= n; i++) cin >> p[i];

    cout << "\nMinimum number of scalar multiplications = "
         << matrixChainMultiplication(p, n) << endl;

    cout << "\n========================================\n";
    cout << "Name       : GUGULOTHU RAVINDRA NAIK\n";
    cout << "Enrollment : 92400118332\n";
    cout << "Division   : 5-EN18\n";
    cout << "========================================\n";

    return 0;
}
