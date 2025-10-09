#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long t;
	cin>>n>>t;
	vector<long long> sum;
	sum.push_back(0);
	long long ai;
	for(int i=0;i<n;i++){
		cin>>ai;
		sum.push_back(sum[i]+ai);
	}
	long long r=t%sum[n];
	for(int i=0;i<=n;i++){
		if(r<sum[i]){
			cout<<i<<" "<<r-sum[i-1]<<" ";
			break;
		}
	}
	return 0;
}