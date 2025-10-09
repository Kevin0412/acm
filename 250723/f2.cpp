#include <vector>
#include <iostream>
using namespace std;

// 树状数组（单点更新，前缀查询）
class FenwickTree {
    vector<long long> tree;
    int n;
public:
    FenwickTree(int size) : n(size), tree(size+1, 0) {}

    void update(int index, long long delta) {
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    long long query(int index) {
        if (index < 1) 
            return 0;
        long long sum = 0;
        while (index) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

// 支持区间更新和区间查询的树状数组
class FenwickTreeRange {
    FenwickTree tree1, tree2;
    int n;
public:
    FenwickTreeRange(int size) : n(size), tree1(size), tree2(size) {}

    void update_range(int l, int r, long long val) {
        tree1.update(l, val);
        if (r+1 <= n) {
            tree1.update(r+1, -val);
        }
        tree2.update(l, val * (l-1));
        if (r+1 <= n) {
            tree2.update(r+1, -val * r);
        }
    }

    long long query_prefix(int i) {
        return tree1.query(i) * i - tree2.query(i);
    }

    long long query_range(int l, int r) {
        if (l > r) 
            return 0;
        return query_prefix(r) - query_prefix(l-1);
    }
};

int main() {
    int m, n, q, x, y, i;
    cin >> n >> m;
    vector<long long> arr(n);
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    FenwickTreeRange st(n);

    for (i = 0; i < n; i++) {
        st.update_range(i+1, i+1, arr[i]);
    }

    for (i = 0; i < m; i++) {
        cin >> q >> x;
        if (q == 1) {
            long long k;
            cin >> k;
            st.update_range(x, x, k);
        } else {
            cin >> y;
            cout << st.query_range(x, y) << endl;
        }
    }

    return 0;
}