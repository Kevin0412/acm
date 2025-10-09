#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,j,n,a,p,l,r;
	cin>>t;
	for(i=0;i<t;i++){
		a=1;
		cin>>n;
	    l=1;
	    r=2;
		for(j=1;j<=n;j++){
			cin>>p;
			if(a){
				if(j==r){
					l*=2;
					r*=2;
					if(r>n)r=n+1;
				}
				if(!(p>=l & p<r))a=0;
			}
		}
		if(a)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}