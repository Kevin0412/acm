#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	cin>>a>>b;
	if(a==1){
		long long c[]={0,6,9,10,14};
		cout<<b/4*14+c[b%4]<<"\n";
		return 0;
	}
	if(b==1){
		long long c[]={0,6,8,9,14};
		cout<<a/4*14+c[a%4]<<"\n";
		return 0;
	}
	cout<<a*b*6LL<<"\n";
	return 0;
}