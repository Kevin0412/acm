#include<bits/stdc++.h>

using namespace std;

// 返回值：(a^b) % mod，保证 0 <= result < mod
long long qpow(long long a, long long b, long long mod) {
    long long res = 1 % mod;          // 处理 mod == 1 的边界
    a %= mod;                         // 防止 a >= mod
    for (; b; b >>= 1) {
        if (b & 1) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
    }
    return res;
}
int main(){
	long long a,b,c,p,l,r;
	cin>>a>>c>>p;
	l=1;
	b=1;
	while(1){
		l*=a;
		l%=p;
		r=qpow(b,c,p);
		if(l==r){
			cout<<b<<endl;
			return 0;
		}
		b++;
	}
}