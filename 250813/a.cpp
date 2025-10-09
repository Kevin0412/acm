#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 505;
const int MAXM = 505;
const int MAXE = 50005;

vector<int> graph[MAXN];
int match[MAXM];
bool vis[MAXM];

bool dfs(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int count = 0;
    memset(match, 0, sizeof(match));

    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}