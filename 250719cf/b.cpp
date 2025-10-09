#include<bits/stdc++.h>

using namespace std;
using ll=long long;

ll a[200005],b[200005],c[200005],d[200005];

void solve(){
	int i,n;
	ll ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	for(i=0;i<n;i++){
		ans+=abs(a[i]-c[i])+abs(d[i]-b[i]);
	}
	ans/=2;
	for(i=0;i<n;i++){
		if(b[i]>d[i]){
		    ans+=a[i];
		    if(a[i]>c[i]){
		    	ans-=a[i]-c[i];
		    }
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}