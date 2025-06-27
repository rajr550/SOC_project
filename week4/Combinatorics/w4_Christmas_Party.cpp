#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> D(n + 2);
    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i <= n; ++i) {
        D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % MOD;
    }
    cout << D[n] << endl;
    return 0;
}
