#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // 1x1 materials
        int k1;
        cin >> k1;
        vector<long long> v1(k1);
        for (int i = 0; i < k1; i++) {
            cin >> v1[i];
        }
        sort(v1.rbegin(), v1.rend());
        vector<long long> sum1(k1 + 1, 0);
        for (int i = 1; i <= k1; i++) {
            sum1[i] = sum1[i - 1] + v1[i - 1];
        }

        // 1x2 materials
        int k2;
        cin >> k2;
        vector<long long> v2(k2);
        for (int i = 0; i < k2; i++) {
            cin >> v2[i];
        }
        sort(v2.rbegin(), v2.rend());
        vector<long long> sum2(k2 + 1, 0);
        for (int i = 1; i <= k2; i++) {
            sum2[i] = sum2[i - 1] + v2[i - 1];
        }

        // 1x3 materials
        int k3;
        cin >> k3;
        vector<long long> v3(k3);
        for (int i = 0; i < k3; i++) {
            cin >> v3[i];
        }
        sort(v3.rbegin(), v3.rend());
        vector<long long> sum3(k3 + 1, 0);
        for (int i = 1; i <= k3; i++) {
            sum3[i] = sum3[i - 1] + v3[i - 1];
        }

        // 2x2 materials
        int k4;
        cin >> k4;
        vector<long long> v4(k4);
        for (int i = 0; i < k4; i++) {
            cin >> v4[i];
        }
        sort(v4.rbegin(), v4.rend());
        vector<long long> sum4(k4 + 1, 0);
        for (int i = 1; i <= k4; i++) {
            sum4[i] = sum4[i - 1] + v4[i - 1];
        }

        // Calculate value from 1x1 slots
        long long S1 = 0;
        if (k1 > 0) {
            if (a <= k1) {
                S1 = sum1[a];
            } else {
                S1 = sum1[k1];
            }
        }

        // Total space for other slots (1x2, 1x3, 2x2)
        long long total_space_other = 2 * b + 3 * c + 4 * d;
        long long ans_other = 0;

        // Enumerate x3 (number of 1x3 materials used in 1x3 slots)
        int x3_max = min(static_cast<long long>(k3), static_cast<long long>(c));
        int x4_max = min(static_cast<long long>(k4), static_cast<long long>(d));

        for (int x3 = 0; x3 <= x3_max; x3++) {
            for (int x4 = 0; x4 <= x4_max; x4++) {
                // Calculate maximum number of 1x2 materials that can be used
                long long x2_max_val = b + (c - x3) + 2 * (d - x4);
                if (x2_max_val < 0) x2_max_val = 0;
                int x2_max = min(static_cast<long long>(k2), x2_max_val);

                // Precompute base values to avoid repeated calculations
                long long base_space = 3LL * x3 + 4LL * x4;
                long long base_non_value = sum3[x3] + sum4[x4];

                for (int x2 = 0; x2 <= x2_max; x2++) {
                    // Space used by non-1x1 materials
                    long long space_used = 2LL * x2 + base_space;
                    if (space_used > total_space_other) continue;
                    long long R = total_space_other - space_used;

                    // Value from filling 1x1 materials
                    long long fill_value = 0;
                    if (k1 > a) {
                        int remain_1 = k1 - a;
                        long long fill_num = min(static_cast<long long>(remain_1), R);
                        fill_value = sum1[a + fill_num] - sum1[a];
                    }

                    // Value from non-1x1 materials
                    long long non_value = base_non_value + sum2[x2];
                    long long total_value = non_value + fill_value;
                    if (total_value > ans_other) {
                        ans_other = total_value;
                    }
                }
            }
        }

        // Total value from 1x1 slots and other slots
        long long ans_total = S1 + ans_other;
        cout << ans_total << '\n';
    }
    return 0;
}