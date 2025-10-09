#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200000;
int fact[MAXN + 1], inv_fact[MAXN + 1]; // 阶乘 和 阶乘的逆元
const int mod = 998244353;

int fast_pow(int base, int exp, int mod) {
    int result = 1;
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

void init_comb_adv() {
    fact[0] = inv_fact[0] = 1;
    // 预处理阶乘
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    // 预处理阶乘的逆元 (利用费马小定理)
    inv_fact[MAXN] = fast_pow(fact[MAXN], mod - 2, mod);
    // 逆推，利用 inv_fact[i] = inv_fact[i+1] * (i+1) % mod
    for (int i = MAXN - 1; i >= 1; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}

int comb(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fact[n] * inv_fact[m] % mod * inv_fact[n - m] % mod;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	if(sum!=n){
		cout<<"0\n";
		return;
	}
	//cerr<<"a\n";
	for(int i=(n+1)/2;i<n;i++){
		if(a[i]!=0){
			cout<<"0\n";
			return;
		}
	}
	//cerr<<"b\n";
	int ans=1,u=0,k=n-((n-1)/2)*2;
	for(int i=(n-1)/2;i>=0;i--){
		//cerr<<k<<"\n";
		if(a[i]>k){
			//cerr<<"c\n";
			cout<<"0\n";
			return;
		}else{
			//cerr<<k-u<<" "<<a[i]<<" "<<comb(k-u,a[i])<<"\n";
			ans*=comb(k-u,a[i]);
			ans%=mod;
			u+=a[i];
			k+=2;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init_comb_adv();
	
	int t;
	cin>>t;
	while(t--){
		//cerr<<t<<":\n";
		solve();
	}
	return 0;
}