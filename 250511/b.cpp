#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,t;
	cin>>t;
	int n,a[100001],j,k;
	for(i=0;i<t;i++){
		cin>>n;
		k=0;
		for(j=0;j<n;j++){
			cin>>a[j];
			if(j!=0)
			if(a[j]<abs(a[0])&&a[j]>-abs(a[0]))k++;
		}
		cerr<<k<<endl;
		if(k<=n/2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}