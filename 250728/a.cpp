#include <bits/stdc++.h>
using namespace std;

const int MAX_NODE = 40000000;  // 节点池大小
const int MAXM = 1000000 + 5;   // 最大操作数

struct Node {
    int lc, rc;      // 左右子节点索引
    long long val;   // 存储的值
};

Node tree[MAX_NODE];
int rt[MAXM];        // 每个版本的根节点索引
int tot;             // 节点计数器

// 构建线段树
int build(int l, int r, const vector<long long>& arr) {
    int p = ++tot;
    if (l == r) {
        tree[p].val = arr[l];
        return p;
    }
    int mid = (l + r) >> 1;
    tree[p].lc = build(l, mid, arr);
    tree[p].rc = build(mid + 1, r, arr);
    return p;
}

// 更新操作：修改位置pos的值为val
int update(int now, int l, int r, int pos, long long val) {
    int p = ++tot;
    tree[p] = tree[now];  // 复制原节点
    if (l == r) {
        tree[p].val = val;
        return p;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        tree[p].lc = update(tree[now].lc, l, mid, pos, val);
    } else {
        tree[p].rc = update(tree[now].rc, mid + 1, r, pos, val);
    }
    return p;
}

// 查询操作：获取位置pos的值
long long query(int now, int l, int r, int pos) {
    if (l == r) {
        return tree[now].val;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        return query(tree[now].lc, l, mid, pos);
    } else {
        return query(tree[now].rc, mid + 1, r, pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    tot = 0;
    rt[0] = build(1, n, arr);  // 构建初始版本

    for (int i = 1; i <= m; i++) {
        int op, v, p;
        long long c;
        cin >> v >> op;
        if (op == 1) {
            cin >> p >> c;
            rt[i] = update(rt[v], 1, n, p, c);
        } else {
            cin >> p;
            long long ans = query(rt[v], 1, n, p);
            cout << ans << '\n';
            rt[i] = rt[v];  // 新版本是访问版本的复制
        }
    }
    return 0;
}