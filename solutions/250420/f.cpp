#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,m;
	cin>>n>>m;
	ll p[m],a[n-1],b[n-1],c[n-1],d[n],e[n-1];
	for(ll i=0;i<n-1;i++){
		d[i]=0;
	}
	for(ll i=0;i<m;i++){
		cin>>p[i];
	}
	for(ll i=0;i<n-1;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(ll i=0;i<m-1;i++){
		if(p[i]<p[i+1]){
			d[p[i]-1]++;
			d[p[i+1]-1]--;
		}else{
			d[p[i]-1]--;
			d[p[i+1]-1]++;
		}
	}
	e[0]=d[0];
	for(ll i=1;i<n-1;i++){
		e[i]=e[i-1]+d[i];
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		//cerr<<e[i]<<" ";
		ans+=min(a[i]*e[i],b[i]*e[i]+c[i]);
	}
	printf("%lld",ans);
	return 0;
}