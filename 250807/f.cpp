#include<bits/stdc++.h>

using namespace std;

int b[1003][1003];

void solve(){
	int i,j,n,m;
	vector<string> a;
	string s;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s;
		a.push_back(s);
		for(j=0;j<m;j++){
			b[i][j]=-1;
		}
	}
	vector<pair<int,int>> dfs;
	dfs.push_back({0,0});
	queue<pair<int,int>> bfs;
	while(!dfs.empty()){
		pair<int,int> c=dfs[dfs.size()-1];
		bfs.push(c);
		int x=c.first,y=c.second;
		dfs.pop_back();
		b[x][y]=0;
		if(x>0){
			if(a[x-1][y]=='.' & b[x-1][y]==-1){
				dfs.push_back({x-1,y});
			}
		}
		if(x<n-1){
			if(a[x+1][y]=='.' & b[x+1][y]==-1){
				dfs.push_back({x+1,y});
			}
		}
		if(y>0){
			if(a[x][y-1]=='.' & b[x][y-1]==-1){
				dfs.push_back({x,y-1});
			}
		}
		if(y<m-1){
			if(a[x][y+1]=='.' & b[x][y+1]==-1){
				dfs.push_back({x,y+1});
			}
		}
	}
	if(b[n-1][m-1]==0){
		cout<<0<<endl;
		return;
	}
	dfs.push_back({n-1,m-1});
	while(!dfs.empty()){
		pair<int,int> c=dfs[dfs.size()-1];
		dfs.pop_back();
		int x=c.first,y=c.second;
		b[x][y]=-2;
		if(x>0){
			if(a[x-1][y]=='.' & b[x-1][y]==-1){
				dfs.push_back({x-1,y});
			}
		}
		if(x<n-1){
			if(a[x+1][y]=='.' & b[x+1][y]==-1){
				dfs.push_back({x+1,y});
			}
		}
		if(y>0){
			if(a[x][y-1]=='.' & b[x][y-1]==-1){
				dfs.push_back({x,y-1});
			}
		}
		if(y<m-1){
			if(a[x][y+1]=='.' & b[x][y+1]==-1){
				dfs.push_back({x,y+1});
			}
		}
	}
	while(!bfs.empty()){
		pair<int,int> c=bfs.front();
		bfs.pop();
		int x=c.first,y=c.second;
		if(x>0){
			if(b[x-1][y]==-1){
				b[x-1][y]=b[x][y]+1;
				bfs.push({x-1,y});
			}else if(b[x-1][y]==-2){
				cout<<b[x][y]<<endl;
				return;
			}
		}
		if(x<n-1){
			if(b[x+1][y]==-1){
				b[x+1][y]=b[x][y]+1;
				bfs.push({x+1,y});
			}else if(b[x+1][y]==-2){
				cout<<b[x][y]<<endl;
				return;
			}
		}
		if(y>0){
			if(b[x][y-1]==-1){
				b[x][y-1]=b[x][y]+1;
			    bfs.push({x,y-1});
			}else if(b[x][y-1]==-2){
				cout<<b[x][y]<<endl;
				return;
			}
		}
		if(y<m-1){
			if(b[x][y+1]==-1){
				b[x][y+1]=b[x][y]+1;
				bfs.push({x,y+1});
			}else if(b[x][y+1]==-2){
				cout<<b[x][y]<<endl;
				return;
			}
		}
	}
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