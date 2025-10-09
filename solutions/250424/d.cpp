#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		int a[n],b[m];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		int ai=0,bi=0,out=0,c[n],d[n];
		for(int j=0;j<n;j++){
			c[j]=n;
			d[j]=-1;
		}
		while(1){
			if(a[ai]>=b[bi]){
				bi++;
			}
			if(bi>=m){
				for(;ai<n;ai++){
					c[ai]=bi;
				}
				break;
			}
			c[ai]=bi;
			ai++;
			if(ai>=n){
				break;
			}
		}
		ai=n-1;
		bi=m-1;
		while(1){
			if(a[ai]>=b[bi]){
				bi--;
			}
			if(bi<0){
				for(;ai>=0;ai--){
					c[ai]=bi;
				}
				break;
			}
			d[ai]=bi;
			ai--;
			if(ai<0){
				break;
			}
		}
		out=-1;
		for(int j=0;j<n;j++){
			cerr<<j<<" "<<c[j]<<" "<<d[j]<<" "<<out<<endl;
			if(d[j]-c[j]<0){
				out=0;
			}else if(d[j]-c[j]==0){
				if(out!=0){
					out=b[d[j]];
				}
			}
		}
		cout<<out<<endl;
	}
	return 0;
}