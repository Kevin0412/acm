#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll Exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = Exgcd(b, a % b, y, x);
	y -= a / b * x;
    return d;
}

typedef long long ll;//很可能long long也会爆，要开__int128
ll CRT(vector<ll> &r, vector<ll> &a) {
    ll n = 1, ans = 0, k = a.size();
    for (auto x : r) n = n * x;
    for (int i = 0; i < k; i++) {
        ll m = n / r[i], R, y;
        Exgcd(m, r[i], R, y);  // 见扩欧模版
        ans = (ans + a[i] * m * R % n) % n;
    }
    return (ans % n + n) % n;
}

int main(){
	int i,n;
	ll ai,bi;
	vector<ll> a,b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ai>>bi;
		a.push_back(ai);
		b.push_back(bi);
	}
	cout<<CRT(a,b)<<endl;
	return 0;
}