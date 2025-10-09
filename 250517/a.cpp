#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,t,a[100],n,j,k;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>a[0];
		k=1;
		for(j=1;j<n;j++){
			cin>>a[j];
		}
		for(j=1;j<n;j++){
			if(a[j-1]==0 && a[j]==1){
				a[j]=2;
				k=1;
			}
			if(a[j-1]==0 && a[j]==0){
				k=0;
				break;
			}
			if(a[j-1]==1 && a[j]==0){
				k=1;
			}
			if(a[j-1]==1 && a[j]==1){
				k=0;
			}
			if(a[j-1]==2 && a[j]==0){
				k=1;
			}
			if(a[j-1]==2 && a[j]==1){
				k=1;
				a[j]=2;
			}
		}
		if(k)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}