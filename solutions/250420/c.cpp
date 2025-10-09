#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max0=a[0],max1=a[0];
	for(int i=1;i<n;i++){
		max0=max(a[i],max0+a[i]);
		max1=max(max1,max0);
	}
	cout<<max1<<endl;
	return 0;
}