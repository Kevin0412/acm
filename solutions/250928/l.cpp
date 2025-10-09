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
        tree[node] = tree[left_node] + tree[right_node];
    }

    // 下推懒惰标记
    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            // 更新当前节点值
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;

            // 更新左右子节点的值和懒惰标记
            tree[left_node] += lazy[node] * (mid - start + 1);
            tree[right_node] += lazy[node] * (end - mid);
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
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
            return;
        }
        
        push_down(node, start, end);  // 下推懒惰标记
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        if (l <= mid) update_range(left_node, start, mid, l, r, val);
        if (r > mid) update_range(right_node, mid + 1, end, l, r, val);
        
        tree[node] = tree[left_node] + tree[right_node];
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
        return left_sum + right_sum;
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

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m),l(k),c(n+1);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<m;i++){
    	cin>>b[i];
    }
    for(int i=0;i<k;i++){
    	cin>>l[i];
    }
    int k1=0;
    for(int i=0;i<n;i++){
    	if(k1>=b.size())break;
    	if(b[k1]==a[i]){
    		k1++;
    	}
    }
    if(k1<b.size()){
    	cout<<"NO\n";
    	return;
    }
    for(int i=0;i<n;i++){
    	c[a[i]]=i;
    }
    sort(b.begin(), b.end(), greater<int>());
    set<int> d;
    d.insert(-1);
    d.insert(n);
    vector<int> l1,e(n+2,1);
    e[0]=0;
    e[n+1]=0;
    SegmentTree st(e);
    k1=0;
    for(int i=n;i>0;i--){
    	if(k1>=b.size()){
    		auto it = d.lower_bound(c[i]);
    		it--;
    		int lower=*it;
    		auto it1 = d.upper_bound(c[i]);
    		int upper=*it1;
    		//cerr<<i<<" "<<c[i]<<" "<<lower<<" "<<upper<<"\n";
    		l1.push_back(st.query(lower+1,upper+1));
    	}
    	else if(i==b[k1]){
    		d.insert(c[i]);
    		k1++;
    	}else{
    		auto it = d.lower_bound(c[i]);
    		it--;
    		int lower=*it;
    		auto it1 = d.upper_bound(c[i]);
    		int upper=*it1;
    		//cerr<<i<<" "<<c[i]<<" "<<lower<<" "<<upper<<"\n";
    		l1.push_back(st.query(lower+1,upper+1));
    	}
    	st.update(c[i]+1,c[i]+1,-1);
    }
    sort(l1.begin(),l1.end(), greater<int>());
    sort(l.begin(),l.end(), greater<int>());
    //for(auto i:l1){
    	//cerr<<i<<" ";
    //}
    //cerr<<"\n";
    k1=0;
    for(auto i:l){
    	if(k1>=l1.size()){
			cout<<"YES\n";
		    return;
		}
    	if(l1[k1]>=i){
    		k1++;
    	}
    }
    //cerr<<"\n";
    if(k1>=l1.size())cout<<"YES\n";
    else cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		//cerr<<t<<":\n";
		solve();
	}
	return 0;
}
