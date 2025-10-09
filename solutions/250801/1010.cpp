#include<bits/stdc++.h>

using namespace std;

double dp[100005], p[100005];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<double> result;
    result.clear();
    int t;
    read(t);
    while (t--) {
        int i, n;
        read(n);
        for (i = 0; i < n; i++) {
            read(p[i]);
            p[i] /= 1000;
        }
        dp[n - 1] = n;
        for (i = n - 2; i >= 0; i--) {
            dp[i] = min((1 - p[i]) * (i + 1) + p[i] * (dp[i + 1] + 20), dp[i + 1]);
        }
        double ans = n;
        for (i = 0; i < n; i++) {
            ans = min(dp[i], ans);
        }
        result.push_back(ans);
    }
    for (auto ans : result) printf("%.10lf\n", ans);
    return 0;
}