#include<bits/stdc++.h>

using namespace std;

const int MAXN=151;

int low[MAXN], dfn[MAXN], idx;
bool isbridge[MAXN];
vector<int> G[MAXN];
int cnt_bridge;
int father[MAXN];

void tarjan(int u, int fa){
	bool flag = false;
	father[u] = fa;
	low[u] = dfn[u] = ++idx;
	for (const auto &v : G[u]) {
	    if (!dfn[v]) {
		    tarjan(v, u);
		    low[u] = min(low[u], low[v]);
		    if (low[v] > dfn[u]) {
		        isbridge[v] = true;
		        ++cnt_bridge;
		    }
	    } else {
	    	if (v != fa || flag) low[u] = min(low[u], dfn[v]);
	      	else flag = true;
	    }
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b,i;
	for(i=0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	tarjan(1,0);
	vector<pair<int,int>> bridges;
	for(i=2;i<=n;i++){
		if(isbridge[i]){
			if(i>father[i]) bridges.push_back({father[i],i});
			else bridges.push_back({i,father[i]});
		}
	}
	sort(bridges.begin(),bridges.end(),[](pair<int,int> a,pair<int,int> b){
		if(a.first==b.first) return a.second<b.second;
		return a.first<b.first;
	});
	for(auto j:bridges){
		cout<<j.first<<" "<<j.second<<endl;
	}
	return 0;
}