#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> L(n+1, 0);
        vector<int> R(n+1, n);
        for (int i = 0; i < m; i++) {
            int v, x, p;
            cin >> v >> x >> p;
            if (p == 0) {
                if (x < R[v]) R[v] = x;
            } else {
                if (x > L[v]) L[v] = x;
            }
        }

        bool valid = true;
        vector<int> nodes;
        for (int v = 2; v <= n; v++) {
            if (L[v] > R[v]) {
                valid = false;
            }
            nodes.push_back(v);
        }

        if (!valid) {
            cout << "Ugly\n";
            continue;
        }

        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            if (R[a] != R[b]) {
                return R[a] < R[b];
            }
            return L[a] < L[b];
        });

        set<int> layers;
        layers.insert(0);
        vector<vector<int>> q_per_layer(n+1);
        q_per_layer[0] = {1};
        vector<int> parent(n+1, 0);
        bool valid_flag = true;

        for (int v : nodes) {
            int L0 = max(0, L[v] - 1);
            int R0 = R[v] - 1;

            auto it = layers.upper_bound(R0);
            if (it == layers.begin()) {
                valid_flag = false;
                break;
            }
            it--;
            if (*it < L0) {
                valid_flag = false;
                break;
            }
            int j = *it;
            int d = j + 1;
            int u = q_per_layer[j][0];
            parent[v] = u;
            q_per_layer[d].push_back(v);
            if (q_per_layer[d].size() == 1) {
                layers.insert(d);
            }
        }

        if (!valid_flag) {
            cout << "Ugly\n";
        } else {
            cout << "Beautiful\n";
            for (int v = 2; v <= n; v++) {
                cout << parent[v] << " " << v << "\n";
            }
        }
    }

    return 0;
}