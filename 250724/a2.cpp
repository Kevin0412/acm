#include <bits/stdc++.h>
using namespace std;

// Placeholder for FFT function
void fft_convolve(const vector<int>& a, const vector<int>& b, vector<long long>& result, int n) {
    // This should compute the cyclic convolution of a and b
    // For simplicity, we'll simulate it with a naive O(n^2) approach here
    // Replace with actual FFT for efficiency
    result.assign(n, 0);
    for (int k = 0; k < n; k++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] * b[(i - k + n) % n];
        }
        result[k] = sum;
    }
}

char s[3][100005];

int solve_case() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < 3; i++) {
        //cin >> s[i];
        scanf("%s",s[i]);
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
    int t;
    scanf("%d",&t);
    while (t--) {
        printf("%d\n",solve_case());
    }
    return 0;
}