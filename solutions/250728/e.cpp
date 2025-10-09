#include <bits/stdc++.h>
using namespace std;

// 线段树节点结构，用于维护可持久化并查集
struct SegmentTree {
  int lc, rc;   // 左右子节点索引
  int val;      // 存储并查集中节点的父节点
  int rnk;      // 存储并查集中节点的秩（树高度）
};

constexpr int MAXN = 100000 + 5;   // 最大元素数量
constexpr int MAXM = 200000 + 5;   // 最大操作数量

SegmentTree t[MAXN * 2 + MAXM * 40]; // 线段树节点池（可持久化需要大量节点）
int rt[MAXM]; // 存储每个操作后的线段树根节点索引（版本控制）
int n, m, tot; // tot: 线段树节点计数器

// 构建初始线段树
int build(int l, int r) {
  int p = ++tot; // 创建新节点
  if (l == r) {  // 叶子节点：初始父节点为自身，秩为1
    t[p].val = l;
    t[p].rnk = 1;
    return p;
  }
  int mid = (l + r) / 2;
  t[p].lc = build(l, mid);    // 递归构建左子树
  t[p].rc = build(mid + 1, r); // 递归构建右子树
  return p;
}

// 查询节点秩（树高度）
int getRnk(int p, int l, int r, int pos) {
  if (l == r) {
    return t[p].rnk;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    return getRnk(t[p].lc, l, mid, pos);
  } else {
    return getRnk(t[p].rc, mid + 1, r, pos);
  }
}

// 修改节点秩（可持久化）
int modifyRnk(int now, int l, int r, int pos, int val) {
  int p = ++tot;     // 新建节点
  t[p] = t[now];     // 复制原节点信息
  if (l == r) {
    t[p].rnk = max(t[p].rnk, val); // 更新秩（取最大值保证正确性）
    return p;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    t[p].lc = modifyRnk(t[now].lc, l, mid, pos, val); // 递归修改左子树
  } else {
    t[p].rc = modifyRnk(t[now].rc, mid + 1, r, pos, val); // 递归修改右子树
  }
  return p;
}

// 查询节点父节点
int query(int p, int l, int r, int pos) {
  if (l == r) {
    return t[p].val;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    return query(t[p].lc, l, mid, pos);
  } else {
    return query(t[p].rc, mid + 1, r, pos);
  }
}

// 查找节点的根节点（无路径压缩）
int findRoot(int p, int pos) {
  int f = query(p, 1, n, pos); // 查询当前父节点
  if (pos == f) { // 找到根节点
    return pos;
  }
  return findRoot(p, f); // 递归向上查找
}

// 修改节点父节点（可持久化）
int modify(int now, int l, int r, int pos, int fa) {
  int p = ++tot;     // 新建节点
  t[p] = t[now];     // 复制原节点
  if (l == r) {
    t[p].val = fa;   // 更新父节点
    return p;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    t[p].lc = modify(t[now].lc, l, mid, pos, fa); // 递归修改左子树
  } else {
    t[p].rc = modify(t[now].rc, mid + 1, r, pos, fa); // 递归修改右子树
  }
  return p;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  rt[0] = build(1, n); // 初始化版本0：每个元素独立成树

  for (int i = 1; i <= m; i++) {
    int op, a, b;
    cin >> op;

    if (op == 1) { // 合并操作
      cin >> a >> b;
      int fa = findRoot(rt[i - 1], a); // 查找a的根
      int fb = findRoot(rt[i - 1], b); // 查找b的根
      
      if (fa != fb) {
        // 按秩合并：保持fa是秩较小的树
        if (getRnk(rt[i - 1], 1, n, fa) > getRnk(rt[i - 1], 1, n, fb)) {
          swap(fa, fb);
        }
        // 第一步：将fa的父节点设为fb
        int tmp = modify(rt[i - 1], 1, n, fa, fb);
        // 第二步：更新fb的秩（若两树高度相同则+1）
        rt[i] = modifyRnk(tmp, 1, n, fb, getRnk(rt[i - 1], 1, n, fa) + 1);
      } else {
        // 已在同一集合，版本不变
        rt[i] = rt[i - 1];
      }
    } else if (op == 2) { // 版本回退
      cin >> a;
      rt[i] = rt[a]; // 直接使用历史版本
    } else { // 查询连通性
      cin >> a >> b;
      rt[i] = rt[i - 1]; // 不修改版本
      // 输出是否连通（1/0）
      cout << (findRoot(rt[i], a) == findRoot(rt[i], b)) << '\n';
    }
  }
  return 0;
}