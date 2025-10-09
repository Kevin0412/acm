#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,n,j,b[256],flag;
	char a[100001];
	cin>>t;
	for(i=0;i<t;i++){
		flag=1;
		cin>>n>>a;
		for(j=0;j<256;j++){
			b[j]=0;
		}
		b[a[0]]++;
		b[a[n-1]]++;
		for(j=1;j<n-1;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				flag=0;
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(flag)cout<<"No"<<endl;
	}
	return 0;
}