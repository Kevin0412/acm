#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i] % b[j] != 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	if (n == 1) {
		if (m == 1) {
			if (a[0] == b[0]) {
				cout << "YES" << endl;
				cout << a[0];
				return 0;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
			ll lcmb=lcm(b[0],b[1]);
			for(int i=2;i<m;++i){
				lcmb=lcm(lcmb,b[i]);
			}
			if(lcmb==a[0]){
				cout << "YES" << endl;
				for (int i = 0; i < m; ++i) {
					cout << b[i];
					cout << " ";
				}
				cout << endl;
				return 0;
			}
			cout << "NO" << endl;
			return 0;
		}
	}

	else if (m == 1) {
		ll gcda=gcd(a[0],a[1]);
		for(int i=2;i<n;++i){
			gcda=gcd(gcda,a[i]);
		}
		if(gcda==b[0]){
			cout << "YES" << endl;
			for (int i = 0; i < n; ++i) {
				cout << a[i];
	            cout << endl;
			}
			return 0;
		}
		cout << "NO" << endl;
	    return 0;
	}

	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == j % n){
					cout << b[j];;
				} 
				else{
					cout << a[i];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
    
    return 0;
}
