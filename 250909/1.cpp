#include<bits/stdc++.h>

using namespace std;

struct node{
	vector<int> son;
	int father;
	int w;
};

int main(){
	int n;
	cin>>n;
	vector<node> a(n+1,{vector<int>(),0,0});
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].son.push_back(v);
		a[v].son.push_back(u);
	}
	vector<int> dfs;
	dfs.push_back(1);
	while(!dfs.empty()){
		int k=dfs.back(),flag=0;
		for(auto i:a[k].son){
			if(i!=a[k].father){
				a[i].father=k;
				if(a[i].w==0){
					flag=1;
					dfs.push_back(i);
				}
			}
		}
		if(flag){
			continue;
		}
		dfs.pop_back();
		for(auto i:a[k].son){
			if(i!=a[k].father){
				a[k].w+=a[i].w;
			}
		}
		a[k].w++;
	}
	int min_w=n+1,ans=0;
	for(int i=1;i<=n;i++){
		int max_w=0;
		for(auto j:a[i].son){
			if(j!=a[i].father){
				max_w=max(max_w,a[j].w);
			}else{
				max_w=max(max_w,n-a[i].w);
			}
		}
		cerr<<i<<" "<<max_w<<"\n";
		if(max_w<min_w){
			min_w=max_w;
			ans=i;
		}
	}
	cout<<ans<<" "<<min_w<<"\n";
	return 0;
}