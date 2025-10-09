#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

const int BITS = 60;
const unsigned long long MASK = (1ULL << 60) - 1;

vector<unsigned long long> str2vec(string x, int m) {
    vector<unsigned long long> ans;
    unsigned long long a;
    int i = 0;
    if (m % 12 != 0) {
        a = 0;
        for (i = 0; i < m % 12; i++) {
            a = (a << 5);
            if (x[i] >= 'a') {
                a += x[i] - 'a' + 10;
            } else {
                a += x[i] - '0';
            }
        }
        ans.push_back(a);
    }
    for (i = m % 12; i < m; i += 12) {
        a = 0;
        for (int j = 0; j < 12; j++) {
            a = (a << 5);
            if (x[i + j] >= 'a') {
                a += x[i + j] - 'a' + 10;
            } else {
                a += x[i + j] - '0';
            }
        }
        ans.push_back(a);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string x_str;
        cin >> x_str;
        vector<unsigned long long> x_vec = str2vec(x_str, m);
        int M = (m + 11) / 12;

        vector<string> a_str(n);
        for (int i = 0; i < n; i++) {
            cin >> a_str[i];
        }

        vector<vector<unsigned long long>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(str2vec(a_str[i], m));
        }

        vector<unsigned long long> total = arr[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < M; j++) {
                total[j] &= arr[i][j];
            }
        }

        bool isTotalSubset = true;
        for (int j = 0; j < M; j++) {
            if (total[j] & ~x_vec[j]) {
                isTotalSubset = false;
                break;
            }
        }
        if (!isTotalSubset) {
            cout << -1 << '\n';
            continue;
        }

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }

        int LOG = 0;
        while ((1 << (LOG + 1)) <= n) {
            LOG++;
        }

        vector<vector<vector<unsigned long long>>> st;
        st.resize(LOG + 1, vector<vector<unsigned long long>>(n, vector<unsigned long long>(M)));

        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }

        for (int j = 1; j <= LOG; j++) {
            int step = 1 << (j - 1);
            for (int i = 0; i + (1 << j) <= n; i++) {
                for (int k = 0; k < M; k++) {
                    st[j][i][k] = st[j - 1][i][k] & st[j - 1][i + step][k];
                }
            }
        }

        auto query_and = [&](int l, int r) {
            if (l > r) {
                vector<unsigned long long> identity(M, ~0ULL);
                return identity;
            }
            int len = r - l + 1;
            int j = 0;
            while ((1 << (j + 1)) <= len) {
                j++;
            }
            vector<unsigned long long> res = st[j][l];
            int right_start = r - (1 << j) + 1;
            if (right_start > l) {
                for (int k = 0; k < M; k++) {
                    res[k] &= st[j][right_start][k];
                }
            }
            return res;
        };

        int segments = 0;
        int i = 0;
        while (i < n) {
            int low = i;
            int high = n - 1;
            int j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                vector<unsigned long long> and_seg = query_and(i, mid);
                bool isSub = true;
                for (int idx = 0; idx < M; idx++) {
                    if (and_seg[idx] & ~x_vec[idx]) {
                        isSub = false;
                        break;
                    }
                }
                if (isSub) {
                    j = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (j == -1) {
                break;
            }
            segments++;
            i = j + 1;
        }

        cout << segments << '\n';
    }

    return 0;
}