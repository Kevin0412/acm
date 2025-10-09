#include<bits/stdc++.h>
using namespace std;

struct Trie {
    int nex[3200001][2], cnt;
    bool isEnd[3200001]; // 标记叶子节点（可选）

    void insert(int s) {
        int p = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (s >> i) & 1;
            if (!nex[p][bit]) {
                nex[p][bit] = ++cnt;
                nex[cnt][0] = nex[cnt][1] = 0; // 初始化新节点
            }
            p = nex[p][bit];
        }
    }

    void clear() {
        for (int j = 0; j < 2; j++) nex[0][j] = 0;
        cnt = 0;
    }

    int query(int x) {
        int p = 0, res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            // 优先选择相反位（使异或结果为1）
            if (nex[p][bit ^ 1]) {
                res |= (1 << i);   // 当前位异或结果为1
                p = nex[p][bit ^ 1];
            } else {
                p = nex[p][bit];   // 只能选相同位（异或结果为0）
            }
        }
        return res;
    }
};

Trie a;

int main() {
    a.clear();
    int n, s;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a.insert(s);
        nums.push_back(s);
    }
    
    int ans = 0;
    for (int x : nums) {
        ans = max(ans, a.query(x)); // 查询每个数的最大异或值
    }
    cout << ans << endl;
    return 0;
}