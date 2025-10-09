#include<iostream>
#define ll long long
using namespace std;

int main(){
	ll n,m,s,i;
	cin>>n>>m>>s;
	ll w[n],v[n];
	for(i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	ll l[m],r[m];
	for(i=0;i<m;i++){
		cin>>l[i]>>r[i];
	}
	ll wmin=0,wmax=1000001,W,y=0,v1[n+1],v2[n+1];
	while(1){
		W=(wmin+wmax)/2;
		v1[0]=0;
		v2[0]=0;
		for(i=1;i<n+1;i++){
			v1[i]=v1[i-1];
			v2[i]=v2[i-1];
			if(w[i-1]>=W){
				v1[i]+=v[i-1];
				v2[i]+=1;
			}
		}
		y=0;
		for(i=0;i<m;i++){
			y+=(v1[r[i]]-v1[l[i]-1])*(v2[r[i]]-v2[l[i]-1]);
		}
		if(y>s){
			wmin=W;
		}else{
			wmax=W;
		}
		if(wmax-wmin==1){
			break;
		}
	}
	ll ans=0;
	v1[0]=0;
	v2[0]=0;
	for(i=1;i<n+1;i++){
		v1[i]=v1[i-1];
		v2[i]=v2[i-1];
		if(w[i-1]>=wmin){
			v1[i]+=v[i-1];
			v2[i]+=1;
		}
	}
	y=0;
	for(i=0;i<m;i++){
		y+=(v1[r[i]]-v1[l[i]-1])*(v2[r[i]]-v2[l[i]-1]);
	}
	ans=y-s;
	v1[0]=0;
	v2[0]=0;
	for(i=1;i<n+1;i++){
		v1[i]=v1[i-1];
		v2[i]=v2[i-1];
		if(w[i-1]>=wmax){
			v1[i]+=v[i-1];
			v2[i]+=1;
		}
	}
	y=0;
	for(i=0;i<m;i++){
		y+=(v1[r[i]]-v1[l[i]-1])*(v2[r[i]]-v2[l[i]-1]);
	}
	ans=min(ans,s-y);
	cout<<ans<<endl;
	return 0;
}