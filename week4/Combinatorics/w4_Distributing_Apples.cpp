#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int MAX = 2e6 ;
const ll MOD = 1e9 + 7;

vector<ll> fact(MAX), inv_fact(MAX);

// Fast modular exponentiation
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 1; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// Compute C(a, b) % MOD
ll binomial(int a, int b) {
    if (b < 0 || b > a) return 0;
    return (((fact[a] * inv_fact[b]) % MOD) * inv_fact[a - b]) % MOD;
}

int main() {
    int a,b;
    cin >> a >>b;
    precompute();
        cout << binomial(a+b-1, b) << "\n";

    return 0;
}
