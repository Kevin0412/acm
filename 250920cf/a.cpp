#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int x,y;
	cin>>x>>y;
	if(x<y){
		if(y>=2){
			cout<<"2\n";
		    return;
		}
	}else if(x-y>=2){
		if(y>=2){
			cout<<"3\n";
		    return;
		}
	}
	cout<<"-1\n";
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

