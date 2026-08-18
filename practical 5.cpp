#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& weight, const vector<int>& value, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int w = 1; w <= W; w++)
            if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];

    return dp[n][W];
}

int main()
{
    int n, W;

    cout << "========================================\n";
    cout << "       0/1 KNAPSACK PROBLEM\n";
    cout << "        DYNAMIC PROGRAMMING\n";
    cout << "========================================\n";

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weight[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> value[i];

    cout << "Enter maximum capacity: ";
    cin >> W;

    cout << "\nMaximum value = " << knapsack(W, weight, value, n) << endl;

    cout << "\n========================================\n";
    cout << "Name       : GUGULOTHU RAVINDRA NAIK\n";
    cout << "Enrollment : 92400118332\n";
    cout << "Division   : 5-EN18\n";
    cout << "========================================\n";

    return 0;
}
