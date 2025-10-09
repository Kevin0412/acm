#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100000;
const int MAXA = 100000;
int INF;

template<int N>
struct SegmentTree {
    struct Node {
        int l, r;
        ll mx, mn, tag;
    } tr[N * 4 + 5];

    ll a[N + 5];

    void pushup(int u) {
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
    }

    void build(int u, int l, int r) {
        tr[u].l = l; tr[u].r = r; tr[u].tag = 0;
        if (l == r) {
            tr[u].mx = tr[u].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void apply_tag(int u, ll v) {
        tr[u].tag += v;
        tr[u].mx += v;
        tr[u].mn += v;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            apply_tag(u << 1, tr[u].tag);
            apply_tag(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    // 点设为 v
    void point_update(int u, int pos, ll v) {
        if (tr[u].l == tr[u].r) {
            tr[u].mx = tr[u].mn = v;
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (pos <= mid) point_update(u << 1, pos, v);
        else            point_update(u << 1 | 1, pos, v);
        pushup(u);
    }

    // 取区间最大
    ll range_max(int u, int L, int R) {
        if (L <= tr[u].l && tr[u].r <= R)
            return tr[u].mx;
        pushdown(u);
        ll res = LLONG_MIN;
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (L <= mid) res = max(res, range_max(u << 1, L, R));
        if (R > mid) res = max(res, range_max(u << 1 | 1, L, R));
        return res;
    }

    // 取区间最小
    ll range_min(int u, int L, int R) {
        if (L <= tr[u].l && tr[u].r <= R)
            return tr[u].mn;
        pushdown(u);
        ll res = LLONG_MAX;
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (L <= mid) res = min(res, range_min(u << 1, L, R));
        if (R > mid) res = min(res, range_min(u << 1 | 1, L, R));
        return res;
    }
};
SegmentTree<MAXN> t1, t2;
void solve() {
    
    int n, q;
    cin >> n >> q;
    INF = n + 1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t1.a[i] = a[i];
        t2.a[i] = INF;
    }

    unordered_map<int, int> last;
    for (int i = n; i >= 1; i--) {
        if (last.count(a[i])) {
            t2.a[i] = last[a[i]];
        }
        last[a[i]] = i;
    }
    t1.build(1, 1, n);
    t2.build(1, 1, n);
    static set<int> pos[MAXA + 5];
    for (int i = 1; i <= n; i++) {
        pos[a[i]].insert(i);
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int old = a[x];
            if (old == y) continue;
            {
                auto& S = pos[old];
                auto it = S.find(x);
                int pre = -1, nxt = -1;
                if (it != S.begin()) pre = *prev(it);
                if (next(it) != S.end()) nxt = *next(it);
                S.erase(it);
                if (pre != -1) {
                    int np = (nxt == -1 ? INF : nxt);
                    t2.point_update(1, pre, np);
                }
            }
            {
                auto& S = pos[y];
                S.insert(x);
                auto it = S.find(x);
                int pre = -1, nxt = -1;
                if (it != S.begin()) pre = *prev(it);
                if (next(it) != S.end()) nxt = *next(it);

                if (pre != -1) {
                    t2.point_update(1, pre, x);
                }
                int np = (nxt == -1 ? INF : nxt);
                t2.point_update(1, x, np);
            }

            a[x] = y;
            t1.point_update(1, x, y);
        }
        else {
            int l = x, r = y;
            ll mn = t1.range_min(1, l, r);
            ll mx = t1.range_max(1, l, r);
            ll nxtMin = t2.range_min(1, l, r);

            if (mx - mn == r - l && nxtMin > r) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}