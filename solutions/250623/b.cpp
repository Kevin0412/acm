#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,j,n,a[1001],b,flag;
	cin>>t;
	for(i=0;i<t;i++){
		flag=1;
		cin>>n;
		for(j=0;j<n;j++){
			cin>>a[j];
		}
		if(a[0]-a[1]<-1){
			b=1;
		}else if(a[0]-a[1]>1){
			b=0;
		}else{
			cout<<0<<endl;
			continue;
		}
		for(j=1;j<n-1;j++){
			if(a[j]-a[j+1]<-1){
				if(!b){
					cout<<1<<endl;
					flag=0;
					break;
				}
			}else if(a[j]-a[j+1]>1){
				if(b){
					cout<<1<<endl;
					flag=0;
					break;
				}
			}else{
				cout<<0<<endl;
				flag=0;
				break;
			}
		}
		if(flag)cout<<-1<<endl;
	}
	return 0;
}