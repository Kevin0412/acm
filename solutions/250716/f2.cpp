#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3200001;

struct Trie {
    int nex[MAXN][2], cnt;
    
    void insert(int s) {
        int p = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (s >> i) & 1;
            if (!nex[p][bit]) {
                nex[p][bit] = ++cnt;
                nex[cnt][0] = nex[cnt][1] = 0;
            }
            p = nex[p][bit];
        }
    }

    void clear() {
        for (int j = 0; j < 2; j++) 
            nex[0][j] = 0;
        cnt = 0;
    }
    
    int maxXor() {
        // 优化：从最高位开始逐层处理，避免存储完整路径
        int ans = 0;
        queue<pair<int, int>> q; // (node1, node2)
        q.push({0, 0});
        
        for (int level = 31; level >= 0 && !q.empty(); level--) {
            int size = q.size();
            bool found = false;
            
            while (size--) {
                auto [u, v] = q.front();
                q.pop();
                
                // 尝试所有可能的组合
                for (int b1 : {0, 1}) {
                    for (int b2 : {0, 1}) {
                        int nu = nex[u][b1];
                        int nv = nex[v][b2];
                        
                        if (nu && nv) {
                            found = true;
                            q.push({nu, nv});
                        }
                    }
                }
            }
            
            // 如果当前层有分叉，更新答案
            if (found) {
                ans = (ans << 1) | 1;
            } else {
                ans <<= 1;
                // 没有分叉，重新开始下一层
                queue<pair<int, int>> newQ;
                swap(q, newQ);
                
                while (!newQ.empty()) {
                    auto [u, v] = newQ.front();
                    newQ.pop();
                    
                    // 只能选择相同的分支
                    for (int b : {0, 1}) {
                        int nu = nex[u][b];
                        int nv = nex[v][b];
                        if (nu && nv) {
                            q.push({nu, nv});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

Trie a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    a.clear();
    int n, s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a.insert(s);
    }
    cout << a.maxXor() << endl;
    return 0;
}