#include<bits/stdc++.h>

using namespace std;

struct node{
	int mark;
	int father;
	vector<int> son;
	unordered_map<int,int> edge;
};

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<node> a(n+1,{-1,0,vector<int>(0),unordered_map<int,int>()});
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int c;
			cin>>c;
			a[i].son.push_back(c);
			a[i].edge[c]=0;
			a[c].father=i;
		}
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		a[u].edge[v]=1;
	}
	for(int i=0;i<k;i++){
		int t;
		cin>>t;
		a[t].mark=0;
	}
	vector<int> dfs;
	vector<int> visited(n+1,0);
	dfs.push_back(1);
	while(!dfs.empty()){
		int b=dfs.back();
		for(auto i:a[b].son){
			if(!visited[i]){
				dfs.push_back(i);
			}
		}
		if(b!=dfs.back()){
			continue;
		}
		dfs.pop_back();
		visited[b]=1;
		if(a[b].son.size()==1){
			a[b].mark=a[a[b].son[0]].mark;
		}else if(a[b].son.size()!=0){
			a[b].mark=0;
			for(auto i:a[b].son){
				if(a[i].mark>=0){
					a[b].mark+=a[i].mark;
				}else{
					a[b].mark=-1;
					break;
				}
			}
			for(auto i:a[b].son){
				if(a[b].edge[i]){
					if(a[i].mark>=0){
						if(a[b].mark==-1){
							a[b].mark=a[i].mark+1;
						}else{
							a[b].mark=min(a[i].mark+1,a[b].mark);
						}
					}
				}
			}
		}
		//cerr<<b<<" "<<a[b].mark<<"\n";
	}
	cout<<a[1].mark<<"\n";
	//cerr<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}