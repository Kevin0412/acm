#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

// 快速幂函数
long long quick_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) { // 如果 exp 是奇数
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1; // exp = exp / 2
    }
    return result;
}

// 求模逆元函数（费马小定理）
long long mod_inverse(long long a, long long mod) {
    return quick_pow(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> results(t);

    for (int i = 0; i < t; ++i) {
        long long a, b;
        cin >> a >> b;
        results[i] = (b * mod_inverse(a - b + 1, MOD)) % MOD;
    }

    for (int i = 0; i < t; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}