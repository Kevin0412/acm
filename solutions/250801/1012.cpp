#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005],b[100005];

void solve(){
    int i,n;
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    }
    for(i=0;i<n;i++){
    	cin>>b[i];
    }
    vector<ll> sum,minus;
    sum.clear();
    minus.clear();
    for(i=0;i<n;i++){
    	sum.push_back(a[i]+b[i]);
    	minus.push_back(a[i]-b[i]);
    }
    sort(sum.begin(),sum.end());
    sort(minus.begin(),minus.end());
    ll ans=2000000000012;
    for(i=0;i<n-1;i++){
    	ans=min(sum[i+1]-sum[i],ans);
    	ans=min(minus[i+1]-minus[i],ans);
    }
    cout<<ans<<endl;
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