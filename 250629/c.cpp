#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,n,a[1001],temp=-1,tempa;
	cin>>n;
	cin>>a[0];
	for(i=1;i<n;i++){
		cin>>a[i];
		if(temp==-1){
			if(a[i]<a[i-1]){
				temp=i-1;
			}
		}else if(temp>=0 & a[i]<a[i-1]){
			tempa=a[i];
			a[i]=a[temp];
			a[temp]=tempa;
			temp==-2;
		}
	}
	for(i=1;i<n;i++){
		if(a[i]<a[i-1]){
			cout<<"Failed"<<endl;
			return 0;
		}
	}
	cout<<"Sorted"<<endl;
	return 0;
}