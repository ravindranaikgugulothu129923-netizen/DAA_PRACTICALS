#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(const vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "========================================\n";
    cout << "          COIN CHANGE PROBLEM\n";
    cout << "         DYNAMIC PROGRAMMING\n";
    cout << "========================================\n";

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);

    if (result == INT_MAX)
        cout << "\nAmount cannot be made using given coins." << endl;
    else
        cout << "\nMinimum number of coins = " << result << endl;

    cout << "\n========================================\n";
    cout << "Name       : GUGULOTHU RAVINDRA NAIK\n";
    cout << "Enrollment : 92400118332\n";
    cout << "Division   : 5-EN18\n";
    cout << "Lab Batch  : B\n";
    cout << "========================================\n";

    return 0;
}
