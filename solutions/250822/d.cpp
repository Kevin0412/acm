#include<bits/stdc++.h>
using namespace std;

long long dp[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,d;
	cin>>n>>k>>d;
	vector<long long> a;
	long long ai;
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
	}
	for(int i=0;i<102;i++){
		for(int j=0;j<102;j++){
			dp[i][j]=-1;
		}
	}
	for(int l=0;l<n;l++){
		int r=(int)(a[l]%(long long)d);
		for(int i=n-2;i>=0;i--){
			for(int j=0;j<d;j++){
				if(dp[i][j]>=0){
					dp[i+1][(j+r)%d]=max(dp[i+1][(j+r)%d],dp[i][j]+a[l]);
				}
			}
		}
		dp[0][r]=max(dp[0][r],a[l]);
		// for(int i=0;i<k;i++){
			// for(int j=0;j<d;j++){
				// cerr<<dp[i][j]<<" ";
			// }
			// cerr<<"\n";
		// }
		// cerr<<"\n";
	}
	cout<<dp[k-1][0]<<"\n";
	return 0;
}