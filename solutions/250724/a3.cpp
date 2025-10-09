#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1.0);

// FFT implementation
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd& x : a) x /= n;
    }
}

// Convolution using FFT
void fft_convolve(const vector<int>& a, const vector<int>& b, vector<long long>& result, int n) {
    int sz = 1;
    while (sz < 2 * n) sz <<= 1; // Pad to power of 2
    vector<cd> fa(sz, 0), fb(sz, 0);
    for (int i = 0; i < n; i++) {
        fa[i] = a[i];
        fb[i] = b[i];
    }
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < sz; i++) fa[i] *= fb[i];
    fft(fa, true);
    result.assign(n, 0);
    for (int i = 0; i < n; i++) {
        result[i] = (long long)(fa[i].real() + 0.5); // Cyclic convolution
    }
}

int solve_case() {
    int n;
    cin >> n;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    int max_result = 0;
    // Try shifting each string
    for (int shift_str = 0; shift_str < 3; shift_str++) {
        // Compute c[i] = sum of the other two strings
        vector<int> c(n, 0);
        int a = 0; // Count of positions where c[i] = 2
        vector<int> indices; // Positions where c[i] = 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != shift_str) {
                    c[i] += (s[j][i] - '0');
                }
            }
            if (c[i] == 2) a++;
            if (c[i] == 1) indices.push_back(i);
        }

        // Prepare f and g for convolution
        vector<int> f(n, 0), g(n, 0);
        for (int i = 0; i < n; i++) {
            f[i] = (s[shift_str][i] - '0');
        }
        for (int i : indices) {
            g[i] = 1;
        }

        // Compute convolution
        vector<long long> conv;
        fft_convolve(f, g, conv, n);

        // Find maximum
        for (int k = 0; k < n; k++) {
            max_result = max(max_result, a + (int)conv[k]);
        }
    }

    return max_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << solve_case() << "\n";
    }
    return 0;
}