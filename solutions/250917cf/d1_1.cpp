#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int max_val = n;
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1;
        
        for (int num : a) {
            vector<vector<int>> next_dp(max_val + 1, vector<int>(max_val + 1, 0));
            for (int x = 0; x <= max_val; x++) {
                for (int y = x; y <= max_val; y++) {
                    if (dp[x][y] == 0) continue;
                    next_dp[x][y] = (next_dp[x][y] + dp[x][y]) % MOD;
                    if (!(x < y && num < x)) {
                        if (num >= y) {
                            next_dp[x][num] = (next_dp[x][num] + dp[x][y]) % MOD;
                        } else if (num >= x) {
                            next_dp[num][y] = (next_dp[num][y] + dp[x][y]) % MOD;
                        } else {
                            next_dp[num][x] = (next_dp[num][x] + dp[x][y]) % MOD;
                        }
                    }
                }
            }
            dp = move(next_dp);
        }
        
        long long ans = 0;
        for (int x = 0; x <= max_val; x++) {
            for (int y = x; y <= max_val; y++) {
                ans = (ans + dp[x][y]) % MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}