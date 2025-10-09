#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    char c;
};

vector<TreeNode> tree;
vector<vector<int>> adj;

void buildNext(string pattern, vector<int>& next) {
    int m = pattern.size();
    next.resize(m + 1);
    if (m == 0) return;
    next[0] = -1;
    if (m == 1) {
        next[1] = 0;
        return;
    }
    next[1] = 0;
    int i = 2, j = 0;
    while (i <= m) {
        if (j == -1 || pattern[i - 1] == pattern[j]) {
            next[i] = j + 1;
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
}

void dfs(int u, int current_match, string& pattern, vector<int>& next, vector<bool>& visited, int& count, int depth) {
    int m = pattern.size();
    int new_match = current_match;
    char c = tree[u].c;

    while (new_match != -1) {
        if (new_match == m) {
            new_match = next[new_match];
            continue;
        }
        if (pattern[new_match] == c) {
            break;
        } else {
            new_match = next[new_match];
        }
    }

    if (new_match == -1) {
        if (m > 0 && pattern[0] == c) {
            new_match = 1;
        } else {
            new_match = 0;
        }
    } else {
        new_match++;
    }

    if (new_match == m && depth == m) {
        count++;
    }

    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        dfs(v, new_match, pattern, next, visited, count, depth + 1);
        visited[v] = false;
    }
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> tree[i].c;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string pattern;
    cin >> pattern;
    int m = pattern.size();

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> next;
    buildNext(pattern, next);

    int total_count = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        int init_match = 0;
        if (m > 0 && tree[i].c == pattern[0]) {
            init_match = 1;
        }
        dfs(i, init_match, pattern, next, visited, total_count, 1);
    }

    cout << total_count << endl;
    return 0;
}