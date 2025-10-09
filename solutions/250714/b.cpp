#include<bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <vector>
using namespace std;

template<typename T>
class UnionFind {
private:
    unordered_map<T, T> parent;  // 父节点映射
    unordered_map<T, int> rank;   // 秩映射
    int count = 0;                // 连通分量计数

public:
    // 添加新元素
    void add(T x) {
        if (parent.count(x)) return;
        parent[x] = x;
        rank[x] = 0;
        count++;
    }

    // 带路径压缩的查找
    T find(T x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 按秩合并
    void unite(T x, T y) {
        T rx = find(x), ry = find(y);
        if (rx == ry) return;
        
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
        count--;
    }

    // 检查连通性
    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    // 连通分量数量
    int componentCount() const {
        return count;
    }
};

void solve(){
	int n;
	cin>>n;
	UnionFind<int> a;
	vector<pair<int,int>> b;
	int i,j,e;
	while(n--){
		cin>>i>>j>>e;
		a.add(i);
		a.add(j);
		if(e==1){
			a.unite(i,j);
		}else{
			b.push_back({i,j});
		}
	}
	for(auto c:b){
		if(a.connected(c.first,c.second)){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}