#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		ll i=1;
		while(a/i!=b/i){
			i*=2;
		}
		cout<<a%i<<"\n";
	}
}