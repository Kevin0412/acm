#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,ans=0;
	cin>>t;
	char a[31];
	for(i=0;i<t;i++){
		cin>>a;
		if(a[0]=='M' & a[1]=='c'){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}