#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5+10;
bool is_prime[MAXN + 1];
vector<int> primes;

void euler_sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        // 用已得到的素数 primes[j] 去筛
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            // 关键：保证每个合数只被最小质因子筛掉
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    euler_sieve(MAXN);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    /*
    0: 1
    1: odd
    2: even
    3: remain
    */
    vector<vector<int>> dp(n,vector<int>(4,0x0d000721));
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[0][3]=0;
    if(a[0]==1){
        dp[0][0]=0;
    }
    // for(int j=0;j<4;j++){
    //     cout<<dp[0][j]<<" ";
    // }
    // cout<<"\n";
    for(int i=1;i<n;i++){
        //0
        if(is_prime[a[i-1]+1]){
            dp[i][0]=dp[i-1][3]+1;
        }
        dp[i][0]=min(dp[i][0],dp[i-1][2]+1);
        dp[i][0]=min(dp[i][0],dp[i-1][0]+1);
        if(a[i]==1){
            dp[i][0]--;
        }

        //1
        dp[i][1]=dp[i-1][2]+1;
        if(a[i-1]%2==0){
            dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
        }

        //2
        dp[i][2]=dp[i-1][1]+1;
        if(a[i-1]%2==1){
            dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
        }
        dp[i][2]=min(dp[i][2],dp[i-1][0]+1);

        //3
        if(a[i]%2==0){
            dp[i][3]=dp[i-1][1];
        }else{
            dp[i][3]=dp[i-1][2];
        }
        if(is_prime[a[i]+a[i-1]]){
            dp[i][3]=min(dp[i][3],dp[i-1][3]);
        }
        if(is_prime[a[i]+1]){
            dp[i][3]=min(dp[i][3],dp[i-1][0]);
        }
        // for(int j=0;j<4;j++){
        //     cout<<dp[i][j]<<" ";
        // }
        // cout<<"\n";
    }
    int ans=0x0d000721;
    for(int j=0;j<4;j++){
        ans=min(ans,dp[n-1][j]);
    }
    cout<<ans<<"\n";
    return 0;
}