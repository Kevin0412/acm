#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 200000;
const int K_MAX = 60;
const long long INF = 1e18;

struct NodeDS {
    vector<long long> sorted_d;
    vector<long long> prefix_max;
};

vector<NodeDS> ds_array;
vector<vector<pair<int, int>>> adj;
vector<long long> max_d_arr;
vector<vector<long long>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, Q;
    cin >> n >> m >> Q;

    adj.resize(n+1);
    max_d_arr.resize(n+1, 0);

    for (int i=0; i<m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        if (d > max_d_arr[u]) max_d_arr[u] = d;
    }

    ds_array.resize(n+1);
    for (int u=1; u<=n; u++) {
        vector<pair<long long, long long>> events;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int d_val = edge.second;
            long long R = (long long) d_val * max_d_arr[v];
            events.push_back({d_val, R});
        }
        sort(events.begin(), events.end());
        NodeDS ds;
        long long current_max = -1;
        for (int i=0; i<events.size(); i++) {
            ds.sorted_d.push_back(events[i].first);
            if (i==0) {
                current_max = events[i].second;
            } else {
                if (events[i].second > current_max) {
                    current_max = events[i].second;
                }
            }
            ds.prefix_max.push_back(current_max);
        }
        ds_array[u] = ds;
    }

    dp.resize(n+1, vector<long long>(K_MAX+1, INF));
    for (int u=1; u<=n; u++) {
        dp[u][1] = 1;
    }

    for (int u=1; u<=n; u++) {
        long long min_val = INF;
        for (auto edge : adj[u]) {
            int d = edge.second;
            if (d < min_val) min_val = d;
        }
        dp[u][2] = min_val;
    }

    for (int k=3; k<=K_MAX; k++) {
        for (int u=1; u<=n; u++) {
            long long min_val = INF;
            for (auto edge : adj[u]) {
                int v = edge.first;
                int d = edge.second;
                if (dp[v][k-1] >= INF) 
                    continue;
                if (dp[v][k-1] > 0 && d > INF / dp[v][k-1]) {
                    continue;
                }
                long long candidate = (long long) d * dp[v][k-1];
                if (candidate < min_val) {
                    min_val = candidate;
                }
            }
            dp[u][k] = min_val;
        }
    }

    for (int i=0; i<Q; i++) {
        int p;
        long long x;
        cin >> p >> x;

        if (x < max_d_arr[p]) {
            cout << 1 << '\n';
        } else {
            NodeDS& ds = ds_array[p];
            int idx = -1;
            if (!ds.sorted_d.empty()) {
                auto it = upper_bound(ds.sorted_d.begin(), ds.sorted_d.end(), x);
                idx = it - ds.sorted_d.begin() - 1;
            }
            bool found_k2 = false;
            if (idx >= 0) {
                if (ds.prefix_max[idx] > x) {
                    found_k2 = true;
                }
            }

            if (found_k2) {
                cout << 2 << '\n';
            } else {
                int ans = -1;
                for (int k=3; k<=K_MAX; k++) {
                    if (x >= dp[p][k]) {
                        ans = k;
                        break;
                    }
                }
                if (ans == -1) {
                    ans = K_MAX;
                }
                cout << ans << '\n';
            }
        }
    }

    return 0;
}