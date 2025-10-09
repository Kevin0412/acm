#include<bits/stdc++.h>

using namespace std;


const int BITS = 60;
const unsigned long long MASK = (1LL << BITS) - 1;   // 低60位全1

vector<unsigned long long> vecor(vector<unsigned long long> a, vector<unsigned long long> b){
	////cerr<<a[0]<<" "<<b[0]<<endl;
	vector<unsigned long long> ans;
    for(int i=0;i<a.size();i++){
    	ans.push_back(a[i] | b[i]);
    }
    return ans;
}

class SegmentTree {
private:
    int n;  // 原始数组的大小
    vector<vector<unsigned long long>> tree;  // 线段树数组（存储区间and）

    // 构建线段树
    void build(const vector<vector<unsigned long long>>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build(arr, left_node, start, mid);
        build(arr, right_node, mid + 1, end);
        for(int i=0;i<tree[node].size();i++){
        	tree[node][i] = (tree[left_node][i] & tree[right_node][i]);
        }
    }


    // 区间查询：求区间 [l, r] 的and
    vector<unsigned long long> query_range(int node, int start, int end, int l, int r,int m) {
    	//cerr<<node<<" "<<start<<" "<<end<<endl;
    	if (r < start || end < l){
    		vector<unsigned long long> ans;
    		unsigned long long a;
    		if(m%12!=0){
    			a=(2LL<<((m%12)*5))-1;
    			ans.push_back(a);
    		}
    		for(int i=m%12;i<m;i+=12){
    			ans.push_back(MASK);
    		}
    		return ans;
    	}
        if (l <= start && end <= r) return tree[node];  // 当前区间完全包含在查询区间内
        
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        
        vector<unsigned long long> left_sum = query_range(left_node, start, mid, l, r, m);
        vector<unsigned long long> right_sum = query_range(right_node, mid + 1, end, l, r, m);
        vector<unsigned long long> ans;
        for(int i=0;i<tree[node].size();i++){
        	ans.push_back(left_sum[i] & right_sum[i]);
        }
        return ans;
    }

public:
    SegmentTree(const vector<vector<unsigned long long>>& arr,int m) {
        n = arr.size();
        tree.resize(4 * n, std::vector<unsigned long long>((m+11)/12, 0));  // 分配4倍空间
        build(arr, 0, 0, n - 1);
    }

    // 区间查询接口：返回区间 [l, r] 的元素and
    vector<unsigned long long> query(int l, int r, int m) {
    	////cerr<<l<<" "<<r<<endl;
        return query_range(0, 0, n - 1, l, r, m);
    }
};

vector<unsigned long long> str2vec(string x,int m){
	vector<unsigned long long> ans;
	unsigned long long a;
	int i=0;
	if(m%12!=0){
		a=0;
		for(i=0;i<m%12;i++){
			a=(a<<5);
			if(x[i]>='a'){
				a+=x[i]-'a'+10;
			}else{
				a+=x[i]-'0';
			}
		}
		ans.push_back(a);
	}
	for(i=m%12;i<m;i+=12){
		a=0;
		for(int j=0;j<12;j++){
			a=(a<<5);
			if(x[i+j]>='a'){
				a+=x[i+j]-'a'+10;
			}else{
				a+=x[i+j]-'0';
			}
		}
		ans.push_back(a);
	}
	return ans;
}

int bigger(vector<unsigned long long>a, vector<unsigned long long> b){
	for(int i=0;i<a.size();i++){
    	if(a[i]>b[i]){
    		return 1;
    	}
    	if(a[i]<b[i]){
    		return 0;
    	}
    }
    return 1;
}


// 取第 idx 位（0 = 最低位）
inline int getBit(const vector<unsigned long long>& v, size_t idx) {
    size_t blk = idx / BITS;
    int pos = idx % BITS;
    if (blk >= v.size()) return 0;
    return (v[v.size() - 1 - blk] >> pos) & 1;
}

// 设置第 idx 位
inline void setBit(vector<unsigned long long>& v, size_t idx, int bit) {
    size_t blk = idx / BITS;
    int pos = idx % BITS;
    if (blk >= v.size()) return;
    if (bit) v[v.size() - 1 - blk] |= 1LL << pos;
    else     v[v.size() - 1 - blk] &= ~(1LL << pos);
}

// 把 [0, idx] 全部置 1
inline void fillSuffix(vector<unsigned long long>& v, size_t idx) {
    size_t blk = idx / BITS;
    int pos = idx % BITS;
    if (blk >= v.size()) return;

    v[v.size() - 1 - blk] |= (1LL << (pos + 1)) - 1;
    for (size_t i = blk + 1; i < v.size(); ++i)
        v[v.size() - 1 - i] = MASK;
}

// 主函数：返回从大到小所有状态
vector<vector<unsigned long long>> next_perm_sequence(const vector<unsigned long long>& init) {
    vector<vector<unsigned long long>> seq;
    seq.push_back(init);

    vector<unsigned long long> cur = init;
    size_t totalBits = init.size() * BITS;

    while (true) {
        // 找最右侧的 10 模式
        size_t hi = SIZE_MAX;
        for (size_t i = 0; i + 1 < totalBits; ++i) {
            if (getBit(cur, i + 1) == 1 && getBit(cur, i) == 0) {
                hi = i + 1;      // 高位 1 的索引
            }
        }
        if (hi == SIZE_MAX) break;   // 没有更多

        setBit(cur, hi, 0);          // 1->0
        fillSuffix(cur, hi - 1);     // 低位全1
        seq.emplace_back(cur);
    }
    return seq;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<unsigned long long>> arr;
	string xin;
	cin>>xin;
	vector<unsigned long long> x=str2vec(xin,m);
	for(int i=0;i<n;i++){
		cin>>xin;
		arr.push_back(str2vec(xin,m));
	}
	SegmentTree tree=SegmentTree(arr,m);
	//////cerr<<tree.query(0,n-1,m)[0]<<" "<<x[0]<<endl;
	//cerr<<endl;
	if(bigger(tree.query(0,n-1,m),x)){
		cout<<-1<<"\n";
		return;
	}
	auto xs=next_perm_sequence({x});
	int ans1=1;
	for(auto x:xs){
		//cerr<<x[0]<<":";
		int ans=0;
		int k=0;
		int l=k;
		int r=n-1;
		while(1){
			l=k;
			r=n-1;
			while(1){
				//////cerr<<l<<" "<<r<<endl;
				//cerr<<l<<" "<<(l+r)/2<<" "<<tree.query(k,(l+r)/2,m)[0]<<endl;
				if(bigger(x,vecor(tree.query(k,(l+r)/2,m),x))){
					////cerr<<1;
					r=(l+r)/2;
				}else{
					////cerr<<0;
					l=(l+r)/2;
				}
				if(r-l<=1){
					break;
				}
			}
			////cerr<<endl;
			////cerr<<ans<<endl;
			if(bigger(x,vecor(tree.query(k,r,m),x))){
				//cerr<<k<<" "<<r<<"  ";
				ans++;
			}else{
				break;
			}
			k=r+1;
		}
		ans1=max(ans1,ans);
	}
	//cerr<<endl;
	cout<<ans1<<"\n";
}

int main(){
 	ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0); 
 	int t;
 	cin>>t;
 	while(t--){
 		solve();
 	}
 	return 0;
}