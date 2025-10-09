#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	vector<int> odd(n+1,0),even(n,0);
	for(int i=0;i<n;i++){
		odd[i+1]=odd[i]+a[2*i+1]-a[2*i];
	}
	for(int i=0;i<n-1;i++){
		even[i+1]=even[i]+a[2*i+2]-a[2*i+1];
	}
	int ans=odd[n];
	cout<<ans<<" ";
	for(int i=2;i<=n;i++){
		if(i%2==1){
			ans+=(odd[n-i/2]-odd[i/2])*2;
			//cerr<<odd[n-i/2]-odd[i/2]<<" ";
		}else{
			ans+=(even[n-i/2]-even[i/2-1])*2;
			//cerr<<even[n-i/2]-even[i/2-1]<<" ";
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	cerr<<"\n";
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