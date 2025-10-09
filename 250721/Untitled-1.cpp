#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_S = 90;
const int MAX_LEN = 10;

vector<vector<vector<vector<int>>>> dp0_table;
vector<vector<long long>> pow10_table;

void init() {
    dp0_table.resize(MAX_S + 1);
    pow10_table.resize(MAX_S + 1);
    for (int s_val = 1; s_val <= MAX_S; s_val++) {
        vector<long long> pow10(MAX_LEN + 1);
        pow10[0] = 1;
        for (int i = 1; i <= MAX_LEN; i++) {
            pow10[i] = (pow10[i - 1] * 10) % s_val;
            if (pow10[i] < 0) pow10[i] += s_val;
        }
        pow10_table[s_val] = pow10;

        vector<vector<vector<int>>> dp(MAX_LEN + 1, vector<vector<int>>(s_val + 1, vector<int>(s_val, 0)));
        dp[0][0][0] = 1;
        for (int len = 0; len < MAX_LEN; len++) {
            long long base = pow10[len];
            for (int sum_val = 0; sum_val <= s_val; sum_val++) {
                for (int mod_val = 0; mod_val < s_val; mod_val++) {
                    if (dp[len][sum_val][mod_val] == 0) continue;
                    for (int d = 0; d < 10; d++) {
                        int new_sum = sum_val + d;
                        if (new_sum > s_val) continue;
                        long long new_mod_val = (d * base + mod_val) % s_val;
                        if (new_mod_val < 0) new_mod_val += s_val;
                        dp[len + 1][new_sum][new_mod_val] += dp[len][sum_val][mod_val];
                    }
                }
            }
        }
        dp0_table[s_val] = dp;
    }
}

long long f(long long x, int s, const vector<vector<vector<int>>>& dp0, const vector<long long>& pow10) {
    if (x == 0) {
        return 0;
    }
    string num = to_string(x);
    int n = num.size();
    long long ans = 0;

    function<long long(int, int, int, bool)> dfs = [&](int pos, int already_sum, int already_mod, bool tight) -> long long {
        if (pos == n) {
            if (already_sum == s && already_mod % s == 0) {
                return 1;
            }
            return 0;
        }
        int len_remaining = n - pos;
        if (!tight) {
            int require_sum = s - already_sum;
            if (require_sum < 0 || require_sum > s) {
                return 0;
            }
            long long total_mod = (1LL * already_mod * pow10[len_remaining]) % s;
            total_mod = (total_mod % s + s) % s;
            long long require_mod = (s - total_mod) % s;
            if (require_mod < 0) require_mod += s;
            if (len_remaining < 0 || require_sum < 0 || require_sum > s) 
                return 0;
            return dp0[len_remaining][require_sum][require_mod];
        }
        long long total = 0;
        int up = num[pos] - '0';
        for (int d = 0; d <= up; d++) {
            bool new_tight = tight && (d == up);
            int new_sum = already_sum + d;
            if (new_sum > s) 
                continue;
            int new_mod = (1LL * already_mod * 10 + d) % s;
            if (new_tight) {
                total += dfs(pos + 1, new_sum, new_mod, new_tight);
            } else {
                int len_rest = n - pos - 1;
                int require_sum = s - new_sum;
                if (require_sum < 0 || require_sum > s) 
                    continue;
                long long total_mod_val = (1LL * new_mod * pow10[len_rest]) % s;
                total_mod_val = (total_mod_val % s + s) % s;
                long long require_mod_val = (s - total_mod_val) % s;
                if (require_mod_val < 0) require_mod_val += s;
                if (len_rest < 0 || require_sum < 0 || require_sum > s) 
                    continue;
                total += dp0[len_rest][require_sum][require_mod_val];
            }
        }
        return total;
    };
    return dfs(0, 0, 0, true);
}

long long F(long long x) {
    if (x < 0) return 0;
    if (x == 0) return 0;
    string num = to_string(x);
    int max_possible_sum = num.size() * 9;
    long long res = 0;
    for (int s_val = 1; s_val <= min(max_possible_sum, MAX_S); s_val++) {
        res += f(x, s_val, dp0_table[s_val], pow10_table[s_val]);
    }
    return res;
}

int main() {
    init();
    long long L, R;
    while (cin >> L >> R) {
        long long ans = F(R) - F(L - 1);
        cout << ans << endl;
    }
    return 0;
}