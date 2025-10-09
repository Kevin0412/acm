#include<bits/stdc++.h>

using namespace std;

long long a[210];

long long f(long long x){
	return a[209]*(x/210)+a[x%210]-1;
}

void solve(){
    long long l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1)<<endl;
}

int main(){
	long long b=0;
	for(int i=0;i<210;i++){
		if(i%2!=0 & i%3!=0 & i%5!=0 & i%7!=0)b++;
		a[i]=b;
		//cerr<<i<<" "<<a[i]<<endl;
	}
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}