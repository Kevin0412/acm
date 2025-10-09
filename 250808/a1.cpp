#include<bits/stdc++.h>
using namespace std;

typedef __int128 ll;
ll Exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = Exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll CRT(vector<ll> &r, vector<ll> &a) {
    ll n = 1, ans = 0;
    int k = r.size();
    for (auto x : r) n = n * x;
    for (int i = 0; i < k; i++) {
        ll m = n / r[i], R, y;
        Exgcd(m, r[i], R, y);
        ans = (ans + a[i] * m * R % n) % n;
    }
    return (ans % n + n) % n;
}

void print(ll x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x) {
        s += char('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a, b;
    for (int i = 0; i < n; i++) {
        long long ai, bi; // 用 long long 读取输入
        cin >> ai >> bi;
        a.push_back(ai);
        b.push_back(bi);
    }
    ll result = CRT(a, b);
    print(result);
    cout << endl;
    return 0;
}