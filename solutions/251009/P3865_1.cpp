#include<bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree {
private:
    int n;  // 原始数组的大小
    vector<long long> tree;  // 线段树数组（存储区间和）
    vector<long long> lazy;  // 懒惰标记数组（存储区间待加的值）

    // 构建线段树
    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build(arr, left_node, start, mid);
        build(arr, right_node, mid + 1, end);
        tree[node] = max(tree[left_node], tree[right_node]);
    }

    // 下推懒惰标记
    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            // 更新当前节点值
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;

            // 更新左右子节点的值和懒惰标记
            tree[left_node] += lazy[node];
            tree[right_node] += lazy[node];
            lazy[left_node] += lazy[node];
            lazy[right_node] += lazy[node];
            
            // 清除当前节点的懒惰标记
            lazy[node] = 0;
        }
    }

    // 区间更新：在区间 [l, r] 上加上值 val
    void update_range(int node, int start, int end, int l, int r, long long val) {
        // 当前区间完全包含在更新区间内
        if (l <= start && end <= r) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        
        push_down(node, start, end);  // 下推懒惰标记
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        if (l <= mid) update_range(left_node, start, mid, l, r, val);
        if (r > mid) update_range(right_node, mid + 1, end, l, r, val);
        
        tree[node] = max(tree[left_node], tree[right_node]);
    }

    // 区间查询：求区间 [l, r] 的和
    long long query_range(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;  // 区间无交集
        if (l <= start && end <= r) return tree[node];  // 当前区间完全包含在查询区间内
        
        push_down(node, start, end);  // 下推懒惰标记
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        long long left_sum = query_range(left_node, start, mid, l, r);
        long long right_sum = query_range(right_node, mid + 1, end, l, r);
        return max(left_sum, right_sum);
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);  // 分配4倍空间
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    // 区间更新接口：给区间 [l, r] 的每个元素加上 val
    void update(int l, int r, long long val) {
        update_range(0, 0, n - 1, l, r, val);
    }

    // 区间查询接口：返回区间 [l, r] 的元素和
    long long query(int l, int r) {
        return query_range(0, 0, n - 1, l, r);
    }
};

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n,m;
	n=read();
	m=read();
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	SegmentTree st(arr);
	vector<int> ans;
	for(int i=0;i<m;i++){
		int l,r;
		l=read();
		r=read();
		ans.push_back(st.query(l-1,r-1));
	}
	for(auto i:ans){
		cout<<i<<"\n";
	}
	return 0;
}