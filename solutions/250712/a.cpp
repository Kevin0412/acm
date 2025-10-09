#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long n,a,b;
	cin>>n>>a>>b;
	long long x=(n*b+1-a)/(2*b);
	if(x<0)x=0;
	if(x>n)x=n;
	long long ans=(n-x)*(a+b*x)+x;
	x++;
	if(x>n)x=n;
	ans=max(ans,(n-x)*(a+b*x)+x);
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}