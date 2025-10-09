#include<bits/stdc++.h>

using namespace std;

struct node{
	long long w;
	int maxn;
	int minn;
	int max_min;
	int maxi;
	int mini;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<node> a(n+1);
    for(int i=1;i<=n;i++){
    	cin>>a[i].w;
    	a[i].maxn=a[i].w;
    	a[i].minn=a[i].w;
    	a[i].max_min=0;
    	a[i].maxi=0;
    	a[i].mini=0;
    }
    vector<vector<int>> b(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
    	int u,v;
    	cin>>u>>v;
    	b[u].push_back(v);
    	b[v].push_back(u);
    }
    long long ans=0;
    vector<pair<int,int>> dfs;
    dfs.push_back({1,0});
    vector<int> visited(n+1,0);
    while(!dfs.empty()){
    	auto c=dfs.back();
    	//cout<<c.first<<endl;
    	int flag=0;
    	for(auto i:b[c.first]){
    		if(i!=c.second){
    			if(!visited[i]){
    				dfs.push_back({i,c.first});
    				flag=1;
    			}
    		}
    	}
    	if(flag){
    		continue;
    	}
    	dfs.pop_back();
    	visited[c.first]=1;
    	vector<node> maxs;
    	vector<int> maxs_idx;
    	vector<node> mins;
    	vector<int> mins_idx;
    	for(auto i:b[c.first]){
    		if(i!=c.second){
    			if(a[c.first].w<=a[i].maxn & a[c.first].w>=a[i].minn){
    				ans+=a[i].maxn-a[i].minn;
    			}else{
    				if(a[c.first].w<a[i].minn){
    					maxs.push_back(a[i]);
    					maxs_idx.push_back(i);
    				}else{
    					mins.push_back(a[i]);
    					mins_idx.push_back(i);
    				}
    			}
    		}
    	}
    	if(mins.empty() & maxs.empty()){
    		//cerr<<c.first<<" "<<ans<<" "<<a[c.first].maxn<<" "<<a[c.first].minn<<" "<<a[c.first].max_min<<" "<<a[c.first].maxi<<" "<<a[c.first].mini<<"\n";
    		continue;
    	}
    	node maxi;
    	int maxi_idx=0;
    	node mini;
    	int mini_idx=0;
    	if(!mins.empty()){
    		mini=mins[0];
    		mini_idx=mins_idx[0];
    		for(int i=1;i<mins.size();i++){
    			if(mins[i].maxn+mins[i].maxi<mini.maxn+mini.maxi){
    				mini=mins[i];
    				mini_idx=mins_idx[i];
    			}
    		}
    		for(int i=0;i<mins.size();i++){
				if(mins_idx[i]!=mini_idx){
					ans+=mins[i].maxn-mins[i].minn;
				}
			}
			a[c.first].mini=mini.maxn-mini.minn;
    	}
    	if(!maxs.empty()){
    		maxi=maxs[0];
    		maxi_idx=maxs_idx[0];
    		for(int i=1;i<maxs.size();i++){
    			if(maxs[i].minn+maxs[i].mini>maxi.minn+maxi.mini){
    				maxi=maxs[i];
    				maxi_idx=maxs_idx[i];
    			}
    		}
    		for(int i=0;i<maxs.size();i++){
				if(maxs_idx[i]!=maxi_idx){
					ans+=maxs[i].maxn-maxs[i].minn;
				}
			}
			a[c.first].maxi=maxi.maxn-maxi.minn;
    	}
    	if((!mins.empty()) & (!maxs.empty())){
    		a[c.first].maxn=maxi.maxn;
			a[c.first].minn=mini.minn;
    	}else if(mins.empty()){
    		a[c.first].max_min=1;
    		a[c.first].maxn=maxi.maxn;
    		//cerr<<maxi.max_min<<" "<<maxi_idx<<" "<<maxi.maxi<<" "<<maxi.mini<<"\n";
    		if(maxi.max_min*a[c.first].max_min==-1){
    			ans+=maxi.mini;
    		}
    	}else if(maxs.empty()){
    		a[c.first].max_min=-1;
    		a[c.first].minn=mini.minn;
    		//cerr<<mini.max_min<<" "<<mini_idx<<" "<<mini.maxi<<" "<<mini.mini<<"\n";
    		if(mini.max_min*a[c.first].max_min==-1){
    			ans+=mini.maxi;
    		}
    	}
    	//cerr<<c.first<<" "<<ans<<" "<<a[c.first].maxn<<" "<<a[c.first].minn<<" "<<a[c.first].max_min<<" "<<a[c.first].maxi<<" "<<a[c.first].mini<<"\n";
    }
    ans+=a[1].maxn-a[1].minn;
    cout<<ans<<"\n";
    return 0;
}