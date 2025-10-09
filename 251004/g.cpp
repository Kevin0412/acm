#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int depth;
	int deepest_id;
	int d;
	int dl;
	int dr;
	vector<int> children;
};

void solve(){
	int n;
	cin>>n;
	vector<node> a(n+1,{0,0,0,0,0,vector<int>(0)});
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		if(l!=0){
			a[i].children.push_back(l);
			a[l].children.push_back(i);
		}
		if(r!=0){
			a[i].children.push_back(r);
			a[r].children.push_back(i);
		}
	}
	int k=1;
	while(true){
		vector<pair<int,int>> dfs;
		vector<int> visited(n+1,0);
	    dfs.push_back(<k,0>);
	    while(!dfs.empty()){
	    	auto k=dfs.back();
	    	flag=1;
	    	for(auto i:a[k.first].children){
	    		if(!visited(i) & i!=k.second){
	    			flag=0;
	    		    dfs.push_back({i,k.first});
	    		}
	    	}
	    	if(flag){
	    		continue;
	    	}
	    	visited[k.first]=1;
	    	a[k.first].depth=0;
	    	a[k.first].deepest_id=k.first;
	    	a[k.first].d=1;
	    	a[k.first].dl=k.first;
	    	a[k.first].dr=k.first;
	    	for(auto i:a[k.first].children){
	    		if(a[k.first].depth<a[i].depth+1){
	    			a[k.first].depth=a[i].depth+1;
	    			a[k.first].deepest_id=a[i].deepest_id;
	    		}
	    		if(a[k.first].d<a[i].d){
	    			a[k.first].d=a[i].d;
	    			a[k.first].dl=a[i].dl;
	    			a[k.first].dr=a[i].dr;
	    		}
	    	}
	    	if(a[k.first].children.size==1){
	    		a[k.first].d=max(a[a[k.first].children[0]].depth+1,a[i].d);
	    	}else if(a[k.first].children.size==2){
	    		a[k.first].d=max(a[a[k.first].children[0]].depth+a[a[k.first].children[1]].depth+1,a[i].d);
	    	}else if(a[k.first].children.size==3){
	    		a[k.first].d=max(a[a[k.first].children[0]].depth+a[a[k.first].children[1]].depth+1,a[i].d);
	    		a[k.first].d=max(a[a[k.first].children[0]].depth+a[a[k.first].children[2]].depth+1,a[i].d);
	    		a[k.first].d=max(a[a[k.first].children[1]].depth+a[a[k.first].children[2]].depth+1,a[i].d);
	    	}
	    }
	}
	
}

signed main(){
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
