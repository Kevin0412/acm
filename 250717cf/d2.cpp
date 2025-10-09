#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <cmath>
using namespace std;

const long long inf = 1e18;

class SegmentTree {
public:
    int size;
    vector<long long> tree;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, inf);
    }

    void update(int idx, long long val) {
        idx += size;
        if (tree[idx] > val) {
            tree[idx] = val;
            for (idx /= 2; idx >= 1; idx /= 2) {
                tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
            }
        }
    }

    long long query(int l, int r) {
        if (l > r) 
            return inf;
        l += size;
        r += size;
        long long res = inf;
        while (l <= r) {
            if (l % 2 == 1) {
                res = min(res, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                res = min(res, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<tuple<int, int, int>> casinos;
        vector<long long> all_vals;

        for (int i = 0; i < n; i++) {
            int l, r, real_val;
            cin >> l >> r >> real_val;
            casinos.emplace_back(l, r, real_val);
            all_vals.push_back(l);
            all_vals.push_back(r);
            all_vals.push_back(real_val);
        }

        long long ans = k;
        if (n == 0) {
            cout << ans << '\n';
            continue;
        }

        sort(all_vals.begin(), all_vals.end());
        auto last = unique(all_vals.begin(), all_vals.end());
        all_vals.erase(last, all_vals.end());
        int m = all_vals.size();

        SegmentTree seg_tree(m);

        sort(casinos.begin(), casinos.end(), [](const auto& a, const auto& b) {
            return get<2>(a) < get<2>(b);
        });

        auto get_index = [&](int val) {
            return lower_bound(all_vals.begin(), all_vals.end(), val) - all_vals.begin();
        };

        for (int i = 0; i < n; i++) {
            int l = get<0>(casinos[i]);
            int r = get<1>(casinos[i]);
            int real_val = get<2>(casinos[i]);

            int left_idx = get_index(l);
            int right_idx = upper_bound(all_vals.begin(), all_vals.end(), r) - all_vals.begin() - 1;

            long long dp_val;
            if (left_idx > right_idx) {
                dp_val = l;
            } else {
                long long min_query = seg_tree.query(left_idx, right_idx);
                dp_val = min((long long)l, min_query);
            }

            if (dp_val <= k) {
                ans = max(ans, (long long)real_val);
            }

            int pos = get_index(real_val);
            seg_tree.update(pos, dp_val);
        }

        cout << ans << '\n';
    }
    return 0;
}