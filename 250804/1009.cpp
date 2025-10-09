#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

// 快读模板
template <typename T>
void read(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

ll a[200005];

void solve(){
	int i,n;
	read(n);
	for(i=0;i<n;i++){
		read(a[i]);
	}
	ll maxa=0;
	for(i=0;i<n;i++){
		maxa=max(a[i],maxa);
	}
	if(n<3){
		cout<<0<<endl;
	}else cout<<maxa*ll(n-3)+max(a[0],a[n-1])<<endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0); 
    int t;
    read(t);
    while(t--)solve();
    return 0;
}