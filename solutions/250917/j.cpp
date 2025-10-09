#include<bits/stdc++.h>

using namespace std;

vector<long long> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,53,59,61,67,71,73,79,83,89,97};

bool isprime(long long n){
	if(n<4){
		return true;
	}
	for(auto p:primes){
		if(p*p>n)break;
		if(n%p==0){
			return false;
		}
	}
	return true;
}

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(!isprime(a[i])){
			cout<<"0\n";
			return;
		}
	}
	vector<long long> b(n,0);
	for(int i=0;i<n-1;i++){
		b[i]=a[i]+a[i+1];
		if(!isprime(b[i])){
			cout<<"1\n";
			return;
		}
	}
	for(int i=0;i<n-2;i++){
		b[i]+=a[i+2];
		if(!isprime(b[i])){
			cout<<"2\n";
			return;
		}
	}
	for(int i=0;i<n-3;i++){
		b[i]+=a[i+3];
		if(!isprime(b[i])){
			cout<<"3\n";
			return;
		}
	}
	cout<<"-1\n";
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