#include<bits/stdc++.h>

using namespace std;
int dp[3000001];

int main(){
	int n,i,x,y,j=0;
	cin>>n;
	vector<pair<int,int>> a;
	for(i=0;i<3000001;i++)dp[i]=0;
	for(i=0;i<n;i++){
		cin>>x>>y;
		a.push_back({x,y});
	}
	sort(a.begin(),a.end(),[](const auto& c,const auto& b){
		return c.second < b.second;
	});
	pair<int,int> p=a[0];
	for(i=1;i<3000001;i++){
		dp[i]=dp[i-1];
		while(p.second==i){
			dp[i]=max(dp[p.first-1]+p.second-p.first+1,dp[i]);
			j++;
			p=a[j];
		}
		//cerr<<dp[i]<<endl;
	}
	cout<<dp[3000000]<<endl;
	return 0;
}