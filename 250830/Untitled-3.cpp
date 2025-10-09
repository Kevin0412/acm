#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

void solve() {
    int n, m, q;
    read(n), read(m), read(q);
    
    vector<int> score(m + 1, 0);  // 1-based
    int current_level = -1;
    vector<int> player_state(m + 1, 0);
    vector<int> finish_order;
    
    for (int i = 0; i < q; ++i) {
        int type;
        read(type);
        if (type == 1) {
            // 处理上一个 level 的分数
            if (current_level != -1 && !finish_order.empty()) {
                int k = m;
                for (int id : finish_order) {
                    score[id] += k--;
                }
            }
            int x;
            read(x);
            current_level = x;
            finish_order.clear();
            fill(player_state.begin(), player_state.end(), 0);
        } else if (type == 2 || type == 3) {
            int id, x;
            read(id), read(x);
            if (x != current_level || player_state[id] != 0) continue;
            if (type == 2) {
                player_state[id] = 1;
                finish_order.push_back(id);
            } else {
                player_state[id] = 2;
            }
        }
    }
    
    // 处理最后一个 level
    if (current_level != -1 && !finish_order.empty()) {
        int k = m;
        for (int id : finish_order) {
            score[id] += k--;
        }
    }
    
    vector<pair<int, int>> res;
    for (int i = 1; i <= m; ++i) {
        res.emplace_back(-score[i], i);
    }
    sort(res.begin(), res.end());
    
    for (auto [neg_score, id] : res) {
        printf("%d %d\n", id, -neg_score);
    }
}

int main() {
    int t;
    read(t);
    while (t--) solve();
    return 0;
}