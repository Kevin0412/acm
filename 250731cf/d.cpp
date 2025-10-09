#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cerr<<endl;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (p[j] < p[i]) {
                    cnt[i]++;
                }
            }
        }

        int initial_inv = 0;
        for (int i = 0; i < n; i++) {
            initial_inv += cnt[i];
        }

        vector<int> is_zero(n, 1);
        int ones_count = 0;
        int current = initial_inv;
        int ans = initial_inv;

        for (int i = 0; i < n; i++) {
            int part1 = 0;
            for (int j = 0; j < i; j++) {
                if (is_zero[j] && p[j] > p[i]) {
                    part1++;
                }
            }
            int within0_remove = part1 + cnt[i];
            int within1_add = 0;
            for (int j = 0; j < i; j++) {
                if (!is_zero[j] && p[j] < p[i]) {
                    within1_add++;
                }
            }
            int cross_change = -ones_count + (n - i - 1);
            int net_change = -within0_remove + within1_add + cross_change;

            if (net_change < 0) {
                current += net_change;
                is_zero[i] = 0;
                ones_count++;
                for (int j = 0; j < i; j++) {
                    if (is_zero[j] && p[j] > p[i]) {
                        cnt[j]--;
                    }
                }
            }
            if (current < ans) {
                ans = current;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}