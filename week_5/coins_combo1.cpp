#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> coins(m);
    for (int i = 0; i < m; ++i)
        cin >> coins[i];

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
