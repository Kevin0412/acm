#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s;
        cin >> t;

        int T_rev = 0;
        for (int i = m - 1; i >= 0; i--) {
            T_rev = (T_rev << 1) | (t[i] - '0');
        }

        int mask = (1 << m) - 1;
        int state = 0;
        int ans = 0;
        bool valid = true;

        for (int i = 0; i < n; i++) {
            state = (state << 1) & mask;
            int p = __builtin_parity(state & T_rev);
            int current = (s[i] - '0') ^ p;

            if (current) {
                if (i > n - m) {
                    valid = false;
                    ans = -1;
                    break;
                }
                ans++;
                state |= 1;
            }
        }

        if (!valid) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}