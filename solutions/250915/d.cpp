#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_M = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, y;
        cin >> n >> y;
        vector<int> c(n);
        vector<int> freq(MAX_M + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            if (c[i] <= MAX_M) {
                freq[c[i]]++;
            }
        }
        
        vector<long long> pref(MAX_M + 1, 0);
        pref[0] = 0;
        for (int i = 1; i <= MAX_M; i++) {
            pref[i] = pref[i-1] + freq[i];
        }
        
        long long ans = LLONG_MIN;
        
        for (int x = 2; x <= MAX_M; x++) {
            long long total_new = 0;
            long long reuse = 0;
            int k = 1;
            while (true) {
                int L = (k-1)*x + 1;
                if (L > MAX_M) break;
                int R = min(k*x, MAX_M);
                long long count_k = pref[R] - pref[L-1];
                if (count_k > 0) {
                    total_new += k * count_k;
                    reuse += min(static_cast<long long>(freq[k]), count_k);
                }
                k++;
            }
            long long income = total_new - y * (n - reuse);
            if (income > ans) {
                ans = income;
            }
        }
        
        long long reuse_x_inf = min(static_cast<long long>(freq[1]), static_cast<long long>(n));
        long long income_x_inf = n - y * (n - reuse_x_inf);
        if (income_x_inf > ans) {
            ans = income_x_inf;
        }
        
        cout << ans << '\n';
    }
    return 0;
}