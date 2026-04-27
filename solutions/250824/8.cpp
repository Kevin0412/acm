#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000006;
long long fact[MAXN+1], inv_fact[MAXN+1];
const int mod=998244353;

long long fast_pow(long long base,long long exp,long long mod){
	long long result=1;
	base%=mod;
	while(exp){
		if(exp&1){
			result=(result*base)%mod;
		}
		base=(base*base)%mod;
		exp>>=1;
	}
	return result;
}

void init_comb_adv() {
	fact[0]=inv_fact[0]=1;
	
	for(int i=1;i<= MAXN;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	inv_fact[MAXN]=fast_pow(fact[MAXN],mod-2,mod);
	for(int i=MAXN-1;i>=0;i--){
		inv_fact[i]=inv_fact[i+1]*(i+1)%mod;
	}
}

long long comb(int n,int m){
	if(m<0 || m>n) return 0;
	return fact[n]*inv_fact[m]%mod*inv_fact[n-m]%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init_comb_adv();
	
    int n,m;
    cin>>n>>m;
    
    int a=0,b=0;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
    	if(s[i]=='A')a++;
    	else if(s[i]=='B')b++;
    }
    
    vector<long long> bs(b+1,1);
    
    //cerr<<bs[0]<<" ";
    for(int i=0;i<b;i++){
    	bs[i+1]=(bs[i]+comb(b,i+1))%mod;
    	//cerr<<bs[i+1]<<" ";
    }
    //cerr<<endl;
    
    long long ans=0;
    for(int i=0;i<=a;i++){
    	if(i>m){
    		break;
    	}
    	//cerr<<comb(a,i)<<" "<<fast_pow(2,i,mod)<<" "<<i<<" "<<bs[min(b,m-i)]<<endl;
    	ans+=((bs[min(b,m-i)]*comb(a,i))%mod*fast_pow(2,i,mod))%mod;
    	ans%=mod;
    }
	
	cout<<ans<<"\n";
	
	return 0;
}