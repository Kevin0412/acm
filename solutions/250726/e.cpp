#include<bits/stdc++.h>
 
using namespace std;
long long MOD=998244353;
long long pow3[65];
long long pow2[65];
 
void solve(){
	long long n;
	cin>>n;
	n++;
	int bit[64];
	for(int i=0;i<64;i++){
		bit[i]=n%2;
		n/=2;
	}
	long long ans=0;
	int k=0;
	for(int i=63;i>=0;i--){
		if(bit[i]==1){
			ans+=pow3[i]*pow2[k];
			k++;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
}
 
int main(){
    long long n=1;
    for(int i=0;i<65;i++){
    	pow3[i]=n;
    	n*=3;
    	n%=MOD;
    }
    n=1;
    for(int i=0;i<65;i++){
    	pow2[i]=n;
    	n*=2;
    	n%=MOD;
    }
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}