#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int a[n],b[n],m=0,maxa=0,mina=k;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
			if(b[j]==-1){
				m++;
			}
		}
		if(m==n){
			for(int j=0;j<n;j++){
				maxa=max(maxa,a[j]);
				mina=min(mina,a[j]);
			}
			if(maxa>k){
				cout<<0<<endl;
			}else{
				cout<<k-maxa+1+mina<<endl;
			}
		}else{
			int sum=-1;
			int flag=1;
			for(int j=0;j<n;j++){
				if(b[j]!=-1){
					if(sum==-1){
						sum=a[j]+b[j];
					}else{
						if(sum!=a[j]+b[j]){
							cout<<0<<endl;
							flag=0;
							break;
						}
					}
				}
			}
			if(flag){
				int flag1=1;
				for(int j=0;j<n;j++){
					b[j]=sum-a[j];
					if(b[j]>k || b[j]<0){
						cout<<0<<endl;
						flag1=0;
						break;
					}
				}
				if(flag1)cout<<1<<endl;
			}
		}
		
	}
	return 0;
}