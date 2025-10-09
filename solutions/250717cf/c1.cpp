#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int max_val = *max_element(h.begin(), h.end());
    if (h[k] == max_val) {
        cout << "YES\n";
        return;
    }

    vector<int> dist(n, -1);
    queue<int> q;
    dist[k] = 0;
    q.push(k);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int dir : {-1, 1}) {
            int v = u + dir;
            if (v < 0 || v >= n) continue;
            if (dist[v] != -1) continue;

            int C = abs(h[u] - h[v]);
            int current_time = dist[u];

            bool safe_during = true;
            for (int time_point = current_time; time_point < current_time + C; time_point++) {
                if (h[u] <= 1 + time_point) {
                    safe_during = false;
                    break;
                }
            }

            bool safe_arrival = (h[v] > 1 + current_time + C);

            if (safe_during && safe_arrival) {
                dist[v] = current_time + C;
                if (h[v] == max_val) {
                    cout << "YES\n";
                    return;
                }
                q.push(v);
            }
        }
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}