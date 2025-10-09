#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        int len_x = x.second - x.first + 1;
        int len_y = y.second - y.first + 1;
        return len_x > len_y;
    });
    
    int root_chain_len = a[0].second - a[0].first + 1;
    if (root_chain_len == 1 && k > 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    vector<int> parent(n+1, 0);
    int l0 = a[0].first;
    int r0 = a[0].second;
    parent[l0] = 0;
    for (int i = l0+1; i <= r0; i++) {
        parent[i] = i-1;
    }
    
    int L0 = r0 - l0 + 1;
    vector<int> new_chain(L0+2);
    new_chain[L0] = l0;
    new_chain[L0+1] = l0;
    for (int i = 0; i < L0; i++) {
        new_chain[i] = r0 - i;
    }
    
    for (int j = 1; j < k; j++) {
        int l = a[j].first;
        int r = a[j].second;
        int L = r - l + 1;
        int d = L - 1;
        if (d == 0) {
            d = 1;
        }
        parent[l] = new_chain[d];
        for (int i = l+1; i <= r; i++) {
            parent[i] = i-1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}