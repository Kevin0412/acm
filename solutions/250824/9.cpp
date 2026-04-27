#include<bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> a[200005];

struct dfs_node{
	int node;
	vector<int> visited_b;
};

void solve(){
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	for(int i=1;i<=n;i++){
		a[n].clear();
	}
	for(int i=0;i<m;i++){
		int u,v;
		int w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	int ci;
	vector<int> b[6];
	vector<int> visited_b(6,0);
	map<int,int> c,d;
	for(int i=1;i<=k;i++){
		cin>>ci;
		c[ci]=i;
		d[i]=ci;
		b[i].clear();
	}
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		b[c[y]].push_back(c[x]);
	}
	
	vector<int> visited(n+1,0);
	vector<long long> dist(n+1,-1);
	vector<dfs_node> e;
	e.push_back({1,visited_b});
	while(!e.empty()){
		auto f=e.back();
		e.pop_back();
		visited[f.node]=1;
		visited_b=f.visited_b;
		for(auto g:a[f.node]){
			int flag=0;
			for(int i=1;i<=k;i++){
				if(g.first==d[k]){
					flag=1;
					break;
				}
			}
			cerr<<g.first<<" "<<flag<<endl;
			if(flag){
				int flag1=0;
				for(auto h:b[c[g.first]]){
					if(!visited_b[g.first]){
						flag1=1;
						break;
					}
				}
				if(!flag){
					if(visited[g.first]){
						dist[g.first]=min(dist[f.node]+g.second,dist[g.first]);
					}else{
						visited_b[c[g.first]]=1;
						dist[g.first]=dist[f.node]+g.second;
					    e.push_back({g.first,visited_b});
					}
				}
			}else{
				if(visited[g.first]){
					dist[g.first]=min(dist[f.node]+g.second,dist[g.first]);
				}else{
					dist[g.first]=dist[f.node]+g.second;
				    e.push_back({g.first,visited_b});
				}
			}
		}
		cerr<<e.size()<<endl;
	}
	if(dist[n]==-1){
		cout<<"impossible\n";
	}else{
		cout<<dist[n]<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	while(t--)solve();
	
	return 0;
}