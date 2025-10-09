#include<bits/stdc++.h>
 
using namespace std;
 
int dp[200005];

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	dp[0]=0;
	for(int i=0;i<n;i++){
		dp[i+1]=dp[i];
		if(s[i]=='(')dp[i+1]++;
	}
	int ans=n;
	for(int i=0;i<=n;i++){
		ans=min(ans,dp[i]+(n-i-dp[n]+dp[i]));
	}
	cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}