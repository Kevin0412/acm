#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rank_;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) {
        return false;
    }
    if (rank_[rx] < rank_[ry]) {
        parent[rx] = ry;
    } else if (rank_[rx] > rank_[ry]) {
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
        rank_[rx]++;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edges;
    int max_node = 2 * n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back(make_tuple(a, b, i + 1));
    }

    sort(edges.begin(), edges.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        if (get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    });

    parent.resize(max_node + 1);
    rank_.resize(max_node + 1, 0);
    for (int i = 1; i <= max_node; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    vector<bool> cover(max_node + 1, false);
    vector<int> selected;

    for (auto &edge : edges) {
        int a = get<0>(edge);
        int b = get<1>(edge);
        int idx = get<2>(edge);
        int ra = find(a);
        int rb = find(b);
        if (ra != rb) {
            int gain = 0;
            for (int x = a; x < b; x++) {
                if (!cover[x]) {
                    gain++;
                }
            }
            if (gain > 0) {
                for (int x = a; x < b; x++) {
                    cover[x] = true;
                }
                selected.push_back(idx);
                merge(a, b);
            }
        }
    }

    cout << selected.size() << endl;
    if (!selected.empty()) {
        sort(selected.begin(), selected.end());
        for (int i = 0; i < selected.size(); i++) {
            cout << selected[i];
            if (i < selected.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
		solve();
	}
	return 0;
}