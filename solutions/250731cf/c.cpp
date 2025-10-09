#include<bits/stdc++.h>

using namespace std;

vector<int> a[6003];
int visited[6003];

void solve(){
    int i,n,u,v;
    vector<pair<int,int>> s;
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>u>>v;
    	s.push_back({u,v});
    }
    for(i=1;i<=2*n;i++){
    	a[i].clear();
    	visited[i]=0;
    }
    for(auto k:s){
    	a[k.first].push_back(k.second);
    	a[k.second].push_back(k.first);
    }
    vector<pair<int,int>> dfs;
    set<pair<int,int>> del;
    int temp=0;
    while(true){
    	int flag=1;
    	for(i=temp;i<=2*n;i++){
	    	if(!a[i].empty()){
	    		if(!visited[i]){
	    			flag=0;
	    			break;
	    		}
	    	}
	    }
	    temp=i;
	    if(flag){
	    	break;
	    }
	    for(auto k:a[i]){
	    	dfs.push_back({i,k});
	    }
	    visited[i]=1;
	    int fa,m;
	    while(!dfs.empty()){
	    	fa=dfs[dfs.size()-1].first;
	    	m=dfs[dfs.size()-1].second;
	    	dfs.pop_back();
	    	if(fa>m){
				auto it = del.find({m,fa});
				if (it != del.end()) continue;
			}else{
				auto it = del.find({fa,m});
				if (it != del.end()) continue;
			}
	    	//cerr<<fa<<" "<<m<<endl;
	    	for(auto k:a[m]){
	    		if(k!=fa){
	    			if(visited[k]==1){
	    				//cerr<<"d "<<m<<" "<<k<<" "<<fa<<endl;
	    				if(k>m){
	    					del.insert({m,k});
	    				}else{
	    					del.insert({k,m});
	    				}
	    			}else{
	    				dfs.push_back({m,k});
	    				////cerr<<m<<" "<<k<<" "<<visited[k]<<"  ";
	    			}
	    		}
	    	}
	    	////cerr<<endl;;
	    	////cerr<<dfs.size()<<endl;
	    	visited[m]=1;
	    }
    }
    cout<<n-del.size()<<endl;
    for(int i=0;i<n;i++){
    	auto it = del.find(s[i]);
	    if (it == del.end()) {
	        cout<< i+1<<" ";
	    }
    }
    cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}