#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const long long MOD = 1000000007;

long long fac[MAXN + 1];

// 快读模板
template <typename T>
void read(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    int t;
    read(t);
    vector<long long> result;
    while (t--) {
        int n, m;
        read(n);
        read(m);

        // 读取置换 q（实际未使用）
        for (int i = 0; i < n; i++) {
            int x;
            read(x);
        }

        // 读取序列 k（实际未使用）
        for (int i = 0; i < m; i++) {
            int x;
            read(x);
        }

        // 计算 (n!)^m mod MOD
        long long ans = pow_mod(fac[n], m, MOD);
        result.push_back(ans);
    }
    for(auto ans:result) printf("%lld\n",ans);
    return 0;
}