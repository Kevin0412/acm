#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long c,a,b,k;
    cin>>a>>b>>k;
    c=gcd(a,b);
    a/=c;
    b/=c;
    if(a<=k & b<=k)cout<<1<<endl;
    else cout<<2<<endl;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}