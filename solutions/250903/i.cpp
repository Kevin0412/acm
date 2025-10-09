#include<bits/stdc++.h>

using namespace std;

long long MOD=998244353LL;

// 迭代法 (推荐)
long long fast_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod; // 先取模，防止base过大
    while (exp) {
        if (exp & 1) { // 如果当前二进制位为1
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // base平方
        exp >>= 1; // exp右移一位
    }
    return result;
}

void solve(){
	vector<long long> a(10);
	for(int i=0;i<9;i++){
		cin>>a[i];
	}
	long long ans=1;
	if(a[0]>=a[1]){
		a[0]-=a[1];
		a[2]+=a[1];
		a[1]=0;
	}else{
		a[1]-=a[0];
		a[2]+=a[0];
		a[0]=0;
	}
	a[2]+=a[0]/3;
	a[0]%=3;
	if(a[0]==1){
		for(int i=2;i<=8;i++){
			if(a[i]!=0){
				a[i]--;
				a[i+1]++;
				break;
			}
		}
		a[0]=0;
	}
	if(a[0]==2){
		a[0]=0;
		a[1]++;
	}
	for(int i=0;i<10;i++){
		ans*=fast_pow(i+1,a[i],MOD);
		ans%=MOD;
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}