#include<bits/stdc++.h>
#define int long long
using namespace std;

int mat[2][2];
int modn=2e10;

pair<int,int> trans(pair<int,int> a){
	return {
		mat[0][0]*a.first+mat[0][1]*a.second+modn,
		mat[1][0]*a.first+mat[1][1]*a.second
	};
}

void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x=0,y=0;
	vector<pair<int,int>> vis;
	for(int i=0;i<n;i++){
		vis.push_back({x,y});
		if(s[i]=='D'){
			y--;
		}else if(s[i]=='U'){
			y++;
		}else if(s[i]=='L'){
			x--;
		}else{
			x++;
		}
	}
	mat[0][0]=x;
	mat[0][1]=y;
	mat[1][0]=-y;
	mat[1][1]=x;
	if(x==0 & y==0){
		set<pair<int,int>> vis1;
		for(auto i:vis){
			vis1.insert(i);
		}
		int cnt=0;
		for(int i=0;i<m;i++){
			int l,r;
			cin>>l>>r;
			if(vis1.count({l,r})){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
		return;
	}
	map<pair<int,int>,int> mp;
	int mod=x*x+y*y;
	for(auto i:vis){
		auto b=trans(i);
		if(mp.count({b.first%mod,b.second})){
			mp[{b.first%mod,b.second}]=min(mp[{b.first%mod,b.second}],b.first);
		}else{
			mp[{b.first%mod,b.second}]=b.first;
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		auto b=trans({l,r});
		if(mp.count({b.first%mod,b.second})){
			if(mp[{b.first%mod,b.second}]<=b.first){
				cnt++;
			}
			//cerr<<l<<" "<<r<<"\n";
		}
	}
	cout<<cnt<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}