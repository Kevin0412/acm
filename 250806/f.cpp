#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> base(64, 0);

    for (int i = 0; i < n; i++) {
        long long x = a[i];
        for (int j = 63; j >= 0; j--) {
            if ((x >> j) & 1) {
                if (base[j] == 0) {
                    base[j] = x;
                    break;
                } else {
                    x ^= base[j];
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 63; j >= 0; j--) {
        if (base[j] != 0 && ((ans >> j) & 1) == 0) {
            ans ^= base[j];
        }
    }

    cout << ans << endl;
    return 0;
}