#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	int ai;
	for(int i=1;i<=n;i++){
		cin>>ai;
		a[i]=ai;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum%3==0){
		cout<<"1 2\n";
	}else{
		cout<<"0 0\n";
	}
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