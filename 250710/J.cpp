#include<bits/stdc++.h>

using namespace std;

int four_based(long n){
	while(n>1){
		if(n%4!=0)return 0;
		n/=4;
	}
	return 1;
}

void solve(){
	 long n,k=1;
	 cin>>n;
	 int m=0;
	 vector<long> a;
	 while(!four_based(n)){
	 	if(n%(k*2)!=0){
	 		n+=k;
	 		a.push_back(k);
	 		m++;
	 	}
	 	k*=2;
	 }
	 cout<<m<<endl;
	 for(auto i:a){
	 	cout<<i<<" ";
	 }
	 cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}