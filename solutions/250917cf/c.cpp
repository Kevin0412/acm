#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        edges.push_back({u, v});
        if (x > y) {
            graph[u].push_back({v, x});
            indegree[v]++;
        } else {
            graph[v].push_back({u, y});
            indegree[u]++;
        }
    }

    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (auto& [neighbor, weight] : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    vector<int> values(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        values[order[i]] = n - i;
    }

    for (int i = 1; i <= n; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}