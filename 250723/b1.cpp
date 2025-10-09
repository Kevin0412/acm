#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n, mod;
    vector<long long> tree;
    vector<long long> add;
    vector<long long> mul;
    
    void push_down(int node, int start, int end) {
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int left_len = mid - start + 1;
        int right_len = end - mid;
        
        // 更新左子树
        if (left_node < tree.size()) {
            // 先应用乘法标记，再应用加法标记
            tree[left_node] = (tree[left_node] * mul[node] % mod + add[node] * left_len % mod) % mod;
            // 更新左子树的懒惰标记
            mul[left_node] = (mul[left_node] * mul[node]) % mod;
            add[left_node] = (add[left_node] * mul[node] % mod + add[node]) % mod;
        }
        
        // 更新右子树
        if (right_node < tree.size()) {
            tree[right_node] = (tree[right_node] * mul[node] % mod + add[node] * right_len % mod) % mod;
            mul[right_node] = (mul[right_node] * mul[node]) % mod;
            add[right_node] = (add[right_node] * mul[node] % mod + add[node]) % mod;
        }
        
        // 重置当前节点标记
        mul[node] = 1;
        add[node] = 0;
    }
    
    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start] % mod;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        build(arr, left_node, start, mid);
        build(arr, right_node, mid + 1, end);
        tree[node] = (tree[left_node] + tree[right_node]) % mod;
    }
    
    void update_mul(int node, int start, int end, int l, int r, long long k) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            // 更新当前节点值和标记
            tree[node] = (tree[node] * k) % mod;
            mul[node] = (mul[node] * k) % mod;
            add[node] = (add[node] * k) % mod;
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        update_mul(left_node, start, mid, l, r, k);
        update_mul(right_node, mid + 1, end, l, r, k);
        tree[node] = (tree[left_node] + tree[right_node]) % mod;
    }
    
    void update_add(int node, int start, int end, int l, int r, long long k) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            // 更新当前节点值和标记
            int len = end - start + 1;
            tree[node] = (tree[node] + k * len) % mod;
            add[node] = (add[node] + k) % mod;
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        update_add(left_node, start, mid, l, r, k);
        update_add(right_node, mid + 1, end, l, r, k);
        tree[node] = (tree[left_node] + tree[right_node]) % mod;
    }
    
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        long long left_sum = query(left_node, start, mid, l, r);
        long long right_sum = query(right_node, mid + 1, end, l, r);
        return (left_sum + right_sum) % mod;
    }

public:
    SegmentTree(const vector<long long>& arr, int mod) {
        this->mod = mod;
        n = arr.size();
        tree.resize(4 * n, 0);
        add.resize(4 * n, 0);
        mul.resize(4 * n, 1);
        build(arr, 0, 0, n - 1);
    }
    
    void multiply(int l, int r, long long k) {
        update_mul(0, 0, n - 1, l, r, k);
    }
    
    void addVal(int l, int r, long long k) {
        update_add(0, 0, n - 1, l, r, k);
    }
    
    long long sum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    int n, q, mod;
    scanf("%d %d %d", &n, &q, &mod);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    
    SegmentTree st(arr, mod);
    
    while (q--) {
        int op, x, y;
        long long k;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %lld", &x, &y, &k);
            st.multiply(x - 1, y - 1, k % mod);
        } else if (op == 2) {
            scanf("%d %d %lld", &x, &y, &k);
            st.addVal(x - 1, y - 1, k % mod);
        } else {
            scanf("%d %d", &x, &y);
            printf("%lld\n", st.sum(x - 1, y - 1));
        }
    }
    return 0;
}