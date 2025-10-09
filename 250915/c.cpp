#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll p = 998244353;  
  
long long int quik_power(ll base, ll power) {  
    base %= p;  
    long long int result = 1;  
    while (power > 0) {  
        if (power & 1) {  
            result = (result * base) % p;  // 分离出当前项并累乘后保存  
        }  
        power >>= 1;                       // 指数折半  
        base = (base * base) % p;         // 底数变其平方  
    }  
    return result;                       // 返回最终结果  
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0),b(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=2;i<=n;i++){
		if(!(a[i]>=a[i-1] & b[i]>=b[i-1])){
			int temp=a[i];
			a[i]=b[i];
			b[i]=temp;
			if(!(a[i]>=a[i-1] & b[i]>=b[i-1])){
				cout<<"0\n";
				return;
			}
		}
	}
	long long ans=1;
	for(int i=2;i<=n;i++){
		if((a[i]>=a[i-1] & b[i]>=b[i-1]) & (a[i]>=b[i-1] & b[i]>=a[i-1])){
			ans++;
		}
	}
	cout<<quik_power(2LL,ans)<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}