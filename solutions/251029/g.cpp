#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int max_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    // 预处理 m_r：a_i > r 的个数
    vector<int> cnt(max_a + 2, 0);
    for (int x : a) cnt[x]++;
    vector<int> m_r(max_a + 1, 0);
    for (int r = max_a - 1; r >= 0; r--) {
        m_r[r] = m_r[r + 1] + cnt[r + 1];
    }

    // 预处理阶乘
    vector<int> fact(max_a + 1, 1);
    for (int i = 1; i <= max_a; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }

    // 计算 Q = ∏ a_i! mod MOD
    int Q = 1;
    for (int x : a) {
        Q = 1LL * Q * fact[x] % MOD;
    }
    int inv_Q = 1;
    if (Q != 0) inv_Q = 1;
    else inv_Q = 0;
    // 逆元
    auto qpow = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1LL * res * a % MOD;
            a = 1LL * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    inv_Q = qpow(Q, MOD - 2);

    // 计算 P(k) = ∏_{r=0}^{k-1} (k - r)^{m_r}
    vector<int> P(m + 1, 1);
    for (int r = 0; r < max_a; r++) {
        if (m_r[r] == 0) continue;
        for (int k = r + 1; k <= m; k++) {
            int term = (k - r) % MOD;
            term = qpow(term, m_r[r]);
            P[k] = 1LL * P[k] * term % MOD;
        }
    }
    
    for (int k = 1; k < max_a; k++) {
        cout << 0 << '\n';
    }


    // 输出答案
    for (int k = max_a; k <= m; k++) {
        int ans = 1LL * P[k] * inv_Q % MOD;
        cout << ans << '\n';
    }

    return 0;
}