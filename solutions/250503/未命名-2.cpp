#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 20; 

struct Tree {
    vector<vector<int>> adj;  // 邻接表存储子节点
    vector<int> parent;
    vector<vector<int>> up;
    vector<int> depth;
    
    void init(int n, const vector<int>& pa) {
        adj.resize(n + 1);
        parent.resize(n + 1);
        up.resize(n + 1, vector<int>(LOG, -1));
        depth.resize(n + 1, 0);

        // 构建邻接表
        for (int v = 2; v <= n; ++v) {
            int p = pa[v-2]; // 节点v的父节点
            adj[p].push_back(v);
            parent[v] = p;
        }
        parent[1] = -1;

        // BFS预处理提升表
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        up[1][0] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) { // 直接访问子节点
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                for (int k = 1; k < LOG; ++k) {
                    if (up[v][k-1] != -1)
                        up[v][k] = up[up[v][k-1]][k-1];
                    else
                        up[v][k] = -1;
                }
                q.push(v);
            }
        }
    }

    int lca(int u, int v) {
        if (u == -1) return v;
        if (v == -1) return u;
        if (depth[u] < depth[v]) swap(u, v);
        
        for (int k = LOG-1; k >= 0; --k) 
            if (depth[u] - (1 << k) >= depth[v]) 
                u = up[u][k];
        
        if (u == v) return u;
        
        for (int k = LOG-1; k >= 0; --k) 
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        
        return up[u][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> keys(K);
    for (int i = 0; i < K; ++i) cin >> keys[i];
    
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    vector<int> pa(N-1);
    for (int i = 0; i < N-1; ++i) cin >> pa[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    vector<int> pb(N-1);
    for (int i = 0; i < N-1; ++i) cin >> pb[i];
    
    Tree treeA, treeB;
    treeA.init(N, pa);
    treeB.init(N, pb);

    // 预处理函数优化为引用传递
    auto preprocess = [](Tree& tree, const vector<int>& keys) {
        int m = keys.size();
        vector<int> pre(m), suf(m);
        pre[0] = keys[0];
        for (int i = 1; i < m; ++i) 
            pre[i] = tree.lca(pre[i-1], keys[i]);
        
        suf[m-1] = keys[m-1];
        for (int i = m-2; i >= 0; --i) 
            suf[i] = tree.lca(suf[i+1], keys[i]);
        
        return make_pair(pre, suf);
    };
    
    auto [preA, sufA] = preprocess(treeA, keys);
    auto [preB, sufB] = preprocess(treeB, keys);
    
    int res = 0;
    for (int i = 0; i < K; ++i) {
        int left = (i > 0) ? preA[i-1] : -1;
        int right = (i < K-1) ? sufA[i+1] : -1;
        int lcaA = treeA.lca(left, right);
        
        left = (i > 0) ? preB[i-1] : -1;
        right = (i < K-1) ? sufB[i+1] : -1;
        int lcaB = treeB.lca(left, right);
        
        if (a[lcaA-1] > b[lcaB-1]) ++res;
    }
    
    cout << res << "\n";
}