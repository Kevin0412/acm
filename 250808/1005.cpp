#include<bits/stdc++.h>
using namespace std;

void solve(){
	int i,j,n,m,k,x,y;
	cin>>n>>m>>k;
	vector<tuple<int,int,int>> tree;
	vector<pair<int,int>> shape={{0,0},{0,-1},{-2,-2},{-1,-2},{0,-2},{1,-2},{2,-2},{-1,-3},{0,-3},{1,-3},{0,-4}};
	for(i=1;i<=k;i++){
		cin>>x>>y;
		tree.push_back({x,y,i});
	}
	sort(tree.begin(),tree.end());
	int map[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			map[i][j]=0;
		}
	}
	for(auto a:tree){
		for(auto s:shape){
			x=get<0>(a)+s.second-1;
			y=get<1>(a)+s.first-1;
			if(x>=0 & x<n){
				if(y>=0 & y<m){
					map[x][y]=get<2>(a);
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(map[i][j]==0)cout<<".";
			else cout<<map[i][j];
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}