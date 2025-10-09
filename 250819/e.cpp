#include<bits/stdc++.h>

using namespace std;

int dp[502],visited[502];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> a;
    int i,n,ai;
    cin>>n;
    for(i=0;i<n;i++){
    	cin>>ai;
    	a.push_back(ai);
    	dp[i]=-1;
    	visited[i]=0;
    }
    for(i=n-1;i>=0;i--){
    	if(dp[i]==-1){
    		int k=i;
    		for(int j=i-1;j>=0;j--){
    			if(a[j]==a[i]){
    				dp[j]=k;
    				k=j;
    			}
    		}
    	}
    }
    int ans=0;
    deque<int> b;
    b.clear();
    for(i=0;i<n;i++){
    	if(dp[i]!=-1 & !visited[i]){
    		visited[i]=1;
    		visited[dp[i]]=1;
    		if(b.size()==2){
    			if(b[0]>dp[i]){
    				b.push_front(dp[i]);
    				b.pop_back();
    			}else if(b[1]>dp[i]){
    				b.pop_back();
    				b.push_back(dp[i]);
    			}
    			//cerr<<b[0]<<" "<<b[1]<<endl;
    		}else if(b.size()==1){
    			if(b[0]>dp[i]){
    				b.push_front(dp[i]);
    			}else{
    				b.push_back(dp[i]);
    			}
    			//cerr<<b[0]<<" "<<b[1]<<endl;
    		}else{
    			b.push_back(dp[i]);
    			//cerr<<b[0]<<endl;
    		}
    	}
    	if(b.size()==2 & b[1]<=i){
    		ans++;
    		i=b[1];
    		//cerr<<i<<endl;
    		for(int j=b[1]+1;j<n;j++){
    			visited[j]=0;
    		}
    		b.clear();
    	}
    }
    cout<<ans<<"\n";
    return 0;
}