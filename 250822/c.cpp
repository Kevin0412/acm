#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	vector<long long> p,sum;
	long long pi;
	for(int i=0;i<n;i++){
		cin>>pi;
		p.push_back(pi);
	}
	sort(p.begin(),p.end());
	sum.push_back(0);
	for(int i=0;i<n;i++){
		sum.push_back(sum[i]+p[i]);
		//cerr<<sum[i]<<" ";
	}
	//cerr<<sum[n]<<endl;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		//cerr<<n-x+y<<" "<<n-x<<endl;
		cout<<sum[n-x+y]-sum[n-x]<<"\n";
	}
	return 0;
}