#include<bits/stdc++.h>

using namespace std;

long long fastPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int a[200001][30];

int main(){
	int i,t,j,m,n,b,k;
	long long ans,c;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m;
		ans=0;
		for(j=0;j<n;j++){
			cin>>b;
			for(k=0;k<m;k++){
				a[j][k]=b%2;
				b/=2;
			}
		}
		c=0;
		for(k=0;k<m;k++){
			if(a[1][k]==1){
				c++;
			}
		}
		ans+=fastPow(2,c)-1;
		for(j=1;j<n-1;j++){
			c=0;
			for(k=0;k<m;k++){
				if(a[j-1][k]==1 & a[j+1][k]==1){
					c++;
				}
			}
			ans+=fastPow(2,c)-1;
		}
		c=0;
		for(k=0;k<m;k++){
			if(a[n-2][k]==1){
				c++;
			}
		}
		ans+=fastPow(2,c)-1;
		cout<<ans<<endl;
	}
	return 0;
}