#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);

    dp[0] = 0; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[n] == INF)
        cout << -1 << endl;
    else
        cout << dp[n] << endl;

    return 0;
}
