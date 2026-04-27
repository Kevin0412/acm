#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		cout<<(m-(n+1)/2)*2+1<<"\n";
	}
	return 0;
}