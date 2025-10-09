#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int main() {
    int n, K;
    cin >> n >> K;

    // 生成所有合法状态及其国王数量
    vector<int> state_list;
    vector<int> cnt_list;
    for (int s = 0; s < (1 << n); ++s) {
        if ((s & (s << 1)) == 0) { // 检查相邻是否有冲突
            int cnt = __builtin_popcount(s);
            state_list.push_back(s);
            cnt_list.push_back(cnt);
        }
    }
    int state_count = state_list.size();

    // 预处理状态转移
    vector<vector<int>> transition(state_count);
    for (int pre_idx = 0; pre_idx < state_count; ++pre_idx) {
        int pre_s = state_list[pre_idx];
        for (int cur_idx = 0; cur_idx < state_count; ++cur_idx) {
            int cur_s = state_list[cur_idx];
            if ((pre_s & cur_s) == 0 && ((pre_s << 1) & cur_s) == 0 && ((pre_s >> 1) & cur_s) == 0) {
                transition[pre_idx].push_back(cur_idx);
            }
        }
    }

    // 初始化动态规划数组
    vector<vector<ll>> dp_prev(K + 1, vector<ll>(state_count, 0));
    dp_prev[0][0] = 1; // 初始状态：0个国王，状态为state_list[0]（即0）

    for (int row = 0; row < n; ++row) {
        vector<vector<ll>> dp_curr(K + 1, vector<ll>(state_count, 0));
        for (int k_prev = 0; k_prev <= K; ++k_prev) {
            for (int pre_idx = 0; pre_idx < state_count; ++pre_idx) {
                if (dp_prev[k_prev][pre_idx] == 0) continue;
                for (int cur_idx : transition[pre_idx]) {
                    int cnt = cnt_list[cur_idx];
                    int new_k = k_prev + cnt;
                    if (new_k > K) continue;
                    dp_curr[new_k][cur_idx] += dp_prev[k_prev][pre_idx];
                }
            }
        }
        dp_prev.swap(dp_curr); // 滚动数组，准备处理下一行
    }

    // 统计所有符合条件的状态
    ll result = 0;
    for (int s = 0; s < state_count; ++s) {
        result += dp_prev[K][s];
    }
    cout << result << endl;

    return 0;
}