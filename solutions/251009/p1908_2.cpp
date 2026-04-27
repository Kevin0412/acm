#include<bits/stdc++.h>
#define int long long
using namespace std;

template<typename T>
class FenwickTree {
public:
    vector<T> tree;
    int n;

    // 构造函数，初始化大小为n+1（树状数组下标从1开始）
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}
    
    // 在位置pos增加value
    void update(int pos, T value) {
        for (; pos <= n; pos += pos & -pos) {
            tree[pos] += value;
        }
    }
    
    // 查询前缀和[1, pos]
    T query(int pos) {
        T sum = 0;
        for (; pos > 0; pos -= pos & -pos) {
            sum += tree[pos];
        }
        return sum;
    }
    
    // 查询区间和[l, r]
    T rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
    
    // 获取原始数组（仅供调试使用）
    vector<T> getOriginalArray() {
        vector<T> arr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            arr[i] = rangeQuery(i, i);
        }
        return arr;
    }
};


struct node{
	int n;
	int idx;
	bool operator<(const node& other) const {
		if(n==other.n) return idx > other.idx;
		else return n > other.n;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<node> arr(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>arr[i].n;
        arr[i].idx=i+1;
    }
    
    sort(arr.begin(),arr.end());
    
    FenwickTree<int> fenwick(n);
    
    // 构建树状数组
    for (int i = 0; i < n; i++) {
        fenwick.update(i + 1, 0);  // 注意：树状数组下标从1开始
    }
    
    int cnt=0;
    for(auto a:arr){
    	cnt+=fenwick.query(a.idx);
    	fenwick.update(a.idx,1);
    }
    cout<<cnt<<"\n";
    return 0;
}