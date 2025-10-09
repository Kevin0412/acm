#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    long long freq[4] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    long long best = LLONG_MAX;

    for (int r = 0; r < 4; r++) {
        long long mod0 = (0 + r) % 4;
        long long mod1 = (1 + r) % 4;
        long long mod2 = (2 + r) % 4;
        long long mod3 = (3 + r) % 4;

        long long A_r = freq[0] * mod0 + freq[1] * mod1 + freq[2] * mod2 + freq[3] * mod3;

        long long candidate;
        if (A_r <= r) {
            candidate = r;
        } else {
            long long diff = A_r - r;
            long long k = (diff + 3) / 4;
            candidate = 4 * k + r;
        }

        if (candidate < best) {
            best = candidate;
        }
    }

    cout << best << '\n';
}