#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

int next_power_of_two(int n) {
    int L = 1;
    while (L < n) L <<= 1;
    return L;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> linear_correlation_fft(const vector<int> &x, const vector<int> &y2, int n, int n2) {
    int len_conv = n + n2 - 1;
    int L = next_power_of_two(len_conv);
    vector<cd> x_pad(L, 0), y2_pad(L, 0);
    for (int i = 0; i < n; i++) {
        x_pad[i] = x[i];
    }
    for (int i = 0; i < n2; i++) {
        y2_pad[i] = y2[i];
    }
    fft(x_pad, false);
    fft(y2_pad, false);
    vector<cd> Z(L);
    for (int i = 0; i < L; i++) {
        Z[i] = conj(x_pad[i]) * y2_pad[i];
    }
    fft(Z, true);
    vector<int> result(n);
    for (int d = 0; d < n; d++) {
        result[d] = round(Z[d].real());
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(3);
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }

        int ans = 0;
        for (int idx = 0; idx < 3; idx++) {
            int fixed1 = (idx+1)%3, fixed2 = (idx+2)%3;
            int rotate_idx = idx;
            int A = 0;
            vector<int> M(n, 0);
            for (int i = 0; i < n; i++) {
                if (s[fixed1][i]=='1' && s[fixed2][i]=='1') {
                    A++;
                } else if (s[fixed1][i]=='1' || s[fixed2][i]=='1') {
                    M[i] = 1;
                }
            }
            vector<int> T(n);
            for (int i = 0; i < n; i++) {
                T[i] = (s[rotate_idx][i] == '1') ? 1 : 0;
            }

            vector<int> F(n, 0);
            if (n <= 1000) {
                for (int d = 0; d < n; d++) {
                    for (int i = 0; i < n; i++) {
                        int j = (i + d) % n;
                        if (M[i] && T[j]) {
                            F[d]++;
                        }
                    }
                }
            } else {
                vector<int> y2 = T;
                y2.insert(y2.end(), T.begin(), T.end());
                vector<int> corr = linear_correlation_fft(M, y2, n, 2*n);
                for (int d = 0; d < n; d++) {
                    F[d] = corr[d];
                }
            }

            int max_val = 0;
            for (int d = 0; d < n; d++) {
                int total = A + F[d];
                if (total > max_val) {
                    max_val = total;
                }
            }
            if (max_val > ans) {
                ans = max_val;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}